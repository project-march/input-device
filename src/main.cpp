#include <Arduino.h>
#include "Led.h"
#include "Button.h"
// Define output pin and period of blink
#define Pin_led 1
#define led_delay 50 // This value x2 is the period in ms
#define Pin_button 19
// Create Led instance
Led led(Pin_led);
Button button(Pin_button);

void setup() 
{
  Serial.begin(9600);
}

void loop() {
 
  //led.Blink(led_delay);
  button.detect_push();
}