#include "state_machine.h"
#include "sd_sector_addresses.h"

#include <list>

void StateMachine::construct()
{
  // Obstacle menu
  State& obstacles = this->createState(STAIRS);

  // Start menu
  State& stand_up = this->createGaitState(STAND_UP, STAND_UP_SELECTED, STAND_UP_ACTIVATED, "gait_stand", &obstacles);
  State& home_sit_start =
      this->createGaitState(HOME_SIT_START, HOME_SIT_START_SELECTED, HOME_SIT_START_ACTIVATED, "home_sit", &stand_up);
  State& home_stand_start = this->createGaitState(HOME_STAND_START, HOME_STAND_START_SELECTED,
                                                  HOME_STAND_START_ACTIVATED, "home_stand", &obstacles);
  State& turn_off_start = this->createState(TURN_OFF_START);
  State& sit_start = this->createGaitState(SIT, SIT_SELECTED, SIT_ACTIVATED, "gait_sit", &turn_off_start);

  // Sub-menus
  this->constructObstacleMenu(&obstacles);

  // Determine the state after the last added state before the walk and single step menu are added
  // This is used in constructing the walk and single step menu
  state_iterator list_end = states_.end();

  this->constructWalkMenu(list_end);
  this->constructStepMenu(list_end);

  // Menu transitions
  home_stand_start.withRight(&home_sit_start).withLeft(&turn_off_start);
  home_sit_start.withRight(&stand_up);
  stand_up.withRight(&sit_start);
  sit_start.withRight(&obstacles);

  // Set start state
  this->current_state_ = &home_sit_start;
}

void StateMachine::constructWalkMenu(state_iterator list_end)
{
  State& walk_small =
      this->createEscapeGaitState(WALK_SMALL, WALK_SMALL_SELECTED, WALK_SMALL_ACTIVATED, "gait_walk_small", nullptr);
  State& walk_normal =
      this->createEscapeGaitState(WALK_NORMAL, WALK_NORMAL_SELECTED, WALK_NORMAL_ACTIVATED, "gait_walk", nullptr);
  State& walk_large = this->createEscapeState(WALK_LARGE);

  walk_small.withRight(&walk_normal);
  walk_normal.withRight(&walk_large);
  walk_large.withRight(&walk_small);

  state_iterator states_iterator;
  for (states_iterator = this->states_.begin(); states_iterator != list_end; states_iterator++)
  {
    if (states_iterator->getGaitName().empty())
    {
      states_iterator->shortcutDoublePushTo(&walk_normal);
    }
  }
}

void StateMachine::constructStepMenu(state_iterator list_end)
{
  State& single_step_small = this->createEscapeGaitState(
      SINGLE_STEP_SMALL, SINGLE_STEP_SMALL_SELECTED, SINGLE_STEP_SMALL_ACTIVATED, "gait_single_step_normal", nullptr);
  State& single_step_normal =
      this->createEscapeGaitState(SINGLE_STEP_NORMAL, SINGLE_STEP_NORMAL_SELECTED, SINGLE_STEP_NORMAL_ACTIVATED,
                                  "gait_single_step_normal", nullptr);
  State& single_step_large = this->createEscapeState(SINGLE_STEP_LARGE);

  single_step_small.withRight(&single_step_normal);
  single_step_normal.withRight(&single_step_large);
  single_step_large.withRight(&single_step_small);

  state_iterator states_iterator;
  for (states_iterator = states_.begin(); states_iterator != list_end; states_iterator++)
  {
    if (states_iterator->getGaitName().empty())
    {
      states_iterator->shortcutPushTo(&single_step_normal);
    }
  }
}

void StateMachine::constructObstacleMenu(State* from)
{
  State& sofa = this->createState(SOFA);
  State& stairs = this->createState(STAIRS);

  this->constructSofaMenu(&sofa, &stairs);
  this->constructStairsMenu(&stairs, from);

  sofa.backTo(from).withRight(&stairs);
  stairs.backTo(from);

  from->withSelect(&sofa);
}

