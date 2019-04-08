#include <Arduino.h>
#include "Joystick.h"

// Pin definitions
// Joystick
#define JOYSTICK_LEFT     23
#define JOYSTICK_RIGHT    22
#define JOYSTICK_UP       21
#define JOYSTICK_DOWN     19
#define JOYSTICK_PUSH     18

// Create instances
// Joystick
Joystick joystick(JOYSTICK_LEFT, JOYSTICK_RIGHT, JOYSTICK_UP, JOYSTICK_DOWN, JOYSTICK_PUSH);

void setup() {
  Serial.begin(9600);
}

void loop() {
  String pos = joystick.get_position();
  String press = joystick.get_press();

  if (pos != "HOLDING" && pos != "NEUTRAL"){
    Serial.print("Joystick position: ");
    Serial.print(pos);
    Serial.print("\n");
  }
  if (press != "HOLDING" && press != "NEUTRAL"){
    Serial.println("Joystick pressed!");
  }
}