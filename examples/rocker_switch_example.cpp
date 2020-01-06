#include "rocker_switch.h"

#include <Arduino.h>

// Pin definitions
#define ROCKER_UP 0
#define ROCKER_DOWN 5

RockerSwitch rocker(ROCKER_UP, ROCKER_DOWN);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  RockerSwitchState status = rocker.getState();
  switch (status)
  {
    case RockerSwitchState::UP:
      Serial.println("rocker switch up");
      break;
    case RockerSwitchState::DOWN:
      Serial.println("rocker switch down");
      break;
    default:
      break;
  }
}
