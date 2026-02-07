#include "autonomous_headers/autonomousRoutes.h"
#include "autonomous_headers/distanceAlgo.hpp"
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
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
    subsystem.intake.intake(6);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-28.5, -21, 700, {false});//heading: 55.849 
    pros::delay(700);
    tonguemech.toggle();
    pros::delay(400);
    

    //Turn around, keep tongue out.

    chassis.moveToPoint(-47, -42, 1000); //heading: 270
    chassis.turnToHeading(90, 650);
    //Intake from match loader 
    chassis.moveToPoint(-70, -43, 900, {false, 60}); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-26, -46, 1100); //271.246
    pros::delay(1000);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-45, -47, 800, {false});
    chassis.turnToPoint(-33, -35, 300);
    chassis.moveToPoint(-35, -35, 700);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.turnToPoint(-11, -35, 300);
    chassis.moveToPoint(-10, -35, 1200);
}

// NEEDS TUNING
void AutonomousRoutes::left7blocks() {
    // setting pose for autonomous route
    chassis.setPose(-57,15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-28.5, 21, 800, {false});//heading: 55.849 
    subsystem.intake.intake(6);
    pros::delay(800);
    tonguemech.toggle();
    pros::delay(600);
    

    //Turn around, keep tongue out.

    chassis.moveToPoint(-47, 44, 1000); //heading: 270
    chassis.turnToHeading(90, 700);
    //Intake from match loader 
    chassis.moveToPoint(-65, 48, 1200, {false, 60}); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-24, 48.5, 1500); //271.246
    pros::delay(1000);
    subsystem.intake.intake(1);
    pros::delay(2000);
    subsystem.intake.intake(6);
    tonguemech.toggle();
    chassis.moveToPoint(-47.5, 48, 800, {false});
    chassis.turnToPoint(-37, 59.1, 400);
    chassis.moveToPoint(-37, 59.1, 700);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-8, 60.1, 1800);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
}


// NOT FINISHED
void AutonomousRoutes::right36() {
  chassis.setPose(-57, -15, 270);
  //intake 3 mid balls
  chassis.moveToPoint(-28.5,-21.3,900, {false});
  subsystem.intake.intake(6);
  pros::delay(700);
  tonguemech.toggle();
  //intake long goal balls 
  chassis.moveToPoint(-12, -45.3, 950, {false});
  pros::delay(400);
  tonguemech.toggle();
  pros::delay(450);
  tonguemech.toggle();
  chassis.moveToPoint(-30,-30,800);
chassis.turnToHeading(225,400);
  chassis.moveToPoint(-43,-51,1000);
  chassis.turnToHeading(90,670);

  chassis.moveToPoint(-28,-52,1100, {true, 65});

  pros::delay(1100);
  subsystem.intake.intake(1);
  pros::delay(1400);


  chassis.moveToPoint(-65,-49.5,1000, {false, 55});
    chassis.moveToPoint(-75,-49.5,600, {false, 55});

  subsystem.intake.intake(6);

  chassis.moveToPoint(-48,-49.5,500);
  
  chassis.turnToHeading(225,800);
  subsystem.intake.intake(0);
  tonguemech.toggle();

  chassis.moveToPoint(-15,-15,1500, {false});
  pros::delay(800);
  subsystem.intake.intake(3);
  pros::delay(1200);

    chassis.moveToPoint(-38, -37, 1000);
    subsystem.intake.intake(6);
    chassis.turnToPoint(-16,-37.5, 500);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.moveToPoint(-16, -37.5, 1000);

  

}

// NOT STARTED
void AutonomousRoutes::left36() {

  // setting pose for autonomous route
    chassis.setPose(-57,15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-28.5, 21, 800, {false});//heading: 55.849 
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

        chassis.moveToPoint(-75, 46.8, 1500, {false, 60}); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
  
    subsystem.intake.intake(6);
        chassis.moveToPoint(-47, 47, 1000, {true}); //heading: 270
          chassis.turnToPoint(-11.5, 11.5, 400);

        chassis.moveToPoint(-12, 11.5, 1600); //heading: 270
    pros::delay(1300);
    subsystem.intake.intake(2);
    pros::delay(1500);
        chassis.moveToPoint(-47, 46.8, 1150, {false}); //heading: 270

    //Intake from match loader 

    tonguemech.toggle();
    chassis.turnToPoint(-37, 55.6, 400);
    chassis.moveToPoint(-37, 55.6, 700);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-9, 55.6, 1500);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
}

