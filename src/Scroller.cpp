#include "Scroller.h"
#include <Arduino.h>

Scroller::Scroller(int pin_A, int pin_B) {
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);

  A_pin = pin_A;
  B_pin = pin_B;

  position = 0;
  last_A = false;
}

int Scroller::get_position() {
  bool new_A = digitalRead(A_pin);
  if ((last_A == LOW) && (new_A == HIGH)) {
    if (digitalRead(B_pin) == LOW) {
      position--;
    } else {
      position++;
    }
  }
  last_A = new_A;
  return position;
}

void Scroller::reset_position(){
  position = 0;
}