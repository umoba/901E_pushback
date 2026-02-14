#include "main.h"
#include "globals.h"// IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
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
std::string str = "";
bool whileAuton = true;
bool whileInit = true;
void initialize() {
  pros::lcd::initialize();
  chassis.calibrate();
  master.clear();
  pros::delay(50);
  master.clear_line(0);
  pros::delay(50);
  master.clear_line(1);
  pros::delay(50);
  master.clear_line(2);
  pros::delay(50);

  Config::prematches.allianceIsRed = true;

  pros::Task screenTask([&]() {
    while (true) {
      if ( !whileAuton) {
      subsystem.intake.stopTOP();
      }
      // subsystem.intake.color_sort();
      // autonSystem.auton.autonSelection();
      
      // if (whileInit) {
        autonSystem.auton.controllerAutonSelection();
      // }
      // autonSystem.auton.controllerAutonSelection();
      // print robot location to the brain screen
      pros::lcd::print(0, "X: %f", chassis.getPose().x);
      pros::lcd::print(1, "Y: %f", chassis.getPose().y);
      pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);

      // master.print(1,0,)
      master.print(2,0,"Battery: %4f", pros::battery::get_capacity());




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


  // chassis.setPose(0,0,0);
  // // chassis.moveToPoint(0,24,10000);
  // chassis.turnToHeading(180,10000);

void autonomous() {

  autonSystem.auton.runSelectedAuton(autonSystem.auton.autonRoute);
  // autonSystem.auton.runSelectedAuton(2);
  // chassis.setPose(0,0,0);
  // chassis.turnToHeading(180,10000);
  // chassis.moveToPoint(0,24,10000);
}
// 
/**
 * Runs in driver control
 */
void opcontrol() {
  whileInit = false;
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
  chassis.cancelAllMotions();
  // subsystem.intake.skills = true;
  if (subsystem.intake.skills == true) {
    wing.extend();
  }
  
  subsystem.intake.intake(0);
  whileAuton = false;
  int leftStick, rightStick;
  while (true) {
    // run the subsystems
    subsystem.intake.run();
    
    subsystem.tongue.run();
    
    // Tank Drive
    int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
    int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
    // if (dir<= 0) {
    //   leftStick = -dir * dir * 1/127;
    // }
    // else {
    //   leftStick = dir * dir * 1/127;
    // }
    // if (turn <= 0) {
    //   rightStick = -turn * turn * 1/127;
    // }
    // else {
    //   rightStick = turn * turn * 1/127;
    // }

    // leftStick = dir * dir * dir * 1/16129;    // Cubic scaling for finer control
    // rightStick = turn * turn * turn * 1/16129;  // Cubic scaling for finer control
    // left.move(leftStick);                      // Sets left motor voltage
    // right.move(rightStick); 

    chassis.curvature(dir, turn, false);

  
  
    // WING CONTROL
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      wing.toggle();   // Y pressed → extend
  }

  // Delay to save resources
  pros::delay(50);
  }

}

