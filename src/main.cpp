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
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Time.h>
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
#define JOYSTICK_RIGHT 22
#define JOYSTICK_UP 21
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

// Create ros nodehandle with publishers
#ifdef USE_WIRELESS
ros::NodeHandle_<WiFiHardware> nh;
#else
ros::NodeHandle nh;
#endif

march_shared_resources::GaitInstruction gaitInstructionMessage;
ros::Publisher gait_instruction_publisher("/march/input_device/instruction", &gaitInstructionMessage);
std_msgs::Time timeMessage;
ros::Publisher ping_publisher("/march/input_device/alive", &timeMessage);

State lastState;

void sendGaitMessage(State state)
{
  Serial.print("sendGaitMessage state ");
  const char* name = stateMachine.getGaitName(state);
  if (strncmp(name, "", 1) != 0)
  {
    gaitInstructionMessage.type = march_shared_resources::GaitInstruction::GAIT;
    gaitInstructionMessage.gait_name = name;
    gait_instruction_publisher.publish(&gaitInstructionMessage);
  }
}
void sendStopMessage()
{
  Serial.println("sendStopMessage");
  gaitInstructionMessage.type = march_shared_resources::GaitInstruction::STOP;
  gaitInstructionMessage.gait_name = "";
  gait_instruction_publisher.publish(&gaitInstructionMessage);
}

void sendAliveMessage()
{
  Serial.println("Staying alive");
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

  // Initialize ros node for communication.
  nh.initNode();
  nh.advertise(gait_instruction_publisher);
  nh.advertise(ping_publisher);
  Serial.println("ros node initialized");

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

  // Determine new state
  stateMachine.updateState(joystickState, joystickPress, rockerState, triggerPress);

  // Draw appropriate image
  int* drawSdAddresses = stateMachine.getScreenImage();
  screen.draw_image(*(drawSdAddresses), *(drawSdAddresses + 1));

  State newState = stateMachine.getCurrentState();
  std::string name = stateMachine.getGaitName(newState);

  // If there is a transition to a new screen which belongs to a gait send message with this gait.
  if (lastState != newState && !name.empty())
  {
    sendGaitMessage(newState);
  }
  else if (triggerPress == "PUSH")
  {
    // If the trigger press is not to select a gait, it's interpreted as a stop.
    sendStopMessage();
  }
  lastState = newState;

  // Average loop frequency is around 20hz.
  sendAliveMessage();

  // Spin ros node
  nh.spinOnce();
}
