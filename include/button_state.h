#ifndef BUTTON_STATE_H
#define BUTTON_STATE_H

enum class ButtonState
{
  NEUTRAL,
  // It is advised to treat HOLDING the same as NEUTRAL
  // as it is only used internally.
  HOLDING,
  PUSH,
  DOUBLE,
};

#endif  // BUTTON_STATE_H
