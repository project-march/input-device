#include "rotary_encoder.h"

RotaryEncoder::RotaryEncoder(uint8_t a_pin, uint8_t b_pin, uint8_t press_pin)
  : a_pin_(a_pin), b_pin_(b_pin), press_pin_(press_pin)
{
  pinMode(a_pin, INPUT_PULLUP);
  pinMode(b_pin, INPUT_PULLUP);
  pinMode(press_pin, INPUT_PULLUP);

  this->last_value_a = digitalRead(this->a_pin_);
  this->last_value_b = digitalRead(this->b_pin_);
}

RotaryEncoderRotation RotaryEncoder::getRotation()
{
  RotaryEncoderRotation rotation;
  bool value_a, value_b;
  value_a = digitalRead(this->a_pin_);
  value_b = digitalRead(this->b_pin_);
  if (value_a == this->last_value_a && value_b == this->last_value_b)
  {
    rotation = RotaryEncoderRotation::NEUTRAL;
  }
  else
  {
    if(this->last_value_a ^ this->last_value_b && value_a == this->last_value_a)
    {
      rotation = RotaryEncoderRotation::CLOCKWISE;
    }
    else
    {
      rotation = RotaryEncoderRotation::COUNTER_CLOCKWISE;
    } 
  }

  this->last_value_a = value_a;
  this->last_value_b = value_b;

  usleep(this->bounce_time_);
  return rotation;
}

ButtonState RotaryEncoder::getButtonState()
{
  ButtonState state;
  if (this->recent_double_click_)
  {
    if (millis() - this->last_double_click_time_ > this->double_click_timeout_time_)
    {
      this->recent_double_click_ = false;  // Go back to an mode where we can publish stuff
    }
  }
  if (this->recent_initial_click_ && !this->recent_double_click_)
  {
    if (millis() - this->last_push_release_time_ > this->double_click_time_ && digitalRead(this->press_pin_) == HIGH)
    {  // Enough time has elapsed since last
       // push release time and not pressed
      this->last_push_ = false;
      state = ButtonState::PUSH;  // No second click, so publish the single click
      this->recent_initial_click_ = false;
    }
    else if (digitalRead(this->press_pin_) == LOW)
    {  // RE is pressed
      this->last_push_ = true;
      state = ButtonState::DOUBLE;  // A second click, so publish the double click
      this->recent_initial_click_ = false;
      this->recent_double_click_ = true;
      this->last_double_click_time_ = millis();
    }
    else
    {  // RE not pressed, not just released and recent enough
       // initial click
      this->last_push_ = false;
      state = ButtonState::NEUTRAL;
    }
  }
  else
  {  // No recent initial click or a recent double click
    if (digitalRead(this->press_pin_) == LOW)
    {  // Pressed
      this->last_push_ = true;
    }
    else
    {  // Not pressed
      if (this->last_push_)
      {  // Just released
        this->recent_initial_click_ = true;
        this->last_push_release_time_ = millis();
      }
      else
      {
        this->recent_initial_click_ = false;
      }
      this->last_push_ = false;
    }
    state = ButtonState::NEUTRAL;
  }
  // To prevent multiple prints per action due to bouncing
  usleep(this->bounce_time_);
  return state;
}
