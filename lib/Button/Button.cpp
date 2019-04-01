#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) {
  pinMode(pin, INPUT_PULLDOWN);
  input_pin = pin;
}

bool Button::read_state() {
  bool buttonstate = digitalRead(input_pin);
  usleep(200000);
  return buttonstate;
}