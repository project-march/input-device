#include <Arduino.h>
#include "Joystick.h"

// Define Pins for Peripherals
#define Pin_left 15
#define Pin_right 2
#define Pin_up 0
#define Pin_down 4
#define Pin_press 5

#define Baudrate 9600

// Create instances
Joystick joystick(Pin_left, Pin_right, Pin_up, Pin_down, Pin_press);

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

  sleep(1);
}