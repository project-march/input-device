#ifndef STATE_H
#define STATE_H
#include "sd_sector_addresses.h"

#include <string>

class State
{
public:
  State(SectorAddress address, const std::string& gait) : gait_(gait), address_(address)
  {
  }

  State(SectorAddress address) : State(address, "")
  {
  }

  const std::string& getGaitName() const
  {
    return this->gait_;
  }

  SectorAddress getImage() const
  {
    return this->address_;
  };

  const State* left() const
  {
    return this->left_;
  }
  const State* right() const
  {
    return this->right_;
  }
  const State* up() const
  {
    return this->up_;
  }
  const State* down() const
  {
    return this->down_;
  }

  const State* back() const
  {
    return this->back_;
  }
  const State* select() const
  {
    return this->select_;
  }
  const State* activate() const
  {
    return this->activate_;
  }

  State& withLeft(State* left)
  {
    this->left_ = left;
    left->right_ = this;
    return *this;
  }

  State& withRight(State* right)
  {
    this->right_ = right;
    right->left_ = this;
    return *this;
  }

  State& withUp(State* up)
  {
    this->up_ = up;
    up->down_ = this;
    return *this;
  }

  State& upTo(const State* up)
  {
    this->up_ = up;
    return *this;
  }

  State& withDown(State* down)
  {
    this->down_ = down;
    down->up_ = this;
    return *this;
  }

  State& downTo(const State* down)
  {
    this->down_ = down;
    return *this;
  }

  State& withBack(State* back)
  {
    this->back_ = back;
    back->select_ = this;
    return *this;
  }

  State& backTo(const State* back)
  {
    this->back_ = back;
    return *this;
  }

  State& withSelect(State* with_select)
  {
    this->select_ = with_select;
    with_select->back_ = this;
    return *this;
  }

  State& withActivate(const State* activate)
  {
    this->activate_ = activate;
    return *this;
  }

protected:
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

#endif  // STATE_H
