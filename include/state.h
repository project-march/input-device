#ifndef STATE_H
#define STATE_H
#include <string>

class State {
public:
  State(const unsigned int address_hi, const unsigned int address_lo,
        const std::string& gait)
      : gait_(gait), image_address_hi_(address_hi),
        image_address_lo_(address_lo) {}

  State(const unsigned int address_hi, const unsigned int address_lo)
      : State(address_hi, address_lo, "") {}

  const std::string& getGaitName() const { return this->gait_; }

  void getImage(unsigned int& image_address_hi,
                unsigned int& image_address_lo) const {
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
  const unsigned int image_address_hi_;
  const unsigned int image_address_lo_;

  const State* left_ = this;
  const State* right_ = this;
  const State* up_ = this;
  const State* down_ = this;

  const State* back_ = this;
  const State* select_ = this;
  const State* activate_ = this;
};

#endif // STATE_H
