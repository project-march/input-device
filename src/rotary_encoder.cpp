#include "rotary_encoder.h"

RotaryEncoder::RotaryEncoder(uint8_t a_pin, uint8_t b_pin) : a_pin_(a_pin), b_pin_(b_pin)
{
  this->debounceCounter = 0;
}

RotaryEncoderRotation RotaryEncoder::getRotation(int* increment_ptr)
{
  RotaryEncoderRotation rotation;

  if (digitalRead(this->a_pin_) && digitalRead(this->a_pin_))
  {
    debounceCounter++;
    if (debounceCounter > 10)
    {
      switch (*increment_ptr)
      {
        case 1:
          rotation = RotaryEncoderRotation::INCREMENT;
          *increment_ptr = 0;
          break;
        case -1:
          rotation = RotaryEncoderRotation::DECREMENT;
          *increment_ptr = 0;
          break;
        case 0:
          rotation = RotaryEncoderRotation::NEUTRAL;
          break;
        default:
          rotation = RotaryEncoderRotation::NEUTRAL;
          break;
      }
    }
  }
  else
  {
    debounceCounter = 0;
  }
  return rotation;
}
