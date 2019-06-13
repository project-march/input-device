#include <Arduino.h>

// This is a minimal working version for the Lolin D32 Pro
// See the examples folder for examples with different peripherals

void setup(){
  Serial.begin(9600);
  Serial.println("Setup");
}

void loop(){
  Serial.println("Loop");
  sleep(1);
}