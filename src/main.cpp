#include "button.h"
#include "joystick.h"
#include "rocker_switch.h"
#include "screen.h"
#include "state_machine.h"
#include "wireless_connection.h"

#include <Adafruit_DRV2605.h>
#include <Arduino.h>
#include <Goldelox_Serial_4DLib.h>
#include <SoftwareSerial.h>
#include <WiFi.h>
#include <march_shared_resources/GaitInstruction.h>
#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <std_msgs/String.h>
#include <std_msgs/Time.h>

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
#define UART_TX 32 // Software serial
#define UART_RX 34 // Software serial
#define RST 13     // Reset
#define BAUD_SCREEN 9600

#undef LEFT
#undef RIGHT
#undef UP
#undef DOWN

//#define USE_WIRELESS  // comment this to use wired connection.

// Trigger
Button trigger(TRIGGER);
// Rocker switch
RockerSwitch rocker(ROCKER_UP, ROCKER_DOWN);
// Joystick
Joystick joystick(JOYSTICK_LEFT, JOYSTICK_RIGHT, JOYSTICK_UP, JOYSTICK_DOWN,
                  JOYSTICK_PUSH);
// Serial communication between Lolin and Screen
SoftwareSerial screen_serial(UART_RX, UART_TX);
// Instance of the screen as in Goldelox_Serial library
Goldelox_Serial_4DLib screen_goldelox(&screen_serial);
// Wrapper instance of the screen
Screen screen(&screen_goldelox, &screen_serial, RST, BAUD_SCREEN);
// State Machine
StateMachine state_machine;

// Haptic Driver
Adafruit_DRV2605 driver;
uint8_t effect =
    14; // Select the desired effect, for now test effect "Buzz 100%"

// Create ros nodehandle with publishers
#ifdef USE_WIRELESS
ros::NodeHandle_<WiFiHardware> nh;
#else
ros::NodeHandle nh;
#endif

bool received_gait_instruction_response;
bool gait_message_send;
void gaitInstructionResponseCallback(const std_msgs::Bool& msg) {
  received_gait_instruction_response = true;
}

ros::Subscriber<std_msgs::Bool> gait_instruction_result_subscriber(
    "/march/input_device/instruction_response",
    &gaitInstructionResponseCallback);

march_shared_resources::GaitInstruction gait_instruction_msg;
std_msgs::Time time_msg;
ros::Publisher gait_instruction_publisher("/march/input_device/instruction",
                                          &gait_instruction_msg);
ros::Publisher ping_publisher("/march/input_device/alive", &time_msg);

void sendGaitMessage(const std::string& name) {
  if (!name.empty() && !gait_message_send) {
    gait_instruction_msg.type = march_shared_resources::GaitInstruction::GAIT;
    gait_instruction_msg.gait_name = name.c_str();
    gait_instruction_publisher.publish(&gait_instruction_msg);
    gait_message_send = true;
#ifdef DEMO_INPUT_DEVICE
    received_gait_instruction_response = true;
#endif
  }
}

void sendStopMessage() {
  gait_instruction_msg.type = march_shared_resources::GaitInstruction::STOP;
  gait_instruction_msg.gait_name = "";
  gait_instruction_publisher.publish(&gait_instruction_msg);
}

void sendAliveMessage() {
  time_msg.data = nh.now();
  ping_publisher.publish(&time_msg);
}

void drawCurrentImage() {
  word address_hi = 0;
  word address_lo = 0;
  state_machine.getCurrentImage(address_hi, address_lo);
  screen.draw_image(address_hi, address_lo);
}

void setup() {
  Serial.begin(57600);
  Serial.println();
  Serial.println("Start Input Device");

  Serial.println("Constructing state machine");
  state_machine.construct();
  Serial.println("Constructed state machine");

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
  Serial.println("ROS node initialized");

  // Reset the joystick right pin, this needed after the ROS node init pin 14 is
  // apparently used by ROS.
  pinMode(JOYSTICK_RIGHT, INPUT_PULLUP);

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.initialize();
  Serial.println("Screen initialized");
  sleep(1);

  drawCurrentImage();
  Serial.println("Ready for use");
}

void loop() {
  // Get button states
  RockerSwitchState rocker_switch_state = rocker.getState();
  JoystickPosition joystick_position = joystick.getPosition();
  ButtonState joystick_state = joystick.getState();
  ButtonState trigger_state = trigger.getState();

  // Set the effect to be played hoi
  // Waveforms can be combined, to create new wavefroms, see driver datasheet
  driver.setWaveform(0, effect); // Setup the waveform(s)
  driver.setWaveform(1, 0);      // end of waveform waveform

  // When button is pressed, vibrate
  if (trigger_state == ButtonState::PUSH) {
    driver.go();
  }

  if (received_gait_instruction_response) {
    // This means gait instruction handled
    // trigger_state = "EXIT_GAIT";
    received_gait_instruction_response = false;
    gait_message_send = false;
  }

  bool state_has_changed = false;
  if (joystick_position == JoystickPosition::LEFT) {
    state_has_changed = state_machine.left();
    Serial.println("Joystick left");
  } else if (joystick_position == JoystickPosition::RIGHT) {
    state_has_changed = state_machine.right();
    Serial.println("Joystick right");
  } else if (joystick_position == JoystickPosition::UP) {
    state_has_changed = state_machine.up();
    Serial.println("Joystick up");
  } else if (joystick_position == JoystickPosition::DOWN) {
    state_has_changed = state_machine.down();
    Serial.println("Joystick down");
  } else if (joystick_state == ButtonState::PUSH) {
    state_has_changed = state_machine.select();
    Serial.println("Joystick pushed");
  } else if (joystick_state == ButtonState::DOUBLE) {
    state_has_changed = state_machine.back();
    Serial.println("Joystick double");
  } else if (trigger_state == ButtonState::PUSH) {
    state_has_changed = state_machine.activate();
    Serial.println("Trigger pushed");
  }

  if (state_has_changed) {
    drawCurrentImage();

    const std::string& gait_name = state_machine.getCurrentGaitName();

    // If there is a transition to a new screen which belongs to a gait send
    // message with this gait.
    if (!gait_name.empty()) {
      sendGaitMessage(gait_name);
    } else if (trigger_state == ButtonState::PUSH) {
      // If the trigger press is not to select a gait, it's interpreted as a
      // stop.
      sendStopMessage();
    }
  }

  // Average loop frequency is around 20hz.
  sendAliveMessage();

  // Spin ros node
  nh.spinOnce();
}
