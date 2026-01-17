#pragma once


#include "api.h" // IWYU pragma: keep
#include "autonomous_headers/distanceAlgo.hpp"
#include "filteredIMU.h"
#include "lemlib/pid.hpp"
#include "liblvgl/misc/lv_color.h" // IWYU pragma: keep
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "autonomous_headers/auton.h"
#include "autonomous_headers/autonomousRoutes.h"



namespace Robot {
  namespace Globals {

    // Subsytems
    struct RobotSubsystems {
      Robot::Intake intake;
      Robot::Tongue tongue;
    };
    extern RobotSubsystems subsystem;

    struct AutonSystem {
      Robot::Auton auton;
      Robot::AutonomousRoutes autonomousRoutes;
      Robot::distanceAlgo distanceAlgo;
    };
    extern AutonSystem autonSystem;

    // IMU
    struct alteredIMU {
      Robot::FilteredIMU imus;
    };
    extern pros::Imu imu;
    extern FilteredIMU filteredIMU;

    // Controller
    extern pros::Controller master;

    // Motors
    // Drivetrain
    extern pros::MotorGroup left;
    extern pros::MotorGroup right;

    // Intakes
    extern pros::Motor topIntake;
    extern pros::Motor sprocketIntake;
    extern pros::Motor flexIntake;


    // Rotational
    extern pros::Rotation autonSelector;

    // Optical
    extern pros::Optical coloring;

    // Distance
    extern pros::Distance back;
    extern pros::Distance leftD;
    extern pros::Distance rightD;

    // Pneumatics
    extern pros::adi::Pneumatics  tonguemech;
    extern pros::adi::Pneumatics  wing;
    extern pros::adi::Pneumatics  doubleParking;
    extern pros::adi::Pneumatics  midGoal;  


    // Odometry wheels
    extern pros::Rotation horizontalEnc; 
    extern pros::Rotation verticalEnc;

    // Lemlib
    extern lemlib::TrackingWheel horizontal;
    extern lemlib::TrackingWheel vertical;


    extern lemlib::Drivetrain drivetrain;

    extern lemlib::ControllerSettings linearController;

    extern lemlib::ControllerSettings angularController;

    extern lemlib::OdomSensors sensors;

    extern lemlib::ExpoDriveCurve throttleCurve;

    // input curve for steer input during driver control
    extern lemlib::ExpoDriveCurve steerCurve;

    // create the chassis
    extern lemlib::Chassis chassis;
    

    
  }
}