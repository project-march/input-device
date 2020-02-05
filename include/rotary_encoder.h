#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include "rotary_encoder_rotation.h"

#include <Arduino.h>

class RotaryEncoder
{
public:
  RotaryEncoder(uint8_t a_pin, uint8_t b_pin);
  RotaryEncoderRotation getRotation(bool * a_pin_changed, bool * b_pin_changed);

private:
  const uint8_t a_pin_;
  const uint8_t b_pin_;
};

#endif  //  ROTARY_ENCODER_H
