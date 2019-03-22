#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) {
  pinMode(pin, INPUT);  // Specify input pin
  input_pin = pin;
}

int Button::read_state() {
  int buttonstate =
      digitalRead(input_pin);  // Read the current state of the button
  return buttonstate;
}