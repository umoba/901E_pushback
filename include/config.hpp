#include "lemlib/api.hpp" // IWYU pragma: keep


namespace Robot {
  namespace Config {
    struct color {
      static constexpr int RED = 210;
      static constexpr int BLUE = 30;
    };
    extern color colors;

    struct prematch {
      bool inAuton = false;
      bool allianceIsRed = false;
      bool skillsMode = false;
    };
    extern prematch prematches;

    // RPM values for intakes
    struct rpm {
      static constexpr int MAX_11V_RPM = 600;
      static constexpr int HALF_11V_RPM = 300;
      static constexpr int MID_11V_RPM = 0;
    };
    extern rpm rpms;

    struct port {
      // Left Chassis
      static constexpr int LEFT_FRONT_PORT = 0;
      static constexpr int LEFT_MID_PORT = 0;
      static constexpr int LEFT_BACK_PORT = 0;

      // Right Chassis
      static constexpr int RIGHT_FRONT_PORT = 0;
      static constexpr int RIGHT_MID_PORT = 0;
      static constexpr int RIGHT_BACK_PORT = 0;

      // Intakes
      static constexpr int LEFT_INTAKE_PORT = 0;
      static constexpr int RIGHT_INTAKE_PORT = 0;

      // Distance Sensors
      static constexpr int BACK_DIST_PORT = 0;
      static constexpr int LEFT_DIST_PORT = 0;
      static constexpr int RIGHT_DIST_PORT = 0;
      static constexpr int FRONT_DIST_PORT = 0;
      static constexpr int TONGUE_DIST_PORT = 0;
      // Color Sensors
      static constexpr int COLOR_PORT = 0;

      // Odometry Pod
      static constexpr int VERTICAL_ENCODER_PORT = 0;

      // IMU 
      static constexpr int IMU_PORT = 0;

      // Pneumatics
      static constexpr char TONGUE_PORT = 'A';
      static constexpr char WING_PORT = 'B';
      static constexpr char DOUBLE_PARKING_PORT = 'C';
      static constexpr char MIDGOAL_PORT = 'D';



    };
    extern port ports;

    struct lemlibConst {
      // Chassis Constants
      static constexpr int DRIVETRAIN_RPM = 450;
      static constexpr float TRACK_WIDTH_INCHES = 13.625;
      static constexpr float WHEEL_BASE_INCHES = 6.8125;
      static constexpr float HORIZONTAL_DRIFT = 8;
      static constexpr float WHEEL_DIAMETER_INCHES = lemlib::Omniwheel::NEW_325;


      // Odometry Offest
      static constexpr float VERTICAL_WHEEL_OFFSET_INCHES = 6.5;
      static constexpr float HORIZONTAL_WHEEL_OFFSET_INCHES = 0;

      // PID Constants
      // Lateral
      static constexpr double LATERAL_KP = 9;
      static constexpr double LATERAL_KI = 5.8;
      static constexpr double LATERAL_KD = 82;
      static constexpr double LATERAL_ANTI_WINDUP = -3;
      static constexpr double LATERAL_SLEW = 0;

      // Angular
      static constexpr double ANGULAR_KP = 9;
      static constexpr double ANGULAR_KI = 3;
      static constexpr double ANGULAR_KD = 74;
      static constexpr double ANGULAR_ANTI_WINDUP = -3.5;
      static constexpr double ANGULAR_SLEW = 0;
           
    };
    extern lemlibConst lemlibconsts;
  }
}