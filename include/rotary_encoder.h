#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include "rotary_encoder_rotation.h"

#include <Arduino.h>

class RotaryEncoder
{
public:
  RotaryEncoder(uint8_t a_pin, uint8_t b_pin);
  RotaryEncoderRotation getRotation();

private:
  const uint8_t a_pin_;
  const uint8_t b_pin_;

  RotaryEncoderRotation last_rotation;

  bool last_value_a, last_value_b;
  int8_t increment_counter;
  
  unsigned long last_print_time_ = 0;

  // Microseconds. May introduce unwanted behaviour if changed
  const useconds_t bounce_time_ = 5000;

  // Milliseconds. Determines how often increment or decrement
  // are returned if the encoder is scrolled.
  const unsigned long hold_time_ = 1000;
};

#endif  //  ROTARY_ENCODER_H
