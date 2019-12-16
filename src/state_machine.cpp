#include "state_machine.h"
#include "sd_sector_addresses.h"

void StateMachine::construct() {
  State& home_sit_start = this->createState(HomeSitStart_Hi, HomeSitStart_Lo);
  State& home_sit_start_activated = this->createState(
      HomeSitStartActivated_Hi, HomeSitStartActivated_Lo, "home_sit");
  State& home_sit_start_selected =
      this->createState(HomeSitStartSelected_Hi, HomeSitStartSelected_Lo)
          .withBack(&home_sit_start)
          .withActivate(&home_sit_start_activated);

  State& stand_up =
      this->createState(StandUp_Hi, StandUp_Lo).withLeft(&home_sit_start);
  State& stand_up_activated =
      this->createState(StandUpActivated_Hi, StandUpActivated_Lo, "gait_sit");
  State& stand_up_selected =
      this->createState(StandUpSelected_Hi, StandUpSelected_Lo)
          .withBack(&stand_up)
          .withActivate(&stand_up_activated);

  State& home_stand_start =
      this->createState(HomeStandStart_Hi, HomeStandStart_Lo)
          .withLeft(&stand_up);
  State& home_stand_activated = this->createState(
      HomeStandActivated_Hi, HomeStandActivated_Lo, "home_stand");
  State& home_stand_selected =
      this->createState(HomeStandSelected_Hi, HomeStandSelected_Lo)
          .withBack(&home_stand_start)
          .withActivate(&home_stand_activated);
  State& power_off = this->createState(TurnOff_Hi, TurnOff_Lo)
                         .withLeft(&home_stand_start)
                         .withRight(&home_sit_start);

  this->current_state_ = &this->states_.front();
}

std::string StateMachine::getCurrentGaitName() const {
  if (this->hasState()) {
    return this->current_state_->getGaitName();
  }
  return std::string();
}

void StateMachine::getCurrentImage(unsigned int& address_hi,
                                   unsigned int& address_lo) const {
  if (this->hasState()) {
    this->current_state_->getImage(address_hi, address_lo);
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

State& StateMachine::createState(const unsigned int address_hi,
                                 const unsigned int address_lo,
                                 const std::string& gait_name) {
  this->states_.emplace_back(address_hi, address_lo, gait_name);
  return this->states_.back();
}