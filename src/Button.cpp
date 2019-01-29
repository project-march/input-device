#include <Arduino.h>
#include "Button.h"

Button::Button(int pin)
{
  pinMode(pin, INPUT);
  input_pin = pin;
}

void Button:: detect_push()
{
  int buttonstate = digitalRead(input_pin);
  Serial.println(buttonstate);
  delay(1);
}