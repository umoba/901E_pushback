#pragma once

namespace Robot {

/**
 * @brief The Auton class handles autonomous routine selection and execution.
 */
class Auton {
public:
   /**
    * @brief Array of auton route descriptions for LCD display
    * Change as needed to match auton routes implemented in auton.cpp
    */
  const char* routeSpecifics[12];
  int autonRoute;
  bool locked;
  void autonSelection();
  void selectedAuton(int route);
  void runSelectedAuton(int route);
  void controllerAutonSelection();


  Auton();

};
} // namespace Robot