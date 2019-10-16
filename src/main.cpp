#include <Arduino.h>
#include <WiFi.h>
#include <StateMachine.h>
#include <RockerSwitch.h>
#include <string.h>
#include <Joystick.h>
#include <Button.h>
#include <SoftwareSerial.h>
#include <Goldelox_Serial_4DLib.h>
#include <Screen.h>
#include "Adafruit_DRV2605.h"
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Time.h>
#include <std_msgs/Bool.h>
#include <ros/time.h>
#include <WirelessConnection.h>
#include <march_shared_resources/GaitInstruction.h>

// Pin definitions
// Trigger
#define TRIGGER 26
// Rocker Switch
#define ROCKER_UP 2
#define ROCKER_DOWN 5
// Joystick
#define JOYSTICK_LEFT 23
#define JOYSTICK_RIGHT 14
#define JOYSTICK_UP 12
#define JOYSTICK_DOWN 19
#define JOYSTICK_PUSH 18
// Screen
#define UART_TX 32  // Software serial
#define UART_RX 34  // Software serial
#define RST 13      // Reset
#define BAUD_SCREEN 9600

//#define USE_WIRELESS  // comment this to use wired connection.

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
uint8_t effect = 14;  // Select the desired effect, for now test effect "Buzz 100%"

// Create ros nodehandle with publishers
#ifdef USE_WIRELESS
ros::NodeHandle_<WiFiHardware> nh;
#else
ros::NodeHandle nh;
#endif

bool received_gait_instruction_response;
bool gait_message_send;
void gaitInstructionResponseCallback(const std_msgs::Bool& msg)
{
  received_gait_instruction_response = true;
}

ros::Subscriber<std_msgs::Bool> gait_instruction_result_subscriber("/march/input_device/instruction_response",
                                                                   &gaitInstructionResponseCallback);

march_shared_resources::GaitInstruction gaitInstructionMessage;
ros::Publisher gait_instruction_publisher("/march/input_device/instruction", &gaitInstructionMessage);
std_msgs::Time timeMessage;
ros::Publisher ping_publisher("/march/input_device/alive", &timeMessage);

void sendGaitMessage(std::string name)
{
  if (!name.empty() && !gait_message_send)
  {
    gaitInstructionMessage.type = march_shared_resources::GaitInstruction::GAIT;
    gaitInstructionMessage.gait_name = name.c_str();
    gait_instruction_publisher.publish(&gaitInstructionMessage);
    gait_message_send = true;
#ifdef DEMO_INPUT_DEVICE
    received_gait_instruction_response = true;
#endif
  }
}

void sendStopMessage()
{
  gaitInstructionMessage.type = march_shared_resources::GaitInstruction::STOP;
  gaitInstructionMessage.gait_name = "";
  gait_instruction_publisher.publish(&gaitInstructionMessage);
}

void sendAliveMessage()
{
  timeMessage.data = nh.now();
  ping_publisher.publish(&timeMessage);
}

void setup()
{
  Serial.begin(57600);
  Serial.println("Start Input Device");

#ifdef USE_WIRELESS
  setupWiFi();
#endif

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

  // Initialize ros node for communication.
  nh.initNode();
  nh.advertise(gait_instruction_publisher);
  nh.advertise(ping_publisher);
  nh.subscribe(gait_instruction_result_subscriber);
  Serial.println("ros node initialized");

  // Reset the joystick right pin, this needed after the ROS node init pin 14 is apparently used by ROS.
  pinMode(JOYSTICK_RIGHT, INPUT_PULLUP);

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.initialize();
  sleep(1);
}

void loop()
{

  // Get button states
  String rockerState = rocker.get_position();
  String joystickState = joystick.get_position();
  String joystickPress = joystick.get_press();
  String triggerPress = trigger.read_state();

  // Set the effect to be played hoi
  // Waveforms can be combined, to create new wavefroms, see driver datasheet
  driver.setWaveform(0, effect);  // Setup the waveform(s)
  driver.setWaveform(1, 0);       // end of waveform waveform

  // When button is pressed, vibrate
  if (triggerPress == "PUSH")
  {
    driver.go();
  }

  if (received_gait_instruction_response)
  {
    // This means gait instruction handled
    triggerPress = "EXIT_GAIT";
    received_gait_instruction_response = false;
    gait_message_send = false;
  }

  // Determine new state
  stateMachine.updateState(joystickState, joystickPress, rockerState, triggerPress);

  // Draw appropriate image
  int* drawSdAddresses = stateMachine.getScreenImage();
  screen.draw_image(*(drawSdAddresses), *(drawSdAddresses + 1));

  State newState = stateMachine.getCurrentState();
  std::string name = stateMachine.getGaitNameOfState(newState);

  // If there is a transition to a new screen which belongs to a gait send message with this gait.
  if (!name.empty())
  {
    sendGaitMessage(name);
  }
  else if (triggerPress == "PUSH")
  {
    // If the trigger press is not to select a gait, it's interpreted as a stop.
    sendStopMessage();
  }

  // Average loop frequency is around 20hz.
  sendAliveMessage();

  // Spin ros node
  nh.spinOnce();
}
