#include "autonomous_headers/autonomousRoutes.h"
#include "autonomous_headers/distanceAlgo.hpp"
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
// NEEDS TUNING
void AutonomousRoutes::right7blocks() {
  // setting pose for autonomous route
    chassis.setPose(-57,-15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-29, -21, 800, {false});//heading: 55.849 
    subsystem.intake.intake(6);
    pros::delay(700);
    tonguemech.toggle();
    pros::delay(400);
    

    //Turn around, keep tongue out.

    chassis.moveToPoint(-47, -45, 1150); //heading: 270
    chassis.turnToHeading(90, 700);
    //Intake from match loader 
    chassis.moveToPoint(-65, -46, 1200, {false, 60}); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-30, -47, 1000); //271.246
    pros::delay(1000);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-48, -47, 800, {false});
    chassis.moveToPoint(-30, -38.3, 800);
    chassis.moveToPoint(-15, -38.3, 6000);
}

// NEEDS TUNING
void AutonomousRoutes::left7blocks() {
    // setting pose for autonomous route
    chassis.setPose(-57,15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-29, 21, 900, {false});//heading: 55.849 
    subsystem.intake.intake(6);
    pros::delay(800);
    tonguemech.toggle();
    pros::delay(600);
    

    //Turn around, keep tongue out.

    chassis.moveToPoint(-47, 45, 1150); //heading: 270
    chassis.turnToHeading(90, 700);
    //Intake from match loader 
    chassis.moveToPoint(-65, 46, 1200, {false, 60}); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-30, 47, 1000); //271.246
    pros::delay(1000);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-47.5, 47, 800, {false});
    chassis.moveToPoint(-33, 54.1, 800);
    chassis.moveToPoint(-13.3, 54.2, 5000);
}


// NOT FINISHED
void AutonomousRoutes::right36() {
    chassis.setPose(-57, -15, 270);
  //intake 3 mid balls
  chassis.moveToPoint(-30,-21.3,900, {false});
  subsystem.intake.intake(6);
  pros::delay(700);
  tonguemech.toggle();
  //intake long goal balls 
  chassis.moveToPoint(-12, -43.3, 950, {false});
  pros::delay(400);
  tonguemech.toggle();
  pros::delay(450);
  tonguemech.toggle();
  chassis.moveToPoint(-30,-30,800);
chassis.turnToHeading(225,400);
  chassis.moveToPoint(-50,-49.5,1300);
  chassis.turnToHeading(90,670);

  chassis.moveToPoint(-28,-49.5,1300, {true, 65});

  pros::delay(1100);
  subsystem.intake.intake(1);
  pros::delay(1200);


  chassis.moveToPoint(-75,-49.5,700, {false, 65});
    chassis.moveToPoint(-75,-49.5,700, {false, 65});

  subsystem.intake.intake(6);

  chassis.moveToPoint(-48,-49.5,500);
  chassis.turnToHeading(225,800);
  tonguemech.toggle();

  chassis.moveToPoint(-19,-19,1500, {false});
  pros::delay(800);
  subsystem.intake.intake(3);
  pros::delay(1000);

    chassis.moveToPoint(-35, -40, 800);
    subsystem.intake.intake(6);
    chassis.turnToHeading(90,700);
    chassis.moveToPoint(-16, -40, 1000);
  

}

// NOT STARTED
void AutonomousRoutes::left36() {

  // setting pose for autonomous route
    chassis.setPose(-57,15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-29, 21, 900, {false});//heading: 55.849 
    subsystem.intake.intake(6);
    pros::delay(550);
    tonguemech.toggle();
    pros::delay(500);
    //Turn around, keep tongue out.

    chassis.turnToPoint(-47, 46.8, 400, {false});
    chassis.moveToPoint(-47, 46.5, 1100, {false}); //heading: 270
    chassis.turnToPoint(-28, 46.5, 400);
    chassis.moveToPoint(-20, 46.5, 1000); //271.246
    pros::delay(950);
    subsystem.intake.intake(1);
    pros::delay(1300);

        chassis.moveToPoint(-75, 46.8, 1400, {false, 60}); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
  
    subsystem.intake.intake(6);
        chassis.moveToPoint(-47, 47, 400, {false}); //heading: 270
        
        chassis.moveToPoint(-10.5, 10.5, 1400); //heading: 270
    pros::delay(1300);
        subsystem.intake.intake(2);
    pros::delay(1500);
        chassis.moveToPoint(-47, 46.8, 1150, {false}); //heading: 270

    //Intake from match loader 

    tonguemech.toggle();
    chassis.moveToPoint(-33, 53.4, 700);
    chassis.turnToHeading(90, 350);
    subsystem.intake.intake(0);
    chassis.moveToPoint(-11, 53.4, 1200);
      subsystem.intake.intake(0);
  
}

