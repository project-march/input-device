#include <Arduino.h>
#include "Button.h"

Button::Button(int pin)
{
  pinMode(pin, OUTPUT);
  output_pin = pin;
}

void Button:: detect_push()
{
    
}