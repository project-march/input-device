#include "rotary_encoder.h"

RotaryEncoder::RotaryEncoder(uint8_t a_pin, uint8_t b_pin)
  : a_pin_(a_pin), b_pin_(b_pin)
{
  pinMode(a_pin, INPUT_PULLUP);
  pinMode(b_pin, INPUT_PULLUP);

  this->last_value_a = digitalRead(this->a_pin_);
  this->last_value_b = digitalRead(this->b_pin_);
  increment_counter = 0;
}

RotaryEncoderRotation RotaryEncoder::getRotation()
{
  RotaryEncoderRotation rotation;
  bool value_a, value_b;
  value_a = digitalRead(this->a_pin_);
  value_b = digitalRead(this->b_pin_);

  // Check if the encoder is rotating 
  if(last_value_a != value_a || last_value_b != value_b)
  {
    // The encoder rotates clockwise when a and b are the same and a changes first
    // or when a and b are different and b changes first,
    // otherwise the encoder rotates counter clockwise
    if(this->last_value_a ^ this->last_value_b && value_a == this->last_value_a)
    {
      increment_counter++;
    }
    else
    {
      increment_counter--;
    }
  } 
  
  // The encoder has reached the next detent after 4 increments, when a and b both are high
  if(value_a && value_b)
  {
    if(this->last_rotation != RotaryEncoderRotation::INCREMENT || 
       (millis() - this->last_print_time_) > this->hold_time_)
    {
      if(increment_counter > 3 || millis)
      {
        rotation = RotaryEncoderRotation::INCREMENT;
        this->last_print_time_ = millis();
        this->last_rotation = RotaryEncoderRotation::INCREMENT;
      }
    }
    else if(this->last_rotation != RotaryEncoderRotation::DECREMENT || 
            (millis() - this->last_print_time_) > this->hold_time_)
    {
      if(increment_counter < 3)
      {
        rotation = RotaryEncoderRotation::DECREMENT;
        this->last_print_time_ = millis();
        this->last_rotation = RotaryEncoderRotation::DECREMENT;
      }
    }
    else
    {
      rotation = RotaryEncoderRotation::NEUTRAL;
      this->last_rotation = RotaryEncoderRotation::NEUTRAL;
    }
    increment_counter = 0;
  }

  this->last_value_a = value_a;
  this->last_value_b = value_b;

  usleep(this->bounce_time_);
  return rotation;
}
