#include <Arduino.h>
#include "Button.h"

// Define Pin for button
#define Pin_button 26

Button button(Pin_button);

int button_state;


void setup() {
    Serial.begin(9600);
}

void loop() {
    // When button is pressed, print
    if (button.read_state()) {
        Serial.println("Push detected!");
    }
}
