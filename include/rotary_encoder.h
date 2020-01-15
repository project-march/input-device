#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include "button_state.h"
#include "rotary_encoder_rotation.h"

#include <Arduino.h>

class RotaryEncoder
{
public:
  RotaryEncoder(uint8_t a_pin, uint8_t b_pin, uint8_t press_pin);
  RotaryEncoderRotation getRotation();
  ButtonState getButtonState();

private:
  const uint8_t a_pin_;
  const uint8_t b_pin_;
  const uint8_t press_pin_;

  bool last_value_a, last_value_b;
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

#endif  //  ROTARY_ENCODER_H
