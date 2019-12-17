#include "state_machine.h"
#include "sd_sector_addresses.h"

#include <list>

void StateMachine::construct() {
  State& walk_small = this->createState(WALK_SMALL);
  State& walk_small_selected = this->createState(WALK_SMALL_SELECTED);
  State& walk_small_activated =
      this->createState(WALK_SMALL_ACTIVATED, "gait_walk_small");
  State& walk_normal = this->createState(WALK_NORMAL).withLeft(&walk_small);
  State& walk_normal_selected =
      this->createState(WALK_NORMAL_SELECTED).withLeft(&walk_small);
  State& walk_normal_activated =
      this->createState(WALK_NORMAL_ACTIVATED, "gait_walk")
          .withLeft(&walk_small);
  State& walk_large = this->createState(WALK_LARGE)
                          .withLeft(&walk_normal)
                          .withRight(&walk_small);

  State& side_step_left = this->createState(SIDE_STEP_LEFT);
  State& side_step_right = this->createState(SIDE_STEP_RIGHT)
                               .withLeft(&side_step_left)
                               .withRight(&side_step_left);

  State& side_step_left_small = this->createState(SIDE_STEP_LEFT_SMALL);
  State& side_step_left_small_selected =
      this->createState(SIDE_STEP_LEFT_SMALL_SELECTED);
  State& side_step_left_small_activated = this->createState(
      SIDE_STEP_LEFT_SMALL_ACTIVATED, "gait_side_step_left_small");

  State& side_step_left_normal = this->createState(SIDE_STEP_LEFT_NORMAL);
  State& side_step_left_normal_selected =
      this->createState(SIDE_STEP_LEFT_NORMAL_SELECTED);
  State& side_step_left_normal_activated =
      this->createState(SIDE_STEP_LEFT_NORMAL_ACTIVATED, "gait_side_step_left");

  State& side_step_right_small = this->createState(SIDE_STEP_RIGHT_SMALL);
  State& side_step_right_small_selected =
      this->createState(SIDE_STEP_RIGHT_SMALL_SELECTED);
  State& side_step_right_small_activated = this->createState(
      SIDE_STEP_RIGHT_SMALL_ACTIVATED, "gait_side_step_right_small");

  State& side_step_right_normal = this->createState(SIDE_STEP_RIGHT_NORMAL);
  State& side_step_right_normal_selected =
      this->createState(SIDE_STEP_RIGHT_NORMAL_SELECTED);
  State& side_step_right_normal_activated = this->createState(
      SIDE_STEP_RIGHT_NORMAL_ACTIVATED, "gait_side_step_right");

  State& single_step_small = this->createState(SINGLE_STEP_SMALL);
  State& single_step_small_selected =
      this->createState(SINGLE_STEP_SMALL_SELECTED);
  State& single_step_small_activated =
      this->createState(SINGLE_STEP_SMALL_ACTIVATED, "gait_single_step_normal");
  State& single_step_normal =
      this->createState(SINGLE_STEP_NORMAL).withLeft(&single_step_small);
  State& single_step_normal_selected =
      this->createState(SINGLE_STEP_NORMAL_SELECTED);
  State& single_step_normal_activated = this->createState(
      SINGLE_STEP_NORMAL_ACTIVATED, "gait_single_step_normal");
  State& single_step_large = this->createState(SINGLE_STEP_LARGE)
                                 .withLeft(&single_step_normal)
                                 .withRight(&single_step_small);

  State& walk = this->createState(WALK)
                    .withSelect(&walk_normal)
                    .backFrom(&walk_small)
                    .backFrom(&walk_large);
  State& side_step = this->createState(SIDE_STEP)
                         .withRight(&walk)
                         .withSelect(&side_step_left)
                         .backFrom(&side_step_right);
  State& single_step = this->createState(SINGLE_STEP)
                           .withLeft(&walk)
                           .withRight(&side_step)
                           .withSelect(&single_step_normal)
                           .backFrom(&single_step_small)
                           .backFrom(&single_step_large);

  State& sit = this->createState(SIT);
  State& sit_selected = this->createState(SIT_SELECTED);
  State& sit_activated = this->createState(SIT_ACTIVATED, "gait_sit");

  State& home_sit = this->createState(HOME_SIT);
  State& home_sit_selected = this->createState(HOME_SIT_SELECTED);
  State& home_sit_activated = this->createState(HOME_SIT_ACTIVATED, "home_sit");

  State& home_stand = this->createState(HOME_STAND);
  State& home_stand_selected = this->createState(HOME_STAND_SELECTED);
  State& home_stand_activated =
      this->createState(HOME_STAND_ACTIVATED, "home_stand");

  State& turn_off = this->createState(TURN_OFF);

  State& sofa_sit = this->createState(SOFA_SIT);
  State& sofa_sit_selected = this->createState(SOFA_SIT_SELECTED);
  State& sofa_sit_activated =
      this->createState(SOFA_SIT_ACTIVATED, "gait_sofa_sit");

  State& sofa_standup = this->createState(SOFA_STANDUP);
  State& sofa_standup_selected = this->createState(SOFA_STANDUP_SELECTED);
  State& sofa_standup_activated =
      this->createState(SOFA_STANDUP_ACTIVATED, "gait_sofa_stand");

  State& stairs_up = this->createState(STAIRS_UP);
  State& stairs_up_selected = this->createState(STAIRS_UP_SELECTED);
  State& stairs_up_activated =
      this->createState(STAIRS_UP_ACTIVATED, "gait_stairs_up");

  State& stairs_down = this->createState(STAIRS_DOWN);
  State& stairs_down_selected = this->createState(STAIRS_DOWN_SELECTED);
  State& stairs_down_activated =
      this->createState(STAIRS_DOWN_ACTIVATED, "gait_stairs_down");

  State& sofa = this->createState(SOFA);

  State& stairs = this->createState(STAIRS);

  State& home_sit_start = this->createState(HOME_SIT_START);
  State& home_sit_start_activated =
      this->createState(HOME_SIT_START_ACTIVATED, "home_sit");
  State& home_sit_start_selected = this->createState(HOME_SIT_START_SELECTED)
                                       .withBack(&home_sit_start)
                                       .withActivate(&home_sit_start_activated);

  State& stand_up = this->createState(STAND_UP).withLeft(&home_sit_start);
  State& stand_up_activated =
      this->createState(STAND_UP_ACTIVATED, "gait_stand").withActivate(&walk);
  State& stand_up_selected = this->createState(STAND_UP_SELECTED)
                                 .withBack(&stand_up)
                                 .withActivate(&stand_up_activated);

  State& home_stand_start =
      this->createState(HOME_STAND_START).withLeft(&stand_up);
  State& home_stand_start_activated =
      this->createState(HOME_STAND_START_ACTIVATED, "home_stand")
          .withActivate(&walk);
  State& home_stand_start_selected =
      this->createState(HOME_STAND_START_SELECTED)
          .withBack(&home_stand_start)
          .withActivate(&home_stand_start_activated);
  State& turn_off_start = this->createState(TURN_OFF_START)
                              .withLeft(&home_stand_start)
                              .withRight(&home_sit_start);

  this->current_state_ = &home_sit_start;
}

