// #include "main.h"
#include "autonomous_headers/auton.h"

#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"

using namespace Robot;
using namespace Robot::Globals;

Auton::Auton() : autonRoute(0), routeSpecifics(
  "No Auton",
  "Solo AWP",
  "Right 3 + 6",
  "Right 7 Block",
  "Left 7 Block",
  "Left 3 + 6",
  "Skills",
  "---",
  "---",
  "---",
  "---",
  "Full Skills") 
  
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

      pros::lcd::print(5, "Auton Selector Value: %f", autonSelector.get_position());
      pros::lcd::print(6, "Auton Selector Set to: %d", autonRoute);
      pros::lcd::print(7, "Route: %s", routeSpecifics[autonRoute]);
    }
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
      // Right Mid Goal
      break;
    case 8:
      // Left Mid Goal
      break;
    case 9:
      // Right High Goal
      break;
    case 10:
      // Left High Goal
      break;
    case 11:
      // Full Skills
      break;
  }
}
