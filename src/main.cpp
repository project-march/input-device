#include <Arduino.h>
#include "Led.h"

// Define output pin and period of blink
#define Pinout 1
#define led_delay 50 // This value x2 is the period in ms

// Create Led instance
Led led(Pinout);

void setup() 
{
}

void loop() {
 
  led.Blink(led_delay);
}