std::string StateMachine::getCurrentGaitName() const {
  if (this->hasState()) {
    return this->current_state_->getGaitName();
  }
  return std::string();
}

void StateMachine::getCurrentImage(SectorAddress& address) const {
  if (this->hasState()) {
    this->current_state_->getImage(address);
  }
}

size_t StateMachine::size() const {
  return this->states_.size();
}

bool StateMachine::left() {
  return this->hasState() &&
         this->setCurrentState(this->current_state_->left());
}

bool StateMachine::right() {
  return this->hasState() &&
         this->setCurrentState(this->current_state_->right());
}

bool StateMachine::up() {
  return this->hasState() && this->setCurrentState(this->current_state_->up());
}

bool StateMachine::down() {
  return this->hasState() &&
         this->setCurrentState(this->current_state_->down());
}

bool StateMachine::back() {
  return this->hasState() &&
         this->setCurrentState(this->current_state_->back());
}

bool StateMachine::select() {
  return this->hasState() &&
         this->setCurrentState(this->current_state_->select());
}

bool StateMachine::activate() {
  return this->hasState() &&
         this->setCurrentState(this->current_state_->activate());
}

bool StateMachine::hasState() const {
  return this->current_state_ != nullptr;
}

bool StateMachine::setCurrentState(const State* new_state) {
  bool has_changed = this->current_state_ != new_state;
  this->current_state_ = new_state;
  return has_changed;
}

State& StateMachine::createState(const SectorAddress address,
                                 const std::string& gait_name) {
  this->states_.emplace_back(address, gait_name);
  return this->states_.back();
}