#include "rocker_switch.h"

RockerSwitch::RockerSwitch(uint8_t up_pin, uint8_t down_pin) : up_pin_(up_pin), down_pin_(down_pin)
{
  pinMode(up_pin, INPUT_PULLUP);
  pinMode(down_pin, INPUT_PULLUP);
}

RockerSwitchState RockerSwitch::getState()
{
  RockerSwitchState state;
  if (digitalRead(this->up_pin_) == LOW)
  {
    if (this->last_position_ != RockerSwitchState::UP || (millis() - this->last_print_time_) > this->hold_time_)
    {
      // reset lastPrintTime
      this->last_print_time_ = millis();
      this->last_position_ = RockerSwitchState::UP;
      state = RockerSwitchState::UP;
    }
    else
    {
      state = RockerSwitchState::HOLDING_UP;
    }
  }
  else if (digitalRead(this->down_pin_) == LOW)
  {
    if (this->last_position_ != RockerSwitchState::DOWN || (millis() - this->last_print_time_) > this->hold_time_)
    {
      // reset lastPrintTime
      this->last_print_time_ = millis();
      this->last_position_ = RockerSwitchState::DOWN;
      state = RockerSwitchState::DOWN;
    }
    else
    {
      state = RockerSwitchState::HOLDING_DOWN;
    }
  }
  else
  {
    this->last_position_ = RockerSwitchState::NEUTRAL;
    state = RockerSwitchState::NEUTRAL;
  }
  // To prevent multiple 'up's and 'down's per press due to bouncing
  usleep(this->bounce_time_);
  return state;
}
