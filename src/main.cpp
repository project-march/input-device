#include <Arduino.h>
#include "Joystick.h"

// Define Pins for Peripherals
#define Pin_Left 2
#define Pin_Up 15

#define Baudrate 9600

// Create instances
Joystick joystick(1, 3, Pin_Up, 6, 4);

void setup() {
  Serial.begin(Baudrate);
}

void loop() {
  String pos = joystick.get_position();
  bool press = joystick.get_press();

  // Serial.print("Position: ");
  // Serial.print(pos);
  // Serial.print(" Press: ");
  // Serial.print(press);
  // Serial.print("\n");
  Serial.println("Test");

  sleep(5);
}