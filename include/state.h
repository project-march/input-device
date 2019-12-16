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

  State* left() const { return this->left_; }
  State* right() const { return this->right_; }
  State* up() const { return this->up_; }
  State* down() const { return this->down_; }

  State* back() const { return this->back_; }
  State* select() const { return this->select_; }
  State* activate() const { return this->activate_; }

private:
  std::string gait_;
  const word image_address_hi_;
  const word image_address_lo_;

  State* left_ = nullptr;
  State* right_ = nullptr;
  State* up_ = nullptr;
  State* down_ = nullptr;

  State* back_ = nullptr;
  State* select_ = nullptr;
  State* activate_ = nullptr;
};

#endif // STATE_H