// NEEDS TUNING
void AutonomousRoutes::soloAWP() {
  // AWP
  // START
  chassis.setPose(-46.254, 0.198, 180);
  subsystem.intake.intake(6);
  chassis.moveToPoint(-46.254, 5, 300, {false});
  chassis.moveToPoint(-46.254, -40, 950, {true, 90, 0});
  chassis.turnToHeading(90, 300);
  tonguemech.toggle();
  subsystem.intake.intake(6);
  // GO TO MATCH LOAD
  chassis.moveToPoint(-65, -44, 1000, {false, 80, 50});


  // GO TO LONG GOAL
  chassis.moveToPoint(-24, -44, 400, {true, 100, 80});
  chassis.moveToPoint(-24, -44, 300, {true, 50, 0});
  pros::delay(650);
  // SCORE IN LONG GOAL
  subsystem.intake.intake(1);
  pros::delay(1300);

  subsystem.intake.intake(6);
  tonguemech.toggle(); //retract

  // GO BACK A BIT
  chassis.moveToPoint(-35, -39, 400, {false, 95, 0});
  chassis.turnToHeading(220, 300);

  // GET THREE BLOCKS
  chassis.moveToPoint(-18, -23, 1100, {false, 90, 0});
  pros::delay(940);
  tonguemech.toggle(); //extend

  chassis.turnToHeading(180, 300);
 //retractk

  // GET OTHER THREE BLOCKS
  chassis.moveToPoint(-16, 24, 1500, {false, 90, 0});
  pros::delay(200);
  tonguemech.toggle();
  pros::delay(750);
  tonguemech.toggle(); //extend
  chassis.turnToHeading(135, 400);

  // MOVE TO MID UPPER
  chassis.moveToPose(-1, 14, 135,1000);
  pros::delay(700);
  subsystem.intake.intake(2);
  pros::delay(1100);

  // BACK AWAY
  chassis.moveToPoint(-47, 50, 1000, {false, 100, 50});
  subsystem.intake.intake(7);
  pros::delay(80);
  subsystem.intake.intake(10);
  pros::delay(200);
  chassis.turnToHeading(90, 400);
  subsystem.intake.intake(6);

  // GO TO MATCH LOAD
  chassis.moveToPoint(-63, 50, 900, {false, 90, 0});

  // GO TO LONG GOAL
  chassis.moveToPoint(-20, 51, 800, {true, 90, 60});
  pros::delay(500);
chassis.moveToPoint(-15, 51, 600, {true, 90, 50});
pros::delay(100);
  subsystem.intake.intake(1);
    chassis.moveToPoint(-20, 51, 900, {true, 90, });

}