void StateMachine::constructSofaMenu(State* from, State* next_obstacle)
{
  State& sofa_standup = this->createGaitState(SOFA_STANDUP, SOFA_STANDUP_SELECTED, SOFA_STANDUP_ACTIVATED,
                                              "gait_sofa_stand", next_obstacle);
  State& sofa_sit =
      this->createGaitState(SOFA_SIT, SOFA_SIT_SELECTED, SOFA_SIT_ACTIVATED, "gait_sofa_sit", &sofa_standup);

  sofa_sit.backTo(from).withRight(&sofa_standup);
  sofa_standup.backTo(&sofa_sit).withRight(&sofa_sit);

  from->withSelect(&sofa_sit);
}

void StateMachine::constructStairsMenu(State* from, State* next_obstacle)
{
  State& stairs_down = this->createGaitState(STAIRS_DOWN, STAIRS_DOWN_SELECTED, STAIRS_DOWN_ACTIVATED,
                                             "gait_stairs_down", next_obstacle);
  State& stairs_up =
      this->createGaitState(STAIRS_UP, STAIRS_UP_SELECTED, STAIRS_UP_ACTIVATED, "gait_stairs_up", &stairs_down);

  stairs_up.backTo(from).withRight(&stairs_down);
  stairs_down.backTo(&stairs_up).withRight(&stairs_up);

  from->withSelect(&stairs_up);
}

void StateMachine::setEscapeStatesBackTo(const State* previous_state)
{
  for (State& escape_state : this->escape_states_)
  {
    if ((escape_state.getGaitName()).empty())
    {
      escape_state.backTo(previous_state);
    }
    else
    {
      escape_state.withActivate(previous_state);
    }
  }
}

std::string StateMachine::getCurrentGaitName() const
{
  if (this->hasState())
  {
    return this->current_state_->getGaitName();
  }
  return std::string();
}

SectorAddress StateMachine::getCurrentImage() const
{
  if (this->hasState())
  {
    return this->current_state_->getImage();
  }
  return SectorAddress{ 0, 0 };
}

size_t StateMachine::size() const
{
  return this->states_.size();
}

bool StateMachine::left()
{
  return this->hasState() && this->setCurrentState(this->current_state_->left());
}

bool StateMachine::right()
{
  return this->hasState() && this->setCurrentState(this->current_state_->right());
}

bool StateMachine::shortcutPush()
{
  this->setEscapeStatesBackTo(this->current_state_);
  return this->hasState() && this->setCurrentState(this->current_state_->shortcutPush());
}

bool StateMachine::shortcutDoublePush()
{
  this->setEscapeStatesBackTo(this->current_state_);
  return this->hasState() && this->setCurrentState(this->current_state_->shortcutDoublePush());
}

bool StateMachine::back()
{
  return this->hasState() && this->setCurrentState(this->current_state_->back());
}

bool StateMachine::select()
{
  return this->hasState() && this->setCurrentState(this->current_state_->select());
}

bool StateMachine::activate()
{
  return this->hasState() && this->setCurrentState(this->current_state_->activate());
}

bool StateMachine::hasState() const
{
  return this->current_state_ != nullptr;
}

bool StateMachine::setCurrentState(const State* new_state)
{
  bool has_changed = this->current_state_ != new_state;
  this->current_state_ = new_state;
  return has_changed;
}

State& StateMachine::createState(const SectorAddress address, const std::string& gait_name)
{
  this->states_.emplace_back(address, gait_name);
  return this->states_.back();
}

State& StateMachine::createGaitState(const SectorAddress addr, const SectorAddress addr_selected,
                                     const SectorAddress addr_activated, const std::string& gait_name,
                                     const State* result)
{
  State& normal = this->createState(addr);
  State& selected = this->createState(addr_selected);
  State& activated = this->createState(addr_activated, gait_name);

  normal.withSelect(&selected);
  selected.withActivate(&activated);
  activated.withActivate(result == nullptr ? &normal : result);

  return normal;
}

State& StateMachine::createEscapeState(const SectorAddress address, const std::string& gait_name)
{
  this->escape_states_.emplace_back(address, gait_name);
  return escape_states_.back();
}

State& StateMachine::createEscapeGaitState(const SectorAddress addr, const SectorAddress addr_selected,
                                           const SectorAddress addr_activated, const std::string& gait_name,
                                           const State* result)
{
  State& normal = this->createEscapeState(addr);
  State& selected = this->createState(addr_selected);
  State& activated = this->createEscapeState(addr_activated, gait_name);

  normal.withSelect(&selected);
  selected.withActivate(&activated);
  activated.withActivate(result == nullptr ? &normal : result);

  return normal;
}
