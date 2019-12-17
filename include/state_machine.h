#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "state.h"

#include <list>
#include <string>

class StateMachine {
public:
  StateMachine() = default;

  void construct();

  std::string getCurrentGaitName() const;

  void getCurrentImage(SectorAddress& address) const;

  size_t size() const;

  bool left();
  bool right();
  bool up();
  bool down();

  bool back();
  bool select();
  bool activate();

private:
  bool hasState() const;
  bool setCurrentState(const State* new_state);

  State& createState(const SectorAddress address,
                     const std::string& gait_name = "");

  std::list<State> states_;
  const State* current_state_ = nullptr;
};

#endif // STATE_MACHINE_H
