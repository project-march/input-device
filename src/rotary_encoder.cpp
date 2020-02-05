#include "rotary_encoder.h"

RotaryEncoder::RotaryEncoder(uint8_t a_pin, uint8_t b_pin)
  : a_pin_(a_pin), b_pin_(b_pin)
{

}

RotaryEncoderRotation RotaryEncoder::getRotation(bool * a_pin_changed, bool * b_pin_changed)
{
  RotaryEncoderRotation rotation;

  if(digitalRead(this->a_pin_) == HIGH && digitalRead(this->b_pin_) == HIGH)
  {
    if(*a_pin_changed)
    {
      rotation = RotaryEncoderRotation::INCREMENT;
      *a_pin_changed = false;
    }
    else if(*b_pin_changed)
    {
      rotation = RotaryEncoderRotation::DECREMENT;
      *b_pin_changed = false;
    }
    else
    {
      rotation = RotaryEncoderRotation::NEUTRAL;
    }
  }
  
  return rotation;
}
