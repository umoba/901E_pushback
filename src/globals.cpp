#include "globals.h"// IWYU pragma: keep
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/imu.hpp"


namespace Robot {
  
  namespace Globals {
    // Subsystems
    RobotSubsystems subsystem;

    // Autonsystem
    AutonSystem autonSystem;

    // IMU
    pros::Imu imu(12);
    // Controller
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    // Motors
    pros::MotorGroup right({16, 17, 15},pros::MotorGearset::blue);
    pros::MotorGroup left({-20, -18, -19},pros::MotorGearset::blue);
    pros::Motor topIntake(-14, pros::MotorGearset::green);
    pros::Motor flexIntake(2, pros::MotorGearset::green);
    pros::Motor sprocketIntake(21, pros::MotorGearset::blue);


    // Rotational
    pros::Rotation autonSelector(5);

    // Optical
    pros::Optical coloring(21);

    // // Distance
    pros::Distance back(22);
    pros::Distance leftD(16);
    pros::Distance rightD(17);

    // Pneumatics
    pros::adi::Pneumatics  tonguemech('A', false);
    pros::adi::Pneumatics  wing('B', false);
    pros::adi::Pneumatics  doubleParking('C', false);
    pros::adi::Pneumatics  midGoal('D', true);  

// 13.625
// 6.8125
// 6.5




    // Odometry wheels
    // horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
    // pros::Rotation horizontalEnc(-11);
    // vertical tracking wheel encoder. Rotation sensor, port 11, reversed
    pros::Rotation verticalEnc(11);


    // lemlib

    // horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
    // lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -1.375);
    // vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
    lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_2, -0.375);
// 13.125
   
    // drivetrain settings
    lemlib::Drivetrain drivetrain(&left, // left motor group
      &right, // right motor group
      10.75, // 10.75 inch track width
      lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
      450, // drivetrain rpm is 360
      8 // horizontal drift is 2. If we had traction wheels, it would have been 8
    );

    // lateral PID controller
    lemlib::ControllerSettings lateral_controller(14, // proportional gain (kP)
                                                5.5, // integral gain (kI)
                                                78, // derivative gain (kD)
                                                -3, // anti windup
                                                0, // small error range, in inches
                                                0, // small error range timeout, in milliseconds
                                                0, // large error range, in inches
                                                0, // large error range timeout, in milliseconds
                                                0 // maximum acceleration (slew)
    );

    // angular PID controller
    lemlib::ControllerSettings angular_controller(9, // proportional gain (kP)
                                                2, // integral gain (kI)
                                                65, // derivative gain (kD)
                                                -2, // anti windup
                                                0, // small error range, in inches
                                                0, // small error range timeout, in milliseconds
                                                0, // large error range, in inches
                                                0, // large error range timeout, in milliseconds
                                                0 // maximum acceleration (slew)
    );

    // sensors for odometry
    lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
        nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
        nullptr, // horizontal tracking wheel
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &imu // inertial sensor
    );

    // input curve for throttle input during driver control
    lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                10, // minimum output where drivetrain will move out of 127
                1.7 // expo curve gain
    );

    // input curve for steer input during driver control
    lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
              3, // minimum output where drivetrain will move out of 127
              1 // expo curve gain
    );

    // create the chassis
    lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttleCurve, &steerCurve);



  }
}
  