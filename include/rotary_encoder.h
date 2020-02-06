#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include "rotary_encoder_rotation.h"

#include <Arduino.h>

class RotaryEncoder
{
public:
  RotaryEncoder(uint8_t a_pin, uint8_t b_pin);
  RotaryEncoderRotation getRotation(int * increment_ptr);

private:
  const uint8_t a_pin_;
  const uint8_t b_pin_;

  int debounceCounter;
};

#endif  //  ROTARY_ENCODER_H
