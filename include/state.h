#ifndef STATE_H
#define STATE_H
#include <Arduino.h>

#include <string>

class State {
public:
  State(const word address_hi, const word address_lo, const std::string& gait)
      : gait_(gait), image_address_hi_(address_hi),
        image_address_lo_(address_lo), left_(this), right_(this), up_(this),
        down_(this) {}

  State(const word address_hi, const word address_lo)
      : State(address_hi, address_lo, "") {}

  const std::string& getGaitName() const { return this->gait_; }

  void getImage(word& image_address_hi, word& image_address_lo) const {
    image_address_hi = this->image_address_hi_;
    image_address_lo = this->image_address_lo_;
  };

  const State* left() const { return this->left_; }
  const State* right() const { return this->right_; }
  const State* up() const { return this->up_; }
  const State* down() const { return this->down_; }

  const State* back() const { return this->back_; }
  const State* select() const { return this->select_; }
  const State* activate() const { return this->activate_; }

private:
  const std::string gait_;
  const word image_address_hi_;
  const word image_address_lo_;

  const State* left_ = nullptr;
  const State* right_ = nullptr;
  const State* up_ = nullptr;
  const State* down_ = nullptr;

  const State* back_ = nullptr;
  const State* select_ = nullptr;
  const State* activate_ = nullptr;
};

#endif // STATE_H
