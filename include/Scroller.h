#ifndef Scroller_h
#define Scroller_h

#include <Arduino.h>

class Scroller {
 public:
  Scroller(int pin_A, int pin_B);
  int get_position();
  void reset_position();
  
 private:
  int position;
  bool last_A;

  int A_pin;
  int B_pin;
};

#endif