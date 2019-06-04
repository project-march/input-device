#include <Arduino.h>
#include <WiFi.h>
#include <StateMachine.h>
#include <RockerSwitch.h>
#include <Joystick.h>
#include <Button.h>
#include <SoftwareSerial.h>
#include <Goldelox_Serial_4DLib.h>
#include <Screen.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <WirelessConnection.h>


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

// Create ros nodehandle with publishers
ros::NodeHandle_<WiFiHardware> nh;
std_msgs::String str_msg;
ros::Publisher scroller_publisher = ros::Publisher("/scroller", &str_msg);

void sendScrollerMessagePress(){
  str_msg.data = "press";
  scroller_publisher.publish( &str_msg );
}

void setup(){
  Serial.begin(9600);
  Serial.println("Prototype");

  // Set screen pins as either input or output
  pinMode(RST, OUTPUT);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  // Setup wifi connection
  setupWiFi();

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.initialize();
  sleep(1);

  // Initialize ros node for communication.
  nh.initNode();
  nh.advertise(scroller_publisher);
}

void loop(){
  // Get button states
  String rockerState = rocker.get_position();
  String joystickState = joystick.get_position();
  String joystickPress = joystick.get_press();
  String triggerPress = trigger.read_state();

  if (joystickPress == "PUSH"){
    sendScrollerMessagePress();
  }
  // Determine new state
  stateMachine.updateState(joystickState, joystickPress, rockerState, triggerPress);

  // Draw appropriate image
  int *drawSdAddresses = stateMachine.getScreenImage();
  screen.draw_image(*(drawSdAddresses), *(drawSdAddresses+1));

  // Spin ros node
  nh.spinOnce();
}