// NEEDS TUNING
void AutonomousRoutes::soloAWP() {
  // AWP
  // START
  wing.extend();
  chassis.setPose(-46.254, 0.198, 180);
  subsystem.intake.intake(6);
  chassis.moveToPoint(-46.254, 5, 300, {false});
  chassis.moveToPoint(-46.254, -39, 950, {true, 90, 0});
  chassis.turnToHeading(90, 300);
  tonguemech.toggle();
  subsystem.intake.intake(6);
  // GO TO MATCH LOAD
  chassis.moveToPoint(-65, -44, 1000, {false, 65, 0});


  // GO TO LONG GOAL
  chassis.moveToPoint(-24, -44, 400, {true, 100, 80});
  chassis.moveToPoint(-24, -43.5, 700, {true, 65, 0});
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
  chassis.moveToPoint(-15, 25, 1500, {false, 90, 0});
  pros::delay(200);
  tonguemech.toggle();
  pros::delay(750);
  tonguemech.toggle(); //extend
  chassis.turnToHeading(135, 400);

  // MOVE TO MID UPPER
  chassis.moveToPose(0, 15, 135,900);
  pros::delay(600);
  subsystem.intake.intake(2);
  pros::delay(900);

  // BACK AWAY
  chassis.moveToPoint(-45, 55, 1000, {false, 100, 0});
  subsystem.intake.intake(7);
  pros::delay(80);
  chassis.turnToHeading(90, 500);
  subsystem.intake.intake(6);

  // GO TO MATCH LOAD
  chassis.moveToPoint(-63, 56, 900, {false, 70, 0});

  // GO TO LONG GOAL
  chassis.moveToPoint(-20, 53, 500, {true, 90, 70});
  pros::delay(500);
// chassis.moveToPoint(-15, 51, 400, {true, 90, 50});
pros::delay(100);
  subsystem.intake.intake(1);
    chassis.moveToPoint(-20, 31, 900, {true, 90, });

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
  pros::delay(600);
  tonguemech.toggle();
  chassis.moveToPose(-8.526, 11.077, 135, 1700);
  pros::delay(1500);
  subsystem.intake.intake(2);
  pros::delay(1750);
  subsystem.intake.intake(1);
  chassis.moveToPoint(-40, 48, 1700, {false, 100, 0});
  chassis.turnToHeading(90, 350);
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
  chassis.moveToPoint(45, 59, 2300, {false, 100, 0});
  pros::delay(700);
  
  chassis.turnToHeading(180, 700);
  chassis.moveToPoint(45, 45.5, 800, {true, 100, 0});
  chassis.turnToHeading(180, 500);
  pros::delay(1000);
  // add hard reset here
  chassis.setPose(autonSystem.distanceAlgo.leftDist(), 47, 180);

  chassis.turnToHeading(270, 700);

  chassis.moveToPoint(30, 47, 1200, {true, 110, 0});
  pros::delay(1000);
  subsystem.intake.intake(1);
  chassis.moveToPoint(20, 47, 1000, {true, 110, 50});

    pros::delay(2500);
chassis.setPose(31, 47, 270);

  // Second Matchloader
  chassis.moveToPoint(70, 46, 2000, {false, 60, 0});
  tonguemech.toggle();
  pros::delay(300);
  subsystem.intake.intake(6);
  pros::delay(1200);
    chassis.moveToPoint(70, 47, 500, {false, 60, 0});

  chassis.moveToPoint(75, 47, 1000, {false, 60, 0});
  pros::delay(800);
  chassis.moveToPoint(29, 47, 1000, {true, 100, 0});
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
chassis.moveToPoint(40, -53, 3000, {false, 100, 0});
chassis.turnToHeading(270, 600);


chassis.moveToPoint(68, -53, 1500, {false, 60, 0});
  tonguemech.toggle();
  pros::delay(1500);
  chassis.moveToPoint(75, -53, 1000, {false, 70, 0});
  pros::delay(800);


chassis.moveToPoint(50, -53, 800, {false, 100, 0});
   pros::delay(300);
  tonguemech.toggle();
  chassis.moveToPoint(45, -65, 1000, {true, 100, 0});
  chassis.turnToHeading(270, 700);
  chassis.moveToPoint(-45, -65, 2600, {true, 100, 0});

chassis.turnToHeading(180, 1000);

  chassis.moveToPoint(-46, -53, 1000, {false, 100, 0});
chassis.turnToHeading(90, 600);
chassis.moveToPoint(-20, -53, 1000, {true, 85, 0});
chassis.turnToHeading(90, 200);
chassis.moveToPoint(-20, -53, 500, {true, 85, 0});
subsystem.intake.intake(1);
  pros::delay(3000);
  chassis.setPose(-31.543, -46.705, 90);
   
  chassis.moveToPoint(-68, -46.705, 2000, {false, 60, 0});
  subsystem.intake.intake(6);
  tonguemech.toggle();
  pros::delay(1500);
  chassis.moveToPoint(-75, -45.5, 1000, {false, 70, 0});
  pros::delay(800);
chassis.moveToPoint(-20, -46.5, 1500, {true, 80, 0});
pros::delay(1400);
subsystem.intake.intake(1);
pros::delay(2000);


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

void AutonomousRoutes::left34endmid() {
  // setting pose for autonomous route
    chassis.setPose(-57,15, 270);
    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-28.5, 21, 800, {false});//heading: 55.849 
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

        chassis.moveToPoint(-75, 46.8, 1300, {false, 60}); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
  
    subsystem.intake.intake(6);
        chassis.moveToPoint(-47, 47, 1000, {true}); //heading: 270
          chassis.turnToPoint(-11.5, 11.5, 400);

        chassis.moveToPoint(-11.5, 11.5, 1600); //heading: 270
    pros::delay(1300);
    subsystem.intake.intake(2);
    pros::delay(1500);
    //Intake from match loader 

    tonguemech.toggle();
    chassis.moveToPoint(-35, 38.5, 800, {false});
    subsystem.intake.intake(6);
    chassis.turnToHeading(270,700);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.moveToPoint(-16, 38.5, 1000, {false});
    
}

