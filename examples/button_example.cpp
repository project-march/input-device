#include "button.h"

#include <Arduino.h>

// Define Pin for button
#define Pin_button 26

Button button(Pin_button);

int button_state;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // When button is pressed, print
  if (button.getState() == ButtonState::PUSH)
  {
    Serial.println("Push detected!");
  }
  if (button.getState() == ButtonState::DOUBLE)
  {
    Serial.println("Double push detected!");
  }
}
