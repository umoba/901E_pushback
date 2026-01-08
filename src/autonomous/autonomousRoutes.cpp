#include "autonomous_headers/autonomousRoutes.h"
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "config.hpp"
#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"

using namespace Robot;
using namespace Robot::Globals;

AutonomousRoutes::AutonomousRoutes() {}
void AutonomousRoutes::right7blocks() {
// FINISHED AUTONOMOUS ROUTES
  // setting pose for autonomous route
    chassis.setPose(-57,-15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-31, -20, 1000, {false});//heading: 55.849 
    subsystem.intake.intake(6);
    pros::delay(800);
    tonguemech.toggle();
    pros::delay(600);
    

    //Turn around, keep tongue out.

    chassis.moveToPoint(-47, -45, 1500); //heading: 270
    chassis.turnToHeading(90, 1500);
    //Intake from match loader 
    chassis.moveToPoint(-65, -47, 1500, {false}); //heading: 270
     pros::delay(1200);

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-30, -49, 1000); //271.246
    pros::delay(1000);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-47, -45, 800, {false});
    chassis.moveToPoint(-28, -39, 800);
    chassis.moveToPoint(-7, -39, 4000);

}

void AutonomousRoutes::left7blocks() {
    // setting pose for autonomous route
    chassis.setPose(-57,16, 0);

    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-22, 21, 1000);//heading: 124

    //Turn around, keep tongue out.
    //Intake from match loader 
    chassis.moveToPoint(-57, -47, 1000); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-30, -47, 1000); //270

    //back up a bit, wing on 
    chassis.moveToPoint(-34,-47, 1000); //46
    chassis.moveToPoint(-34,-38,1000); //270

    //drive straight to push balls into center 
    chassis.moveToPoint(-16, -38, 1000);// 81
}
// void AutonomousRoutes::right8block() {
  //     chassis.setPose(-57, -15, 270);
  // //intake 3 mid balls
  // chassis.moveToPoint(-31,-20,1000, {false});
  // subsystem.intake.intake(6);
  // pros::delay(800);
  // tonguemech.toggle();
  // pros::delay(300);
  // tonguemech.toggle();
  // pros::delay(600);
  // chassis.turnToHeading(315, 800);
  // //intake long goal balls 
  // chassis.moveToPoint(-9.5,-41.8,1100, {false, 80});
  // pros::delay(1000);
  // tonguemech.toggle();
  // chassis.moveToPoint(-29,-27,850);
  // subsystem.intake.intake(0);
  // pros::delay(100);
  // tonguemech.toggle();
  // chassis.turnToHeading(225, 800);
  // //score in low goal 
  // chassis.moveToPoint(-13.8,-9.8,1200, {false, 80});
  // pros::delay(1000);
  // subsystem.intake.intake(3);
  // pros::delay(2000);
  // subsystem.intake.intake(6);
  // chassis.moveToPoint(-47, -47, 1900);
  // chassis.turnToHeading(90, 900);
  // tonguemech.toggle();

  // //intake from match loader
  // chassis.moveToPoint(-68,-47, 1200, {false});
  // pros::delay(1700);

  // //score in long goal
  // chassis.moveToPoint(-30, -47, 1000);
  // pros::delay(1000);
  // subsystem.intake.intake(1);
// }