void AutonomousRoutes::bothMid() {
      chassis.setPose(-57, -15, 270);
      chassis.moveToPoint(-28.7,-21.3,900, {false});
  subsystem.intake.intake(6);
  pros::delay(700);
  tonguemech.toggle();
  //intake long goal balls 
  chassis.moveToPoint(-11.5, -45.3, 950, {false});
  pros::delay(400);
  tonguemech.toggle();
  pros::delay(450);
  tonguemech.toggle();
  chassis.moveToPoint(-30,-30,800);
chassis.turnToHeading(225,400);
  chassis.moveToPoint(-48,-48,850);
  chassis.turnToHeading(90,600);
  chassis.moveToPoint(-65,-48,1000, {false, 70});
    // chassis.moveToPoint(-75,-49.5,500, {false, 65});

  subsystem.intake.intake(6);

  chassis.moveToPoint(-48,-49.5,500);
  
  chassis.turnToHeading(225,700);
  subsystem.intake.intake(0);
  tonguemech.toggle();

  chassis.moveToPoint(-16,-16,1400, {false, 70});
  pros::delay(1300);
  subsystem.intake.intake(5);
  pros::delay(1000);
    chassis.moveToPoint(-26, -25, 1200, {true});
    subsystem.intake.intake(6);

    chassis.turnToHeading(180,700);
    chassis.moveToPoint(-23, 24, 1400, {false, 90});
    chassis.turnToHeading(135,700);

        chassis.moveToPoint(-14,13, 1400, {true});
  pros::delay(1200);
  tonguemech.toggle();
  subsystem.intake.intake(2);

    
}

void AutonomousRoutes::rushleft() {
  chassis.setPose(-47.5,14, 180);
  chassis.moveToPoint(-47.5, 45, 800, {false, 90});
  subsystem.intake.intake(6);
  chassis.turnToHeading(90,350);
  tonguemech.toggle();
  chassis.moveToPoint(-70, 45, 950, {false, 70});
  chassis.moveToPoint(-20, 45, 1000, {true, 90});
  pros::delay(750);
  subsystem.intake.intake(1);
  pros::delay(1000);
  chassis.moveToPoint(-42, 45, 700, {false, 90});
chassis.turnToPoint(-32,53.5, 200);
chassis.moveToPoint(-32,53.5, 400);
chassis.turnToPoint(-10,53.5, 200);
  chassis.moveToPoint(-10, 53.5, 700, {true, 90});
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);


}

void AutonomousRoutes::rushright() {
  chassis.setPose(-47.5,-14, 0);
  chassis.moveToPoint(-47.5, -44, 800, {false, 90});
  subsystem.intake.intake(6);
  chassis.turnToHeading(90,350);
  tonguemech.toggle();
  chassis.moveToPoint(-70, -44, 1050, {false, 70});
  chassis.moveToPoint(-20, -44, 1000, {true, 90});
  pros::delay(750);
  subsystem.intake.intake(1);
  pros::delay(1000);
  chassis.moveToPoint(-42, -44, 700, {false, 90});
chassis.turnToPoint(-32,-36.5, 200);
chassis.moveToPoint(-32,-36.5, 400);
chassis.turnToPoint(-10,-36.5, 200);
  chassis.moveToPoint(-10, -35.5, 700, {true, 90});
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
}