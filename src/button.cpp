#include "button.h"

Button::Button(uint8_t pin) : input_pin_(pin)
{
  pinMode(pin, INPUT_PULLUP);
}

ButtonState Button::getState()
{
  ButtonState state;
  if (digitalRead(this->input_pin_) == LOW)
  {
    if (this->last_position_ != ButtonState::PUSH || (millis() - this->last_print_time_) > this->hold_time_)
    {
      this->last_print_time_ = millis();
      this->last_position_ = ButtonState::PUSH;
      state = ButtonState::PUSH;
    }
    else
    {
      state = ButtonState::HOLDING;
    }
  }
  else
  {
    this->last_position_ = ButtonState::NEUTRAL;
    state = ButtonState::NEUTRAL;
  }
  // To prevent multiple 'up's and 'down's per press due to bouncing
  usleep(this->bounce_time_);
  return state;
}
