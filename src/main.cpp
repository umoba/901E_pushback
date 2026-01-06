#include "main.h"
#include "globals.h"// IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
using namespace Robot;
using namespace Robot::Globals;
#include "lemlib/api.hpp" // IWYU pragma: keep
ASSET(ringTest_txt); // '.' replaced with "_" to make c++ happy


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
  pros::lcd::initialize();
  chassis.calibrate();
  pros::Task screenTask([&]() {
    while (true) {
      subsystem.intake.stopTOP();

      autonSystem.auton.autonSelection();
        
      // print robot location to the brain screen
      pros::lcd::print(0, "X: %f", chassis.getPose().x);
      pros::lcd::print(1, "Y: %f", chassis.getPose().y);
      pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
      

      // lines 1-3 reserved for auton selection



      // log position telemetry
      lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
      // delay to save resources
      pros::delay(50);
      
    }
  });

}   

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {
}



void autonomous() {
  autonSystem.auton.runSelectedAuton(autonSystem.auton.autonRoute);
}

/**
 * Runs in driver control
 */
void opcontrol() {
  while (true) {
    // run the subsystems
    subsystem.intake.run();
    subsystem.tongue.run();

    // Tank Drive
    int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
    int turn = master.get_analog(ANALOG_RIGHT_Y);  // Gets the turn left/right from right joystick
    left.move(-dir);                      // Sets left motor voltage
    right.move(-turn); 

  
  
    // WING CONTROL
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
      wing.toggle();   // Y pressed → extend
  }

  // Delay to save resources
  pros::delay(50);
  }

}

