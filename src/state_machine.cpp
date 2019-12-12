#include "state_machine.h"

const std::string& StateMachine::getCurrentGaitName() const {
  return this->current_state_->getGaitName();
}

void StateMachine::getCurrentImage(word& address_hi, word& address_lo) const {
  this->current_state_->getImage(address_hi, address_lo);
}

bool StateMachine::left() {
  return this->setCurrentState(this->current_state_->left());
}

bool StateMachine::right() {
  return this->setCurrentState(this->current_state_->right());
}

bool StateMachine::up() {
  return this->setCurrentState(this->current_state_->up());
}

bool StateMachine::down() {
  return this->setCurrentState(this->current_state_->down());
}

bool StateMachine::back() {
  return this->setCurrentState(this->current_state_->back());
}

bool StateMachine::select() {
  return this->setCurrentState(this->current_state_->select());
}

bool StateMachine::activate() {
  return this->setCurrentState(this->current_state_->activate());
}

bool StateMachine::setCurrentState(State* new_state) {
  bool has_changed = this->current_state_ != new_state;
  this->current_state_ = new_state;
  return has_changed;
}
