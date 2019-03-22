#include <Arduino.h>
#include "Adafruit_DRV2605.h"
#include "Button.h"

// Define Pin for button
#define Pin_button 34

Button button(Pin_button);
Adafruit_DRV2605 driver;

int button_state;
uint8_t effect; // Select the desired effect, for now test effect "Buzz 100%"

void setup() {
  Serial.begin(9600);

  // Setup I2C protocol
  driver.begin();

  // Select the effect library
  driver.selectLibrary(2);

  // I2C trigger by sending 'go' command
  // default, internal trigger when sending GO command
  driver.setMode(DRV2605_MODE_INTTRIG);

  effect = 47;
}

void loop() {
  // Set the effect to be played
  // Waveforms can be combined, to create new wavefroms, see driver datasheet
  driver.setWaveform(0, effect);  // Setup the waveform(s)
  driver.setWaveform(1, 0);       // end of waveform waveform

  // When button is pressed, vibrate
  if (button.read_state()) {
    Serial.println("Push detected!");
    // play the effect!
    driver.go();
  }

}