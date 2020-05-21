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

  explicit State(SectorAddress address) : State(address, "")
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
  const State* shortcutPush() const
  {
    return this->shortcut_push_;
  }
  const State* shortcutDoublePush() const
  {
    return this->shortcut_double_push_;
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

  State& shortcutPushTo(const State* shortcut_push)
  {
    this->shortcut_push_ = shortcut_push;
    return *this;
  }

  State& shortcutDoublePushTo(const State* shortcut_double_push)
  {
    this->shortcut_double_push_ = shortcut_double_push;
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

  State& selectTo(const State* select)
  {
    this->select_ = select;
    return *this;
  }

  State& withActivate(const State* activate)
  {
    this->activate_ = activate;
    return *this;
  }

private:
  const std::string gait_;
  const SectorAddress address_;

  const State* left_ = this;
  const State* right_ = this;
  const State* shortcut_push_ = this;
  const State* shortcut_double_push_ = this;

  const State* back_ = this;
  const State* select_ = this;
  const State* activate_ = this;
};

#endif  // STATE_H
