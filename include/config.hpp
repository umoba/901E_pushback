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
  }
}