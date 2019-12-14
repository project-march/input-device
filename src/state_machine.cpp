#include "state_machine.h"

const std::string& StateMachine::getCurrentGaitName() const {
  if (this->hasState()) {
    return this->current_state_->getGaitName();
  }
  return "";
}

void StateMachine::getCurrentImage(word& address_hi, word& address_lo) const {
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

bool StateMachine::setCurrentState(State* new_state) {
  bool has_changed = this->current_state_ != new_state;
  this->current_state_ = new_state;
  return has_changed;
}
