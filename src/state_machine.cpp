#include "state_machine.h"
#include "sd_sector_addresses.h"

void StateMachine::construct() {
  this->states_.emplace_back(HomeSitStart_Hi, HomeSitStart_Lo);

  this->current_state_ = &this->states_[0];
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
