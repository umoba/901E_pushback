#pragma once

namespace Robot {

/**
 * @brief The tongue class represents a robot matchloading/tongue system.
 */
class Tongue {
public:
   /**
    * @brief Toggles the tongue pneumatics when the X button is pressed.
    * If the tongue is extended and the intake is running, the flex intake will use max velocity.
    */
   void run();
   /**
    * @brief Runs the main function of the matchloading system.
    *
    * Toggles the tongue pneumatics.
    * If the tongue is extended and the intake is running, the flex intake will use max velocity.
    */
   void toggle();

   Tongue();

};
} // namespace Robot