#ifndef INPUT_DEVICE_STATE_MACHINE_H
#define INPUT_DEVICE_STATE_MACHINE_H
#include "SD_sector_addresses.h"
#include "state.h"

#include <Arduino.h>

#include <string>
#include <vector>

class StateMachine {
public:
  StateMachine() = default;

  const std::string& getCurrentGaitName() const;

  void getCurrentImage(word& address_hi, word& address_lo) const;

  bool left();
  bool right();
  bool up();
  bool down();

  bool back();
  bool select();
  bool activate();

private:
  bool setCurrentState(State* new_state);

  std::vector<State> states_;
  State* current_state_ = nullptr;
};

#endif // INPUT_DEVICE_STATE_MACHINE_H
