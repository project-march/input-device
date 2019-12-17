#ifndef STATE_H
#define STATE_H
#include "sd_sector_addresses.h"

#include <string>

class State {
public:
  State(SectorAddress address, const std::string& gait)
      : gait_(gait), address_(address) {}

  State(SectorAddress address) : State(address, "") {}

  const std::string& getGaitName() const { return this->gait_; }

  void getImage(SectorAddress& image_address) const {
    image_address = this->address_;
  };

  const State* left() const { return this->left_; }
  const State* right() const { return this->right_; }
  const State* up() const { return this->up_; }
  const State* down() const { return this->down_; }

  const State* back() const { return this->back_; }
  const State* select() const { return this->select_; }
  const State* activate() const { return this->activate_; }

  State& withLeft(State* left) {
    this->left_ = left;
    left->right_ = this;
    return *this;
  }

  State& withRight(State* right) {
    this->right_ = right;
    right->left_ = this;
    return *this;
  }

  State& withUp(State* up) {
    this->up_ = up;
    up->down_ = this;
    return *this;
  }

  State& withDown(State* down) {
    this->down_ = down;
    down->up_ = this;
    return *this;
  }

  State& withBack(State* back) {
    this->back_ = back;
    back->select_ = this;
    return *this;
  }

  State& backFrom(State* from) {
    from->back_ = this;
    return *this;
  }

  State& withSelect(State* select) {
    this->select_ = select;
    select->back_ = this;
    return *this;
  }

  State& withActivate(State* activate) {
    this->activate_ = activate;
    return *this;
  }

private:
  const std::string gait_;
  const SectorAddress address_;

  const State* left_ = this;
  const State* right_ = this;
  const State* up_ = this;
  const State* down_ = this;

  const State* back_ = this;
  const State* select_ = this;
  const State* activate_ = this;
};

#endif // STATE_H
