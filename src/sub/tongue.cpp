#include "main.h"// IWYU pragma: keep
#include "globals.h"// IWYU pragma: keep
#include "subs_headers/tongue.h"
#include "subs_headers/intakes.h"
#include "pros/misc.h"
using namespace Robot;
using namespace Robot::Globals;

Tongue::Tongue() {}

void Tongue::run() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
    tonguemech.toggle();
    if (tonguemech.is_extended() && sprocketIntake.get_target_velocity() != 0) {
      sprocketIntake.move_velocity(subsystem.intake.MAX_55_VELOCITY);
    }
  }
}