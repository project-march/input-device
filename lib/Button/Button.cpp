#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) {
  pinMode(pin, INPUT_PULLDOWN);

  this->input_pin = pin;
}

// Read the current state of the button
bool Button::read_state() {
  return digitalRead(input_pin);
}