#include "autonomous_headers/autonomousRoutes.h"

#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"

using namespace Robot;
using namespace Robot::Globals;

AutonomousRoutes::AutonomousRoutes() {}

void AutonomousRoutes::right7blocks() {
    // setting pose for autonomous route
    chassis.setPose(-143,-40, 101);

    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-57, -57, 1000);//heading: 55.849 

    //Turn around, keep tongue out.
    //Intake from match loader 
    chassis.moveToPoint(-147, -119, 1000); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-70, -119, 1000); //271.246

    //back up a bit, wing on 
    chassis.moveToPoint(-95,-118, 1000); // 52.125
    chassis.moveToPoint(-66,-96,1000); //270.698

    //drive straight to push balls into center 
    chassis.moveToPoint(-23, -96, 1000);// 81.87


    // // example autonomous route function


}

void AutonomousRoutes::left7blocks() {
    // setting pose for autonomous route
    chassis.setPose(-143,47, 84);

    //heading to three balls + intake + tongue out
    chassis.moveToPoint(-57, 56, 1000);//heading: 124

    //Turn around, keep tongue out.
    //Intake from match loader 
    chassis.moveToPoint(-148, 119, 1000); //heading: 270

    // Stop intake first, go straight to long goal 
    //score in long goal 
    chassis.moveToPoint(-79, 119, 1000); //270

    //back up a bit, wing on 
    chassis.moveToPoint(-106,119, 1000); //46
    chassis.moveToPoint(-83,141,1000); //270

    //drive straight to push balls into center 
    chassis.moveToPoint(-34, 141, 1000);// 81
}