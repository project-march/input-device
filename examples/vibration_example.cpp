#include <Adafruit_DRV2605.h>
#include <Arduino.h>

Adafruit_DRV2605 driver;

uint8_t effect;  // Select the desired effect, for now test effect "Buzz 100%"

void setup()
{
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

void loop()
{
  // Set the effect to be played
  // Waveforms can be combined, to create new wavefroms, see driver datasheet
  driver.setWaveform(0, effect);  // Setup the waveform(s)
  driver.setWaveform(1, 0);       // end of waveform waveform

  // play the effect!
  driver.go();

  sleep(1);
}