#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button {
 public:
  Button(int pin);
  String read_state();

 private:
  int input_pin;
  String lastPosition;
  unsigned long lastPrintTime;
  const unsigned int bounceTime = 20000; //us. May introduce unwanted behaviour if changed
  const unsigned int holdTime = 1000; //ms. Determines how often 'push' is returned if the button is held
};

#endif