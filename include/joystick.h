#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "button_state.h"
#include "joystick_position.h"

#include <Arduino.h>

class Joystick {
public:
  explicit Joystick(uint8_t left_pin, uint8_t right_pin, uint8_t up_pin,
                    uint8_t down_pin, uint8_t press_pin);

  JoystickPosition getPosition();
  ButtonState getState();

private:
  const uint8_t left_pin_;
  const uint8_t right_pin_;
  const uint8_t up_pin_;
  const uint8_t down_pin_;
  const uint8_t press_pin_;

  JoystickPosition last_position_ = JoystickPosition::NEUTRAL;
  ButtonState last_push_position_ = ButtonState::NEUTRAL;
  unsigned long last_print_time_ = 0;
  unsigned long last_push_print_time_ = 0;
  bool recent_initial_click_ = false;
  bool recent_double_click_ = false;
  bool last_push_ = false;
  unsigned long last_push_release_time_ = 0;
  unsigned long last_double_click_time_ = 0;

  // us. May introduce unwanted behaviour if changed
  const useconds_t bounce_time_ = 5000;

  // ms. Determines how often up or down
  // are returned if the joystick is held.
  const unsigned long hold_time_ = 1000;

  const unsigned long double_click_time_ = 300;         // ms.
  const unsigned long double_click_timeout_time_ = 500; // ms
};

#endif // JOYSTICK_H
