#ifndef BUTTON_H
#define BUTTON_H
#include "button_state.h"

#include <Arduino.h>

class Button
{
public:
  explicit Button(uint8_t pin);

  ButtonState getState();

private:
  const uint8_t input_pin_;
  ButtonState last_position_ = ButtonState::NEUTRAL;
  uint64_t last_print_time_ = 0;

  // Microseconds. May introduce unwanted behaviour if changed
  const useconds_t bounce_time_ = 20000;
  // Milliseconds. Determines how often 'push' is returned if the button is held
  const uint64_t hold_time_ = 1000;
};

#endif  // BUTTON_H
