#include "state_machine.h"
#include "sd_sector_addresses.h"

#include <list>

void StateMachine::construct()
{
  // Walk menu
  State& walk = this->createState(WALK);
  State& side_step = this->createState(SIDE_STEP);
  State& single_step = this->createState(SINGLE_STEP);

  // Sit menu
  State& sit = this->createGaitState(SIT, SIT_SELECTED, SIT_ACTIVATED, "gait_sit");
  State& home_sit = this->createGaitState(HOME_SIT, HOME_SIT_SELECTED, HOME_SIT_ACTIVATED, "home_sit");
  State& home_stand = this->createGaitState(HOME_STAND, HOME_STAND_SELECTED, HOME_STAND_ACTIVATED, "home_stand");
  State& turn_off = this->createState(TURN_OFF);

  // Obstacle menu
  State& sofa = this->createState(SOFA);
  State& stairs = this->createState(STAIRS);

  // Start menu
  State& stand_up = this->createGaitState(STAND_UP, STAND_UP_SELECTED, STAND_UP_ACTIVATED, "gait_stand", &walk);
  State& home_sit_start =
      this->createGaitState(HOME_SIT_START, HOME_SIT_START_SELECTED, HOME_SIT_START_ACTIVATED, "home_sit", &stand_up);
  State& home_stand_start = this->createGaitState(HOME_STAND_START, HOME_STAND_START_SELECTED,
                                                  HOME_STAND_START_ACTIVATED, "home_stand", &walk);
  State& turn_off_start = this->createState(TURN_OFF_START);

  // Sub-menus
  this->constructWalkMenu(&walk);
  this->constructSideStepMenu(&side_step);
  this->constructStepMenu(&single_step);
  this->constructSofaMenu(&sofa);
  this->constructStairsMenu(&stairs);

  // Menu transitions
  walk.withRight(&single_step).upTo(&stairs).downTo(&sit);
  single_step.withRight(&side_step).upTo(&stairs).downTo(&sit);
  side_step.withRight(&walk).upTo(&stairs).downTo(&sit);

  sit.withRight(&home_sit).upTo(&walk);
  home_sit.withRight(&home_stand).upTo(&walk);
  home_stand.withRight(&turn_off).upTo(&walk);
  turn_off.withRight(&sit).upTo(&walk);

  sofa.withRight(&stairs).downTo(&walk);
  stairs.withRight(&sofa).downTo(&walk);

  home_sit_start.withRight(&stand_up);
  stand_up.withRight(&home_stand_start);
  home_stand_start.withRight(&turn_off_start);
  turn_off_start.withRight(&home_sit_start);

  // Set start state
  this->current_state_ = &home_sit_start;
}

void StateMachine::constructWalkMenu(State* from)
{
  State& walk_small =
      this->createGaitState(WALK_SMALL, WALK_SMALL_SELECTED, WALK_SMALL_ACTIVATED, "gait_walk_small", from);
  State& walk_normal =
      this->createGaitState(WALK_NORMAL, WALK_NORMAL_SELECTED, WALK_NORMAL_ACTIVATED, "gait_walk", from);
  State& walk_large = this->createState(WALK_LARGE);

  walk_small.backTo(from);
  walk_normal.backTo(from).withLeft(&walk_small);
  walk_large.backTo(from).withLeft(&walk_normal).withRight(&walk_small);

  from->withSelect(&walk_normal);
}

void StateMachine::constructSideStepMenu(State* from)
{
  State& side_step_left = this->createState(SIDE_STEP_LEFT);
  State& side_step_right = this->createState(SIDE_STEP_RIGHT);

  State& side_step_left_small =
      this->createGaitState(SIDE_STEP_LEFT_SMALL, SIDE_STEP_LEFT_SMALL_SELECTED, SIDE_STEP_LEFT_SMALL_ACTIVATED,
                            "gait_side_step_left_small", from);

  State& side_step_left_normal = this->createGaitState(SIDE_STEP_LEFT_NORMAL, SIDE_STEP_LEFT_NORMAL_SELECTED,
                                                       SIDE_STEP_LEFT_NORMAL_ACTIVATED, "gait_side_step_left", from);

  State& side_step_right_small =
      this->createGaitState(SIDE_STEP_RIGHT_SMALL, SIDE_STEP_RIGHT_SMALL_SELECTED, SIDE_STEP_RIGHT_SMALL_ACTIVATED,
                            "gait_side_step_right_small", from);

  State& side_step_right_normal = this->createGaitState(SIDE_STEP_RIGHT_NORMAL, SIDE_STEP_RIGHT_NORMAL_SELECTED,
                                                        SIDE_STEP_RIGHT_NORMAL_ACTIVATED, "gait_side_step_right", from);

  side_step_left.backTo(from).withRight(&side_step_right).withSelect(&side_step_left_normal);
  side_step_right.backTo(from).withRight(&side_step_left).withSelect(&side_step_right_normal);

  side_step_left_small.backTo(&side_step_left).withRight(&side_step_left_normal);
  side_step_left_normal.withRight(&side_step_left_small);

  side_step_right_small.backTo(&side_step_right).withRight(&side_step_right_normal);
  side_step_right_normal.withRight(&side_step_right_small);

  from->withSelect(&side_step_left);
}

void StateMachine::constructStepMenu(State* from)
{
  State& single_step_small = this->createGaitState(SINGLE_STEP_SMALL, SINGLE_STEP_SMALL_SELECTED,
                                                   SINGLE_STEP_SMALL_ACTIVATED, "gait_single_step_normal", from);
  State& single_step_normal = this->createGaitState(SINGLE_STEP_NORMAL, SINGLE_STEP_NORMAL_SELECTED,
                                                    SINGLE_STEP_NORMAL_ACTIVATED, "gait_single_step_normal", from);
  State& single_step_large = this->createState(SINGLE_STEP_LARGE);

  single_step_small.backTo(from).withRight(&single_step_normal);
  single_step_normal.backTo(from).withRight(&single_step_large);
  single_step_large.backTo(from).withRight(&single_step_small);

  from->withSelect(&single_step_normal);
}

void StateMachine::constructSofaMenu(State* from)
{
  State& sofa_standup =
      this->createGaitState(SOFA_STANDUP, SOFA_STANDUP_SELECTED, SOFA_STANDUP_ACTIVATED, "gait_sofa_stand", from);
  State& sofa_sit =
      this->createGaitState(SOFA_SIT, SOFA_SIT_SELECTED, SOFA_SIT_ACTIVATED, "gait_sofa_sit", &sofa_standup);

  sofa_sit.backTo(from).withRight(&sofa_standup);
  sofa_standup.backTo(from).withRight(&sofa_sit);
  from->withSelect(&sofa_sit);
}

void StateMachine::constructStairsMenu(State* from)
{
  State& stairs_up = this->createGaitState(STAIRS_UP, STAIRS_UP_SELECTED, STAIRS_UP_ACTIVATED, "gait_stairs_up", from);
  State& stairs_down =
      this->createGaitState(STAIRS_DOWN, STAIRS_DOWN_SELECTED, STAIRS_DOWN_ACTIVATED, "gait_stairs_down", from);

  stairs_up.backTo(from).withRight(&stairs_down);
  stairs_down.backTo(from).withRight(&stairs_up);
  from->withSelect(&stairs_up);
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

bool StateMachine::up()
{
  return this->hasState() && this->setCurrentState(this->current_state_->up());
}

bool StateMachine::down()
{
  return this->hasState() && this->setCurrentState(this->current_state_->down());
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
