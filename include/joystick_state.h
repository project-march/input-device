#ifndef JOYSTICK_STATE_H
#define JOYSTICK_STATE_H

enum class JoystickState
{
  LEFT,
  RIGHT,
  UP,
  DOWN,
  NEUTRAL,
  // It is advised to treat HOLDING the same as NEUTRAL
  // as it is only used internally.
  HOLDING,
};

#endif  // JOYSTICK_STATE_H
