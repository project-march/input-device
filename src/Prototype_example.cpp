#include <Arduino.h>
#include "RockerSwitch.h"
#include "Joystick.h"
#include "SoftwareSerial.h"
#include "Goldelox_Serial_4DLib.h"
#include "Screen.h"
#include "StateMachine.h"

// Pin definitions
// Trigger
#define TRIGGER           26
// Rocker Switch
#define ROCKER_UP         2
#define ROCKER_DOWN       5
// Joystick
#define JOYSTICK_LEFT     23
#define JOYSTICK_RIGHT    22
#define JOYSTICK_UP       21
#define JOYSTICK_DOWN     19
#define JOYSTICK_PUSH     18
// Screen
#define UART_TX           32 //software serial
#define UART_RX           34 //software serial
#define RST               13
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
StateMachine stateMachine();


int scrollAddresses[] = { Sofa_Hi, Sofa_Lo,
                          Cups_Hi, Cups_Lo, 
                          SlopeUp_Hi, SlopeUp_Lo,
                          StairUp_Hi, StairUp_Lo};

int currentPicture = 4;
void scrollLeft();
void scrollRight();

void setup(){
  Serial.begin(9600);
  Serial.println("Prototype");

  // Set screen pins as either input or output
  pinMode(RST, OUTPUT);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.initialize();
  screen.draw_image(SLOPE_ADDRESS_HI, SLOPE_ADDRESS_LO);
  sleep(1);
}

void loop(){
  // Get button states
  String rockerState = rocker.get_position();
  String joystickState = joystick.get_position();
  String joystickPress = joystick.get_press();
  String triggerPress = trigger.read_state();

  // Determine new state
  stateMachine.updateState(joystickState, joystickPress, rockerState, triggerPress);

  // Draw appropriate image
  int drawSdAddresses[2] = stateMachine.getScreenImage();
  screen.draw_image(drawSdAddresses[0], drawSdAddresses[1]);
}
