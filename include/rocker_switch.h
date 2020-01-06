#ifndef ROCKER_SWITCH_H
#define ROCKER_SWITCH_H
#include "rocker_switch_state.h"

#include <Arduino.h>

class RockerSwitch
{
public:
  explicit RockerSwitch(uint8_t up_pin, uint8_t down_pin);

  RockerSwitchState getState();

private:
  const uint8_t up_pin_;
  const uint8_t down_pin_;
  RockerSwitchState last_position_ = RockerSwitchState::NEUTRAL;
  unsigned long last_print_time_ = 0;

  // Microseconds. May introduce unwanted behaviour if changed
  const useconds_t bounce_time_ = 20000;

  // Milliseconds. Determines how often up or down are returned if the rocker
  // switch is held up or down.
  const unsigned long hold_time_ = 1000;
};

#endif  // ROCKER_SWITCH_H
