#include "joystick.h"

#include <Arduino.h>

// Pin definitions
// Joystick
#define JOYSTICK_LEFT 23
#define JOYSTICK_RIGHT 22
#define JOYSTICK_UP 21
#define JOYSTICK_DOWN 19
#define JOYSTICK_PUSH 18

// Create instances
// Joystick
Joystick joystick(JOYSTICK_LEFT, JOYSTICK_RIGHT, JOYSTICK_UP, JOYSTICK_DOWN, JOYSTICK_PUSH);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  JoystickState pos = joystick.getState();
  ButtonState press = joystick.getButtonState();

  switch (pos)
  {
    case JoystickState::LEFT:
      Serial.print("Joystick left");
      break;
    case JoystickState::RIGHT:
      Serial.print("Joystick right");
      break;
    case JoystickState::UP:
      Serial.print("Joystick up");
      break;
    case JoystickState::DOWN:
      Serial.print("Joystick down");
      break;
    default:
      break;
  }

  switch (press)
  {
    case ButtonState::PUSH:
      Serial.println("Joystick pressed");
      break;
    case ButtonState::DOUBLE:
      Serial.println("Joystick double pressed");
      break;
    default:
      break;
  }
}
