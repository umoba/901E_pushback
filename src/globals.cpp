#include "globals.h"// IWYU pragma: keep
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "config.hpp"
using namespace Robot::Config;

namespace Robot {
  
  namespace Globals {
    // Subsystems
    RobotSubsystems subsystem;

    // Autonsystem
    AutonSystem autonSystem;

    // Controller
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    // Chassis motors
    pros::MotorGroup right({ports.RIGHT_BACK_PORT, ports.RIGHT_MID_PORT, ports.RIGHT_FRONT_PORT},pros::MotorGearset::blue);
    pros::MotorGroup left({ports.LEFT_BACK_PORT, ports.LEFT_MID_PORT, ports.LEFT_FRONT_PORT},pros::MotorGearset::blue);
    
    // Intake motors
    pros::MotorGroup wholeIntake({ports.LEFT_INTAKE_PORT, ports.RIGHT_INTAKE_PORT}, pros::MotorGearset::blue);
    pros::Motor topIntake(-14, pros::MotorGearset::green);
    pros::Motor flexIntake(2, pros::MotorGearset::green);
    pros::Motor sprocketIntake(21, pros::MotorGearset::blue);


    // Rotational
    pros::Rotation autonSelector(5);

    // Optical
    pros::Optical coloring(ports.COLOR_PORT);

    // // Distance
    pros::Distance backD(ports.BACK_DIST_PORT);
    pros::Distance leftD(ports.LEFT_DIST_PORT);
    pros::Distance rightD(ports.RIGHT_DIST_PORT);
    pros::Distance frontD(ports.FRONT_DIST_PORT);
    pros::Distance tongueD(ports.TONGUE_DIST_PORT);
    
    // Pneumatics
    pros::adi::Pneumatics  tonguemech(ports.TONGUE_PORT, false);
    pros::adi::Pneumatics  wing(ports.WING_PORT, false);
    pros::adi::Pneumatics  doubleParking(ports.DOUBLE_PARKING_PORT, false);
    pros::adi::Pneumatics  midGoal(ports.MIDGOAL_PORT, true);  

    // IMU
    pros::Imu imu(ports.IMU_PORT);


    // Odometry wheels
    // horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
    // pros::Rotation horizontalEnc(-11);
    // vertical tracking wheel encoder. Rotation sensor, port 11, reversed
    pros::Rotation verticalEnc(ports.VERTICAL_ENCODER_PORT);


    // lemlib

    // horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
    // lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -1.375);
    // vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
    lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_2, lemlibconsts.VERTICAL_WHEEL_OFFSET_INCHES);
// 13.125
   
    // drivetrain settings
    lemlib::Drivetrain drivetrain(&left, // left motor group
      &right, // right motor group
      lemlibconsts.TRACK_WIDTH_INCHES, // 10.75 inch track width
      lemlibconsts.WHEEL_DIAMETER_INCHES, // using new 3.25" omnis
      lemlibconsts.DRIVETRAIN_RPM, // drivetrain rpm is 360
      lemlibconsts.HORIZONTAL_DRIFT // horizontal drift is 2. If we had traction wheels, it would have been 8
    );

    // lateral PID controller
    lemlib::ControllerSettings lateral_controller(lemlibconsts.LATERAL_KP, // proportional gain (kP)
                                                lemlibconsts.LATERAL_KI, // integral gain (kI)
                                                lemlibconsts.LATERAL_KD, // derivative gain (kD)
                                                lemlibconsts.LATERAL_ANTI_WINDUP, // anti windup
                                                0, // small error range, in inches
                                                0, // small error range timeout, in milliseconds
                                                0, // large error range, in inches
                                                0, // large error range timeout, in milliseconds
                                                lemlibconsts.LATERAL_SLEW // maximum acceleration (slew)
    );

    // angular PID controller
    lemlib::ControllerSettings angular_controller(lemlibconsts.ANGULAR_KP, // proportional gain (kP)
                                                lemlibconsts.ANGULAR_KI, // integral gain (kI)
                                                lemlibconsts.ANGULAR_KD, // derivative gain (kD)
                                                lemlibconsts.ANGULAR_ANTI_WINDUP, // anti windup
                                                0, // small error range, in inches
                                                0, // small error range timeout, in milliseconds
                                                0, // large error range, in inches
                                                0, // large error range timeout, in milliseconds
                                                lemlibconsts.ANGULAR_SLEW // maximum acceleration (slew)
    );

    // sensors for odometry
    lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
        nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
        nullptr, // horizontal tracking wheel
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &imu // inertial sensor
    );

    // input curve for throttle input during driver control
    lemlib::ExpoDriveCurve throttleCurve(5, // joystick deadband out of 127
                12, // minimum output where drivetrain will move out of 127
                1.5 // expo curve gain
    );

    // input curve for steer input during driver control
    lemlib::ExpoDriveCurve steerCurve(5, // joystick deadband out of 127
              12, // minimum output where drivetrain will move out of 127
              1.5 // expo curve gain
    );

    // create the chassis
    lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttleCurve, &steerCurve);



  }
}
  