void AutonomousRoutes::skills() {
  // TO BE FILLED

  wing.extend();
  // Initialize starting pose
  chassis.setPose(-46, 14.7, 270);
  subsystem.intake.intake(6);
  chassis.moveToPoint(-33.6, 14.9, 1000, {false});
  chassis.turnToHeading(225, 500);
  chassis.moveToPoint(-26.567, 23.067, 800, {false});
  chassis.moveToPose(-9.026, 11.077, 135, 1700);
  pros::delay(1500);
  subsystem.intake.intake(2);
  pros::delay(2050);
  subsystem.intake.intake(1);
  chassis.moveToPoint(-40, 48, 1700, {false, 100, 0});
  chassis.turnToHeading(90, 350);
  tonguemech.toggle();
  chassis.moveToPoint(-65, 48, 1500, {false, 70, 0});
  pros::delay(1000);
  subsystem.intake.intake(6);
  pros::delay(600);
  // First Matchloader
  chassis.moveToPoint(-65, 48, 800, {false, 55, 0});
  pros::delay(800);
  chassis.moveToPoint(-50, 48, 1000, {false, 100, 0});
   pros::delay(300);
  tonguemech.toggle();
  chassis.moveToPoint(-45, 63, 1000, {true, 100, 0});
  chassis.turnToHeading(270, 700);
  chassis.moveToPoint(45, 59, 3000, {false, 100, 0});
  pros::delay(700);
  
  chassis.turnToHeading(180, 700);
  chassis.moveToPoint(45, 45.5, 800, {true, 100, 0});
  chassis.turnToHeading(180, 500);
  pros::delay(1000);
  // add hard reset here
  chassis.setPose(autonSystem.distanceAlgo.leftDist(), 47, 180);

  chassis.turnToHeading(270, 900);

  chassis.moveToPoint(30, 47, 1200, {true, 110, 0});
  pros::delay(1000);
  subsystem.intake.intake(1);
  chassis.moveToPoint(20, 47, 1000, {true, 110, 50});

    pros::delay(2500);
chassis.setPose(31, 47, 270);

  // Second Matchloader
  chassis.moveToPoint(70, 47, 2000, {false, 60, 0});
  tonguemech.toggle();
  pros::delay(300);
  subsystem.intake.intake(6);
  pros::delay(1200);
  chassis.moveToPoint(75, 47, 1000, {false, 60, 0});
  pros::delay(800);
  chassis.moveToPoint(30, 47, 1000, {true, 100, 0});
  pros::delay(1000);
  subsystem.intake.intake(1);
  pros::delay(3000);



  // TEST FROM HERE
  // Reset using long goal aligner
  chassis.setPose(31.543, 46.705, 270);
  tonguemech.toggle();

  // Move to neutral position
  chassis.moveToPoint(40, 46.705, 800, {true, 100, 0});
chassis.turnToHeading(0, 700);
subsystem.intake.intake(6);
chassis.moveToPoint(40, -48, 4000, {false, 100, 0});
chassis.turnToHeading(270, 800);


chassis.moveToPoint(68, -48, 2000, {false, 60, 0});
  tonguemech.toggle();
  pros::delay(1500);
  chassis.moveToPoint(75, -48, 1000, {false, 70, 0});
  pros::delay(800);


chassis.moveToPoint(50, -48, 1000, {false, 100, 0});
   pros::delay(300);
  tonguemech.toggle();
  chassis.moveToPoint(45, -60, 1000, {true, 100, 0});
  chassis.turnToHeading(270, 700);
  chassis.moveToPoint(-45, -61, 3000, {true, 100, 0});

chassis.turnToHeading(180, 1000);

  chassis.moveToPoint(-46, -47, 1000, {false, 100, 0});
chassis.turnToHeading(90, 600);
chassis.moveToPoint(-20, -47, 1000, {true, 85, 0});
chassis.turnToHeading(90, 200);
chassis.moveToPoint(-20, -47, 500, {true, 85, 0});
subsystem.intake.intake(1);
  pros::delay(3000);
  chassis.setPose(-31.543, -46.705, 90);
   
  chassis.moveToPoint(-68, -46.705, 2000, {false, 60, 0});
  subsystem.intake.intake(6);
  tonguemech.toggle();
  pros::delay(1500);
  chassis.moveToPoint(-75, -47, 1000, {false, 70, 0});
  pros::delay(800);
chassis.moveToPoint(-20, -47, 1500, {true, 80, 0});
subsystem.intake.intake(1);


  chassis.moveToPoint(-46, -47, 1000, {false, 100, 0});

    chassis.moveToPoint(-63, -26, 1000, {false, 100, 0});
chassis.turnToHeading(180, 700);
        chassis.moveToPoint(-63, 10, 2000, {false, 100, 0});
        tonguemech.toggle();
        pros::delay(1000);
        tonguemech.toggle();

  



  // ADD IF NECESSARY FOR NOW
// chassis.setPose(-45, -autonSystem.distanceAlgo.backDist(), 270);



  


}