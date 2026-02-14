// #include "main.h"
#include "autonomous_headers/auton.h"

#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"
#include "globals.h"
using namespace Robot;
using namespace Robot::Globals;

Auton::Auton() : locked(false),autonRoute(0), routeSpecifics(
  "NoAuton",
  "SoloAWP",
  "Right3+6",
  "Right7",
  "Left7",
  "Left3+6",
  "Skills",
  "BothMid",
  "Left3+4End Mid",
  "rushright",
  "rushleft",
  "---") 
  
  {}


/*
  Ran during autonSelection() to set the selected auton route
*/
void Auton::selectedAuton(int route) {
  autonRoute = route;
}

/*
  Auton Selection Logic run during initialize
  Uses the autonSelector rotation sensor to determine which auton to run
*/
void Auton::autonSelection() {
  for (int i = 0; i < 36000; i += 3000)  {
    if (i <= autonSelector.get_position() && autonSelector.get_position() < i + 3000) {
      
      int routeNum = i / 3000;
      selectedAuton(routeNum);
      if (routeNum == 6) {
        subsystem.intake.skills = true;
      }
      else {
        subsystem.intake.skills = false;
      }
      pros::lcd::print(5, "Auton Selector Value: %f", autonSelector.get_position());
      pros::lcd::print(6, "Auton Selector Set to: %d", autonRoute);
      pros::lcd::print(7, "Route: %s", routeSpecifics[autonRoute]);
    
    }
  }
}

void Auton::controllerAutonSelection() {
  if (!locked) {
    master.print(0, 0,"#: %d", autonSystem.auton.autonRoute);
    pros::delay(50);
    master.print(0, 8, "%s", autonSystem.auton.routeSpecifics[autonSystem.auton.autonRoute]); 
    pros::delay(50);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    locked = true;
    master.rumble("-"); //locked
    master.clear_line(0);
    pros::delay(50);
    master.print(0,0,"LOCKED");
  }
  else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    locked = false;
    master.clear_line(0);
    pros::delay(50);
    master.rumble(".."); //unlocked
  }
  if (!locked && master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    autonSystem.auton.autonRoute++;
    if (autonSystem.auton.autonRoute > 11) {
      autonSystem.auton.autonRoute = 0;
    }
    master.clear_line(0);
    pros::delay(50);
  }
  else if (!locked && master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    autonSystem.auton.autonRoute--;
    if (autonSystem.auton.autonRoute < 0) {
      autonSystem.auton.autonRoute = 11;
    }
    master.clear_line(0);
    pros::delay(50);
  }
}

// Runs the selected auton based on the route number
void Auton::runSelectedAuton(int route) {
  switch (route) {
    case 0:
      // No auton
      break;
    case 1:
      // Solo AWP
      autonSystem.autonomousRoutes.soloAWP();
      break;
    case 2:
      // Right 3 + 6
      autonSystem.autonomousRoutes.right36();
      break;
    case 3:
      // Right 7 Block
      autonSystem.autonomousRoutes.right7blocks();
      break;
    case 4:
      // Left 7 Block
      autonSystem.autonomousRoutes.left7blocks();
      break;
    case 5:
      // Left 3 + 6
      autonSystem.autonomousRoutes.left36();
      break;
    case 6:
      // Skills 
      autonSystem.autonomousRoutes.skills();
      break;
    case 7:
      autonSystem.autonomousRoutes.bothMid();
      break;
    case 8:
      // Left Mid Goal
      autonSystem.autonomousRoutes.left34endmid();
      break;
    case 9:
      // Right rush
      autonSystem.autonomousRoutes.rushright();
      break;
    case 10:
      // Left rush
      autonSystem.autonomousRoutes.rushleft();
      break;
    case 11:
      // Full Skills
      break;
  }
}
