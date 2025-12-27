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

        // FIELD DIMENSIONS
    constexpr double FIELD_HALF_IN = 72.0;
    constexpr double TILE_IN = 24.0;

    // DIRECTION
    bool POS_Y_HEADING_0 = true;

    // DISTANCE SENSOR OFFSETS
    // Robot frame: +X right, +Y forward
    constexpr double LEFT_DIST_X_IN = 7.5;
    constexpr double LEFT_DIST_Y_IN = 0.0;

    constexpr double RIGHT_DIST_X_IN = -7.5;
    constexpr double RIGHT_DIST_Y_IN = 0.0;

    constexpr double BACK_DIST_X_IN = -7.5;
    constexpr double BACK_DIST_Y_IN = -0.5;

    // SKILLS DISTANCE SENSOR CONFIGS
    constexpr double SKILLS_WALL_CLEARANCE_IN = 8.0;  // desired stop distance
    constexpr double DIST_CAPTURE_MARGIN_IN   = 20.0; // when to switch to PD
    constexpr double DIST_STOP_TOL_IN         = 0.75; // settle tolerance
    constexpr int    DIST_SETTLE_CYCLES       = 5;
    constexpr int    DIST_TIMEOUT_MS          = 1500;

    // Gains (starting points; tune)
    constexpr double DIST_KP = 700.0;
    constexpr double DIST_KD = 120.0;
    constexpr double LANE_KX = 120.0;

  }
}