#include <Arduino.h>
#include <StateMachine.h>
#include <RockerSwitch.h>
#include <Joystick.h>
#include <Button.h>
#include <SoftwareSerial.h>
#include <Goldelox_Serial_4DLib.h>
#include <Screen.h>
#include "Adafruit_DRV2605.h"

// Pin definitions
// Trigger
#define TRIGGER           26
// Rocker Switch
#define ROCKER_UP         2
#define ROCKER_DOWN       5
// Joystick
#define JOYSTICK_LEFT     23
#define JOYSTICK_RIGHT    12
#define JOYSTICK_UP       14
#define JOYSTICK_DOWN     19
#define JOYSTICK_PUSH     18
// Screen
#define UART_TX           32 // Software serial
#define UART_RX           34 // Software serial
#define RST               13 // Reset
#define BAUD_SCREEN       9600

// Trigger
Button trigger(TRIGGER);
// Rocker switch
RockerSwitch rocker(ROCKER_UP, ROCKER_DOWN);
// Joystick
Joystick joystick(JOYSTICK_LEFT, JOYSTICK_RIGHT, JOYSTICK_UP, JOYSTICK_DOWN, JOYSTICK_PUSH);
// Serial communication between Lolin and Screen
SoftwareSerial screenSerial(UART_RX, UART_TX);
// Instance of the screen as in Goldelox_Serial library
Goldelox_Serial_4DLib screenGoldelox(&screenSerial);
// Wrapper instance of the screen
Screen screen(&screenGoldelox, &screenSerial, RST, BAUD_SCREEN);
// State Machine
StateMachine stateMachine;

// Haptic Driver
Adafruit_DRV2605 driver;
uint8_t effect = 47; // Select the desired effect, for now test effect "Buzz 100%"

void setup(){
  Serial.begin(9600);
  Serial.println("Prototype");

  // Set screen pins as either input or output
  pinMode(RST, OUTPUT);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  // Setup I2C protocol
  driver.begin();
  // Select the effect library
  driver.selectLibrary(2);
  // I2C trigger by sending 'go' command
  // default, internal trigger when sending GO command
  driver.setMode(DRV2605_MODE_INTTRIG);

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.initialize();
  sleep(1);
}

void loop(){
  // Get button states
  String rockerState = rocker.get_position();
  String joystickState = joystick.get_position();
  String joystickPress = joystick.get_press();
  String triggerPress = trigger.read_state();

  // Set the effect to be played
  // Waveforms can be combined, to create new wavefroms, see driver datasheet
  driver.setWaveform(0, effect);  // Setup the waveform(s)
  driver.setWaveform(1, 0);       // end of waveform waveform
  // When button is pressed, vibrate
  if(triggerPress == "PUSH"){
    driver.go();
  }

  // Determine new state
  stateMachine.updateState(joystickState, joystickPress, rockerState, triggerPress);

  // Draw appropriate image
  int *drawSdAddresses = stateMachine.getScreenImage();
  screen.draw_image(*(drawSdAddresses), *(drawSdAddresses+1));
}
