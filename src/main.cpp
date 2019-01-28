#include <Arduino.h>
#define ledPin 1
#define led_delay 100 // Delay for a led in ms
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(led_delay);
  digitalWrite(ledPin,LOW);
  delay(led_delay);
}