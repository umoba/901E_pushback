#pragma once

namespace Robot {

/**
 * @brief The Intake class represents a robot intake system.
 */
class Intake {
public:
   /**
    * @brief Runs the main function of the intake system.
    *
    * Takes optional user input to control the direction of the intake system in
    * autonomous.
    */
  const int MAX_55_VELOCITY=200;
  const int MAX_11_VELOCITY=600;
  const int HALFED_55_VELOCITY=100;
  const int STOPPED_VELOCITY=0;
  void intake(int state);
  void run();
  void color_sort();
  void park();
  int getState();
  bool storage;
  Intake();

private:
  int state;
};
} // namespace Robot