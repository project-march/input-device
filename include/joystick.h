#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "button_state.h"
#include "joystick_state.h"

#include <Arduino.h>

class Joystick
{
public:
  Joystick(uint8_t left_pin, uint8_t right_pin, uint8_t up_pin, uint8_t down_pin, uint8_t press_pin);

  JoystickState getState();
  ButtonState getButtonState();

private:
  const uint8_t left_pin_;
  const uint8_t right_pin_;
  const uint8_t up_pin_;
  const uint8_t down_pin_;
  const uint8_t press_pin_;

  JoystickState last_position_ = JoystickState::NEUTRAL;
  ButtonState last_push_position_ = ButtonState::NEUTRAL;
  unsigned long last_print_time_ = 0;
  unsigned long last_push_print_time_ = 0;
  bool recent_initial_click_ = false;
  bool recent_double_click_ = false;
  bool last_push_ = false;
  unsigned long last_push_release_time_ = 0;
  unsigned long last_double_click_time_ = 0;

  // Microseconds. May introduce unwanted behaviour if changed
  const useconds_t bounce_time_ = 5000;

  // Milliseconds. Determines how often up or down
  // are returned if the joystick is held.
  const unsigned long hold_time_ = 1000;

  // Milliseconds. The duration before a second press is registered
  // as a double click.
  const unsigned long double_click_time_ = 300;
  // Milliseconds. Timeout after a double click was registered
  // before other commands can be registered.
  const unsigned long double_click_timeout_time_ = 500;
};

#endif  // JOYSTICK_H
