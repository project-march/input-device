#include <Arduino.h>
#include "Led.h"
#include "Button.h"

// Define Pins for Peripherals
#define Pin_led 33
#define Pin_button 19

#define led_cycle 50 // This value x2 is the period in ms
#define Baudrate 9600

// Create instances
Led led(Pin_led);
Button button(Pin_button);

int button_state;

void setup() 
{
  Serial.begin(Baudrate);
}

void loop() {

  button_state = button.read_state();
  
  led.Blink(led_cycle);
  
  if (button_state == HIGH)
    {
        Serial.println("Push detected!"); // Print via Serial USB connection
    }

}