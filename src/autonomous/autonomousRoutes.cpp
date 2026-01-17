#include "autonomous_headers/autonomousRoutes.h"
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "config.hpp"
#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"
#include "autonomous_headers/distanceAlgo.hpp"

using namespace Robot;
using namespace Robot::Globals;

AutonomousRoutes::AutonomousRoutes() {}
// NEEDS TUNING
void AutonomousRoutes::right7blocks() {
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
    chassis.moveToPoint(-65, -47, 800, {false, 90}); //heading: 270
        chassis.moveToPoint(-65, -47, 700, {false, 65}); 
     pros::delay(700);

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-30, -49, 1000); //271.246
    pros::delay(1000);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-47, -45, 800, {false});
    chassis.moveToPoint(-25, -39, 800);
    chassis.moveToPoint(-15, -39, 4000);
}

// NEEDS TUNING
void AutonomousRoutes::left7blocks() {
chassis.setPose(-57,15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-28.5, 20.5, 1000, {false});//heading: 55.849 
    subsystem.intake.intake(6);
    pros::delay(715);
    tonguemech.toggle();
    pros::delay(550);
    

    //Turn around, keep tongue out.

    chassis.moveToPoint(-47, 47, 1500); //heading: 270
    chassis.turnToHeading(90, 1500);
    //Intake from match loader 
    chassis.moveToPoint(-60, 47, 800, {false, 90}); //heading: 270
     chassis.moveToPoint(-73, 47, 750, {false, 55});
     pros::delay(790);

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-30, 47, 500, {true, 127, 50}); //271.246
    chassis.moveToPoint(-20, 47, 500, {true, 53});
    pros::delay(500);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-47.5, 47, 800, {false});
    chassis.moveToPoint(-30, 56.1, 800);
    chassis.moveToPoint(-13.3, 54.2, 4000);
}
// NOT FINISHED
void AutonomousRoutes::right36() {
    chassis.setPose(-57, -15, 270);
  //intake 3 mid balls
  chassis.moveToPoint(-30,-20,950, {false});
  subsystem.intake.intake(6);
  pros::delay(700);
  tonguemech.toggle();
  //intake long goal balls 
  chassis.moveToPoint(-14, -42.5, 950, {false});
  pros::delay(400);
  tonguemech.toggle();
  pros::delay(600);
  tonguemech.toggle();
  chassis.moveToPoint(-40,-15,1000);

  chassis.moveToPoint(-47,-47,1000);
  pros::delay(950);
  subsystem.intake.intake(1);
}

// NOT STARTED
void AutonomousRoutes::left36() {

}

// NEEDS TUNING
void AutonomousRoutes::soloAWP() {
  // AWP
  // START
  chassis.setPose(-46.254, 0.198, 180);
  subsystem.intake.intake(6);
  chassis.moveToPoint(-46.254, 5, 300, {false});
  chassis.moveToPoint(-46.254, -40, 950, {true, 100, 0});
  chassis.turnToHeading(90, 300);
  tonguemech.toggle();
  subsystem.intake.intake(6);
  // GO TO MATCH LOAD
  chassis.moveToPoint(-65, -45, 950, {false, 90, 50});


  // GO TO LONG GOAL
  chassis.moveToPoint(-24, -45, 700, {true, 100, 50});
  pros::delay(650);
  // SCORE IN LONG GOAL
  subsystem.intake.intake(1);
  pros::delay(1300);

  subsystem.intake.intake(6);
  tonguemech.toggle(); //retract

  // GO BACK A BIT
  chassis.moveToPoint(-35, -39, 300, {false, 95, 0});
  chassis.turnToHeading(220, 300);

  // GET THREE BLOCKS
  chassis.moveToPoint(-18, -23, 1100, {false, 90, 0});
  pros::delay(940);
  tonguemech.toggle(); //extend

  chassis.turnToHeading(180, 300);
 //retract

  // GET OTHER THREE BLOCKS
  chassis.moveToPoint(-16, 24, 1500, {false, 90, 0});
  pros::delay(200);
  tonguemech.toggle();
  pros::delay(750);
  tonguemech.toggle(); //extend
  chassis.turnToHeading(135, 400);

  // MOVE TO MID UPPER
  chassis.moveToPose(-1, 14, 135,1000);
  pros::delay(800);
  subsystem.intake.intake(2);
  pros::delay(1100);

  // BACK AWAY
  chassis.moveToPoint(-47, 53, 1000, {false, 100, 50});
  subsystem.intake.intake(7);
  pros::delay(80);
  subsystem.intake.intake(6);
  chassis.turnToHeading(90, 400);

  // GO TO MATCH LOAD
  chassis.moveToPoint(-63, 53, 900, {false, 90, 0});

  // GO TO LONG GOAL
  chassis.moveToPoint(-24, 50, 900, {true, 100, 60});
  pros::delay(800);
  subsystem.intake.intake(1);
}

void AutonomousRoutes::skills() {
  // TO BE FILLED

  // Initialize starting pose
  chassis.setPose(-46, 14.7, 270);
  subsystem.intake.intake(6);
  chassis.moveToPoint(-33.6, 14.7, 1000, {false});
  chassis.turnToHeading(225, 500);
  chassis.moveToPoint(-29.567, 18.067, 800, {false});
  chassis.moveToPose(-9.026, 11.077, 135, 1700);
  pros::delay(1500);
  subsystem.intake.intake(2);
  pros::delay(850);
  subsystem.intake.intake(1);
  chassis.moveToPoint(-40, 48, 1700, {false, 100, 0});
  chassis.turnToHeading(90, 350);
  tonguemech.toggle();
  chassis.moveToPoint(-65, 48, 1500, {false, 70, 0});
  pros::delay(1000);
  subsystem.intake.intake(6);
  pros::delay(600);
  // First Matchloader
  chassis.moveToPoint(-65, 48, 400, {false, 70, 0});
  pros::delay(600);
  chassis.moveToPoint(-50, 48, 1000, {false, 100, 0});
   pros::delay(300);
  tonguemech.toggle();
  chassis.moveToPoint(-45, 61, 1000, {true, 100, 0});
  chassis.turnToHeading(270, 700);
  chassis.moveToPoint(45, 59, 3000, {false, 100, 0});
  pros::delay(700);
  
  chassis.turnToHeading(180, 1000);
  chassis.moveToPoint(45, 45.5, 800, {true, 100, 0});
  chassis.turnToHeading(180, 500);
  
  // add hard reset here
  chassis.setPose(autonSystem.distanceAlgo.leftDist(), autonSystem.distanceAlgo.backDist(), 180);

  chassis.turnToHeading(270, 400);

  chassis.moveToPoint(30, 44, 1200, {true, 110, 0});
  pros::delay(1000);
  subsystem.intake.intake(1);
  chassis.moveToPoint(20, 45.5, 1000, {true, 110, 50});

  pros::delay(500);
    pros::delay(2000);


  // Second Matchloader
  subsystem.intake.intake(6);
  chassis.moveToPoint(70, 45, 1000, {false, 70, 0});
  tonguemech.toggle();
  pros::delay(2000);
  chassis.moveToPoint(30, 45, 1000, {true, 100, 0});
  pros::delay(950);
  subsystem.intake.intake(1);

}