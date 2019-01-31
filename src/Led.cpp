#include <Arduino.h>
#include "Led.h" 

Led::Led(int pin)
{
    pinMode(pin, OUTPUT); // Specify that pin is a output
    output_pin = pin;
}

void Led::Blink(int led_delay)
{
    digitalWrite(output_pin, HIGH); // Set 3.3V at output_pin 
    delay(led_delay);               // Wait half the period
    digitalWrite(output_pin,LOW);   // Pull output_pin to GND
    delay(led_delay);               // Wait half the period

}