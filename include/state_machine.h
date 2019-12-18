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
  void constructWalkMenu(State* from);
  void constructSideStepMenu(State* from);
  void constructStepMenu(State* from);

  bool hasState() const;
  bool setCurrentState(const State* new_state);

  State& createState(const SectorAddress address,
                     const std::string& gait_name = "");

  State& createGaitState(const SectorAddress addr,
                         const SectorAddress addr_selected,
                         const SectorAddress addr_activated,
                         const std::string& gait_name,
                         const State* result = nullptr);

  // This must be list, since that does not reallocate
  // Items when it resizes, which a vector does.
  // Otherwise all pointers in states would become invalid :)
  std::list<State> states_;
  const State* current_state_ = nullptr;
};

#endif // STATE_MACHINE_H
