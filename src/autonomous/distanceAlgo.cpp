#include "globals.h"// IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "config.hpp"
#include "autonomous_headers/distanceAlgo.hpp"
using namespace Robot;
using namespace Robot::Globals;

distanceAlgo::distanceAlgo() {}
// DISTANCE SENSOR OFFSETS
// Robot frame: +X right, +Z forward
constexpr double LEFT_DIST_X_IN = 7.5;
constexpr double LEFT_DIST_Z_IN = 15.0;

constexpr double RIGHT_DIST_X_IN = -7.5;
constexpr double RIGHT_DIST_Z_IN = 9.5;

constexpr double BACK_DIST_X_IN = -7.5;
constexpr double BACK_DIST_Z_IN = 13.5;

double distanceAlgo::inchToMM(double inches) {
  return inches * 25.4;
}

double distanceAlgo::mmToInch(double mm) {
  return mm / 25.4;
}

double distanceAlgo::backDist(){
  return mmToInch (inchToMM(70.1) - (back.get_distance() + BACK_DIST_Z_IN));
}

double distanceAlgo::leftDist(){
  return mmToInch (inchToMM(70.1) - (leftD.get_distance() + LEFT_DIST_Z_IN));
}

double distanceAlgo::rightDist(){
  return mmToInch (inchToMM(70.1) - (rightD.get_distance() + RIGHT_DIST_Z_IN));
}



