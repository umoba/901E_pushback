#pragma once

namespace Robot {

/**
 * @brief The Auton class handles autonomous routine selection and execution.
 */
class distanceAlgo {
public:
   /**
    * @brief Array of auton route descriptions for LCD display
    * Change as needed to match auton routes implemented in auton.cpp
    */
  
  double inchToMM(double inches);
  double mmToInch(double mm);
  double backDist();
  double leftDist();
  double rightDist();


  distanceAlgo();

};
} // namespace Robot