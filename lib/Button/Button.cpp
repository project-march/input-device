#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) {
  pinMode(pin, INPUT_PULLDOWN);
  input_pin = pin;
}

bool Button::read_state() {
  bool buttonState = digitalRead(input_pin);
  usleep(this->bouncetime);
  return buttonState;
}