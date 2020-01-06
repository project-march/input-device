#ifndef ROCKER_SWITCH_STATE_H
#define ROCKER_SWITCH_STATE_H

enum class RockerSwitchState
{
  NEUTRAL,
  // It is advised to treat HOLDING X the same as NEUTRAL
  // outside this function.
  HOLDING_UP,
  HOLDING_DOWN,
  UP,
  DOWN,
};

#endif  // ROCKER_SWITCH_STATE_H
