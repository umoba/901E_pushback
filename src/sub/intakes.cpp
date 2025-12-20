#include "subs_headers/intakes.h"
#include "config.hpp"
#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"

using namespace Robot;
using namespace Robot::Globals;




Intake::Intake() : state(0) {}

int state = -1;
void Intake::intake(int state) {
  // OVERALL INTAKE FUNCTIONS
  // stop
  if (state == 0) {
    topIntake.move_velocity(STOPPED_VELOCITY);
    sprocketIntake.move_velocity(STOPPED_VELOCITY);
    flexIntake.move_velocity(STOPPED_VELOCITY);
  }
  // long goal
  else if (state == 1) {
    topIntake.move_velocity(MAX_55_VELOCITY);
    sprocketIntake.move_velocity(MAX_11_VELOCITY);
    flexIntake.move_velocity(HALFED_55_VELOCITY);
  }
  // upper goal
  else if (state == 2) {
    topIntake.move_velocity(-MAX_55_VELOCITY);
    sprocketIntake.move_velocity(MAX_11_VELOCITY);
    flexIntake.move_velocity(HALFED_55_VELOCITY);
  }
  // low goal
  else if (state == 3) {
    topIntake.move_velocity(-MAX_55_VELOCITY);
    sprocketIntake.move_velocity(-MAX_11_VELOCITY);
    flexIntake.move_velocity(-HALFED_55_VELOCITY);
  }
  // skills upper
  else if (state == 4) {
    topIntake.move_velocity(-HALFED_55_VELOCITY);
    sprocketIntake.move_velocity(-MAX_11_VELOCITY);
    flexIntake.move_velocity(-HALFED_55_VELOCITY);
  }
  // skills low
  else if (state == 5) {
    topIntake.move_velocity(-HALFED_55_VELOCITY);
    sprocketIntake.move_velocity(-MAX_11_VELOCITY);
    flexIntake.move_velocity(-HALFED_55_VELOCITY);
  }
  // 
  else if (state == 6) {

  }

  else if (state == 7) {

  }

  else if (state == 8) {

  }

  else if (state == 9) {

  }

  else if (state == 10) {

  }

 }


void intakeState(int a) {
  
}

// Run the intake
void Intake::run() {
if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {

      midGoal.extend();
      int intakeState = sprocketIntake.get_direction(); // get current intake direction
      pros::lcd::print(4, "intake state: %d", intakeState);
      if (intakeState==1){
        topIntake.move(0);
        sprocketIntake.move(0);
        flexIntake.move(0); 
      }
      else{
      Intake::intake(3);
      pros::delay(300);
      if (Config::prematches.skillsMode) {
        Intake::intake(4);
      }
      else {
        topIntake.move(-127); // run intake when piston is toggled
      sprocketIntake.move(127); // run intake when piston is toggled
      flexIntake.move(127);
      }
      }
    }

  // Long goal 
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
      midGoal.retract();
      int intakeState = sprocketIntake.get_direction(); // get current intake direction
      pros::lcd::print(4, "intake state: %d", intakeState);
      if (intakeState==1){
        topIntake.move(0);
        flexIntake.move(0);
        sprocketIntake.move(0);
      }
      else{
      topIntake.move(127); // run intake when piston is toggled
      flexIntake.move(127);
      sprocketIntake.move(127);
      }
  }

// Outtake 
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      int intakeState = sprocketIntake.get_direction(); // get current intake direction
      pros::lcd::print(4, "intake state: %d", intakeState);
      if (intakeState==-1){
        flexIntake.move(0);
        sprocketIntake.move(0);
        topIntake.move(0);
      }
      else{
        if (Config::prematches.skillsMode) {
          Intake::intake(5);
        }
        else {
          topIntake.move(-127); // run intake when piston is toggled
          sprocketIntake.move(-127); // run intake when piston is toggled
          flexIntake.move(-127);
        }
      }
  }



  //R1 close hood storage 
  //R2 deactivate hood, long goal scoring 
  //L1 middle goal scoring, always close the hood (retracted)
  //L2 outtake 
  //arrow up initiate wing 
  //X is tonguemech, retract after being pressed once again 



//OUTAKE (Bottom score)
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
      midGoal.extend();
      int intakeState = sprocketIntake.get_direction(); // get current intake direction
      pros::lcd::print(4, "intake state: %d", intakeState);
      if (intakeState==1){
        sprocketIntake.move(0);
        flexIntake.move(0);
        topIntake.move(0);
      }
      else{
      flexIntake.move(127);
      sprocketIntake.move(127);
      topIntake.move(127); // run intake when piston is toggled
      }
    
  }
}

// Toggle whether the intake is stopping the blocks from scoring or not
void Intake::toggleStopper() {
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      // stopper.toggle();
      // stopped = !stopped;
  }
}

// // Color sorting
// void Intake::color_sort() {
//   if (auton) {
//      coloring.set_led_pwm(50);
//     if (coloring.get_hue() >= 25.0 && coloring.get_hue() <= 30.0 && !red) {
        
//       intake(8);
//       pros::delay(500);
//       intake(6);
//     } 
//     else if (coloring.get_hue() >= 180.0 && coloring.get_hue() <= 240.0 && red) {
//         intake(8);
//     }

//   }
   

// }
// Double parking 
void Intake::park() {
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      // doublePark.toggle();
  }
}

// int flexIntakeVelocityDeterminer() {
//   if (tonguemech.extended()) {
//     return MAX_55_VELOCITY;
//   }
//   else {
//     return HALFED_55_VELOCITY;
//   }
// }
