#include "main.h"
#include "globals.h"// IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "config.hpp"
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
bool whileAuton = true;
void initialize() {
  pros::lcd::initialize();
  chassis.calibrate();
  Config::prematches.allianceIsRed = true;
  pros::Task screenTask([&]() {
    while (true) {
      if ( !whileAuton) {
      subsystem.intake.stopTOP();
      }
      // subsystem.intake.color_sort();
      // autonSystem.auton.autonSelection();
        
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

// autonSystem.auton.runSelectedAuton(autonSystem.auton.autonRoute);

void autonomous() {
  // setting pose for autonomous route
    chassis.setPose(-57,15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-33, 20, 1000, {false});//heading: 55.849 
    subsystem.intake.intake(6);
    pros::delay(800);
    tonguemech.toggle();
    pros::delay(600);
    

    //Turn around, keep tongue out.

    chassis.moveToPoint(-47, 47, 1500); //heading: 270
    chassis.turnToHeading(90, 1500);
    //Intake from match loader 
    chassis.moveToPoint(-58, 47, 1000, {false, 78}); //heading: 270
     chassis.moveToPoint(-67, 47, 600, {false, 40});
     pros::delay(1000);

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-30, 47, 500, {true, 127, 50}); //271.246
    chassis.moveToPoint(-20, 47, 500, {true, 45});
    pros::delay(500);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-47, 47, 800, {false});
    chassis.moveToPoint(-30, 57, 800);
    chassis.moveToPoint(-8, 54, 4000);

}

/**
 * Runs in driver control
 */
void opcontrol() {
  whileAuton = false;
  while (true) {
    // run the subsystems
    subsystem.intake.run();
    subsystem.tongue.run();

    // Tank Drive
    int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
    int turn = master.get_analog(ANALOG_RIGHT_Y);  // Gets the turn left/right from right joystick
    left.move(dir);                      // Sets left motor voltage
    right.move(turn); 

  
  
    // WING CONTROL
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      wing.toggle();   // Y pressed → extend
  }

  // Delay to save resources
  pros::delay(50);
  }

}

