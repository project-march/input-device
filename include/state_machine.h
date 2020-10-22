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

  bool back();
  bool select();
  bool activate();

private:
  using state_iterator = std::list<State>::iterator;

  void constructObstacleMenu(State* from);
  void constructWalkMenu(state_iterator list_end, State* obstacles);
  void constructSofaMenu(State* from, State* next_obstacle);
  void constructSlalomMenu(State* from, State* next_obstacle);
  void constructRoughTerrainMenu(State* from, State* next_obstacle);
  void constructStairsMenu(State* from, State* next_obstacle);
  void constructTiltedPathMenu(State* from, State* next_obstacle);
  void constructSlopeMenu(State* from, State* next_obstacle);
  void setEscapeStatesBackTo(const State* previous_state);

  bool hasState() const;
  bool setCurrentState(const State* new_state);

  State& createState(const SectorAddress address, const std::string& gait_name = "");

  State& createGaitState(const SectorAddress addr, const SectorAddress addr_selected,
                         const SectorAddress addr_activated, const std::string& gait_name,
                         const State* result = nullptr);

  /**
   * Creates a gait state where activation directly goes to selected again, so shorter.
   */
  State& createGaitStateToSelect(const SectorAddress addr, const SectorAddress addr_selected,
                                 const SectorAddress addr_activated, const std::string& gait_name);

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
  const State* previous_state_ = nullptr;

  bool in_escape_menu_ = false;
};

#endif  // STATE_MACHINE_H
