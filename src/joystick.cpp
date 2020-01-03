#include "joystick.h"

Joystick::Joystick(uint8_t left_pin, uint8_t right_pin, uint8_t up_pin, uint8_t down_pin, uint8_t press_pin)
  : left_pin_(left_pin), right_pin_(right_pin), up_pin_(up_pin), down_pin_(down_pin), press_pin_(press_pin)
{
  pinMode(left_pin, INPUT_PULLUP);
  pinMode(right_pin, INPUT_PULLUP);
  pinMode(up_pin, INPUT_PULLUP);
  pinMode(down_pin, INPUT_PULLUP);
  pinMode(press_pin, INPUT_PULLUP);
}

JoystickPosition Joystick::getPosition()
{
  JoystickPosition position;
  if (digitalRead(this->left_pin_) == LOW)
  {
    if (this->last_position_ != JoystickPosition::LEFT || (millis() - this->last_print_time_) > this->hold_time_)
    {
      position = JoystickPosition::LEFT;
      this->last_print_time_ = millis();
      this->last_position_ = JoystickPosition::LEFT;
    }
    else
    {
      position = JoystickPosition::HOLDING;
    }
  }
  else if (digitalRead(this->right_pin_) == LOW)
  {
    if (this->last_position_ != JoystickPosition::RIGHT || (millis() - this->last_print_time_) > this->hold_time_)
    {
      position = JoystickPosition::RIGHT;
      this->last_print_time_ = millis();
      this->last_position_ = JoystickPosition::RIGHT;
    }
    else
    {
      position = JoystickPosition::HOLDING;
    }
  }
  else if (digitalRead(this->up_pin_) == LOW)
  {
    if (this->last_position_ != JoystickPosition::UP || (millis() - this->last_print_time_) > this->hold_time_)
    {
      position = JoystickPosition::UP;
      this->last_print_time_ = millis();
      this->last_position_ = JoystickPosition::UP;
    }
    else
    {
      position = JoystickPosition::HOLDING;
    }
  }
  else if (digitalRead(this->down_pin_) == LOW)
  {
    if (this->last_position_ != JoystickPosition::DOWN || (millis() - this->last_print_time_) > this->hold_time_)
    {
      position = JoystickPosition::DOWN;
      this->last_print_time_ = millis();
      this->last_position_ = JoystickPosition::DOWN;
    }
    else
    {
      position = JoystickPosition::HOLDING;
    }
  }
  else
  {
    position = JoystickPosition::NEUTRAL;
    this->last_position_ = JoystickPosition::NEUTRAL;
  }
  // To prevent multiple prints per action due to bouncing
  usleep(this->bounce_time_);
  return position;
}

ButtonState Joystick::getState()
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
    {  // Joystick is pressed
      this->last_push_ = true;
      state = ButtonState::DOUBLE;  // A second click, so publish the double click
      this->recent_initial_click_ = false;
      this->recent_double_click_ = true;
      this->last_double_click_time_ = millis();
    }
    else
    {  // Joystick not pressed, not just released and recent enough
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
