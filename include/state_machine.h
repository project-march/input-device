#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "state.h"

#include <list>
#include <string>

class StateMachine
{
public:
  StateMachine() = default;

  void construct();

  std::string getCurrentGaitName() const;
  SectorAddress getCurrentImage() const;

  size_t size() const;

  bool left();
  bool right();
  bool shortcutPush();
  bool shortcutDoublePush();

  bool back();
  bool select();
  bool activate();

private:
  void constructObstacleMenu(State* from);
  void constructWalkMenu(std::list<State>::iterator lastState);
  void constructStepMenu(std::list<State>::iterator lastState);
  void constructSofaMenu(State* from, State* next_obstacle);
  void constructStairsMenu(State* from, State* next_obstacle);
  void setEscapeStatesBackTo(const State* previous_state);

  bool hasState() const;
  bool setCurrentState(const State* new_state);

  State& createState(const SectorAddress address, const std::string& gait_name = "");

  State& createGaitState(const SectorAddress addr, const SectorAddress addr_selected,
                         const SectorAddress addr_activated, const std::string& gait_name,
                         const State* result = nullptr);

  State& createEscapeState(const SectorAddress address, const std::string& gait_name = "");

  State& createEscapeGaitState(const SectorAddress addr, const SectorAddress addr_selected,
                           const SectorAddress addr_activated, const std::string& gait_name,
                           const State* result = nullptr);

  // This must be list, since that does not reallocate
  // Items when it resizes, which a vector does.
  // Otherwise all pointers in states would become invalid :)
  std::list<State> states_;
  std::list<State> escape_states_;
  const State* current_state_ = nullptr;
};

#endif  // STATE_MACHINE_H
