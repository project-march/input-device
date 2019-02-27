#ifndef Scroller_h
#define Scroller_h

#include <Arduino.h>

class Scroller {
 public:
  Scroller(int pin_A, int pin_B);
  int get_position();

 private:
  String last_position;
  bool last_press;

  int A_pin;
  int B_pin;
};

#endif