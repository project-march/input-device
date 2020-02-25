#include "double_click_button.h"

DoubleClickButton::DoubleClickButton(uint8_t pin) : input_pin_(pin)
{
  pinMode(pin, INPUT_PULLUP);
}

ButtonState DoubleClickButton::getState()
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
    if (millis() - this->last_push_release_time_ > this->double_click_time_ && digitalRead(this->input_pin_) == HIGH)
    {  // Enough time has elapsed since last
       // push release time and not pressed
      this->last_push_ = false;
      state = ButtonState::PUSH;  // No second click, so publish the single click
      this->recent_initial_click_ = false;
    }
    else if (digitalRead(this->input_pin_) == LOW)
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
    if (digitalRead(this->input_pin_) == LOW)
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
