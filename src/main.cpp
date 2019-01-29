#include <Arduino.h>
#include "Led.h"

// Define output pin and period of blink
#define Pin_led 1
#define led_delay 50 // This value x2 is the period in ms

// Create Led instance
Led led(Pin_led);

void setup() 
{
}

void loop() {
 
  led.Blink(led_delay);
}