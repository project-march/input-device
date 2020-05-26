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
#include <ros.h>

#include <march_shared_resources/Alive.h>
#include <march_shared_resources/GaitInstruction.h>
#include <march_shared_resources/GaitInstructionResponse.h>

namespace pins
{
const uint8_t TRIGGER = 26;

const uint8_t ROCKER_UP = 2;
const uint8_t ROCKER_DOWN = 5;

const uint8_t JOYSTICK_LEFT = 23;
const uint8_t JOYSTICK_RIGHT = 14;
const uint8_t JOYSTICK_UP = 12;
const uint8_t JOYSTICK_DOWN = 19;
const uint8_t JOYSTICK_PUSH = 18;
const uint8_t UART_TX = 32;  // Software serial
const uint8_t UART_RX = 34;  // Software serial
const uint8_t RST = 13;      // Reset
}  // namespace pins

const uint32_t BAUD_SCREEN = 9600;
const uint64_t BAUD_SERIAL = 57600;

// Necessary, since the 4dsystems defines these
// and they clash with our joystick definitions
#undef LEFT
#undef RIGHT
#undef UP
#undef DOWN

//#define USE_WIRELESS  // comment this to use wired connection.

Button trigger(pins::TRIGGER);
RockerSwitch rocker(pins::ROCKER_UP, pins::ROCKER_DOWN);
Joystick joystick(pins::JOYSTICK_LEFT, pins::JOYSTICK_RIGHT, pins::JOYSTICK_UP, pins::JOYSTICK_DOWN,
                  pins::JOYSTICK_PUSH);

SoftwareSerial screen_serial(pins::UART_RX, pins::UART_TX);
Goldelox_Serial_4DLib screen_goldelox(&screen_serial);
Screen screen(&screen_goldelox, &screen_serial, pins::RST, BAUD_SCREEN);

StateMachine state_machine;

Adafruit_DRV2605 driver;
// Select the desired effect, for now test effect "Buzz 100%"
const uint8_t EFFECT = 14;

// Create ros nodehandle with publishers
#ifdef USE_WIRELESS
ros::NodeHandle_<WiFiHardware> nh;
#else
ros::NodeHandle nh;
#endif

bool received_gait_instruction_response = false;
bool gait_rejected = false;
bool gait_message_send = false;
void gaitInstructionResponseCallback(const march_shared_resources::GaitInstructionResponse& msg)
{
  if (msg.result == msg.GAIT_FINISHED || msg.result == msg.GAIT_REJECTED)
  {
    received_gait_instruction_response = true;
  }
}

ros::Subscriber<march_shared_resources::GaitInstructionResponse>
    gait_instruction_result_subscriber("/march/input_device/instruction_response", &gaitInstructionResponseCallback);

march_shared_resources::GaitInstruction gait_instruction_msg;
march_shared_resources::Alive alive_msg;
ros::Publisher gait_instruction_publisher("/march/input_device/instruction", &gait_instruction_msg);
ros::Publisher ping_publisher("/march/input_device/alive", &alive_msg);

void sendGaitMessage(const std::string& name)
{
  if (!name.empty() && !gait_message_send)
  {
    gait_instruction_msg.type = march_shared_resources::GaitInstruction::GAIT;
    gait_instruction_msg.gait_name = name.c_str();
    gait_instruction_publisher.publish(&gait_instruction_msg);
    gait_message_send = true;
#ifdef DEMO_INPUT_DEVICE
    sleep(1);
    received_gait_instruction_response = true;
#endif
  }
}

void sendStopMessage()
{
  gait_instruction_msg.type = march_shared_resources::GaitInstruction::STOP;
  gait_instruction_msg.gait_name = "";
  gait_instruction_publisher.publish(&gait_instruction_msg);
}

void sendAliveMessage()
{
  alive_msg.stamp = nh.now();
  ping_publisher.publish(&alive_msg);
}

void drawCurrentImage()
{
  const SectorAddress& address = state_machine.getCurrentImage();
  screen.draw_image(address);
}

void setup()
{
  Serial.begin(BAUD_SERIAL);

#ifdef USE_WIRELESS
  setupWiFi();
#endif

  pinMode(pins::UART_TX, OUTPUT);
  pinMode(pins::UART_RX, INPUT);

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.init();

  // Setup I2C protocol
  driver.begin();
  driver.selectLibrary(2);
  // I2C trigger by sending 'go' command
  // default, internal trigger when sending GO command
  driver.setMode(DRV2605_MODE_INTTRIG);

  // Initialize ros node for communication.
  nh.initNode();
  nh.advertise(gait_instruction_publisher);
  nh.advertise(ping_publisher);
  nh.subscribe(gait_instruction_result_subscriber);

  alive_msg.id = "crutch";

  // Reset the joystick right pin, this needed after the ROS node init pin 14 is
  // apparently used by ROS.
  pinMode(pins::JOYSTICK_RIGHT, INPUT_PULLUP);

  state_machine.construct();

  sleep(2);
  drawCurrentImage();
}

void loop()
{
  // Get button states
  // RockerSwitchState rocker_switch_state = rocker.getState();
  JoystickState joystick_state = joystick.getState();
  ButtonState joystick_button_state = joystick.getButtonState();
  ButtonState trigger_state = trigger.getState();

  // When button is pressed, vibrate
  if (trigger_state == ButtonState::PUSH)
  {
    // Waveforms can be combined, to create new wavefroms, see driver datasheet
    driver.setWaveform(0, EFFECT);  // Setup the waveform(s)
    driver.setWaveform(1, 0);       // end of waveform waveform

    driver.go();
  }

  bool state_has_changed = false;
  if (received_gait_instruction_response)
  {
    // This means gait instruction handled
    received_gait_instruction_response = false;
    gait_message_send = false;
    state_has_changed = state_machine.activate();
  }
  else if (gait_message_send)
  {
    if (trigger_state == ButtonState::PUSH)
    {
      sendStopMessage();
    }
  }
  else
  {
    switch (joystick_state)
    {
      case JoystickState::LEFT:
        state_has_changed = state_machine.left();
        break;
      case JoystickState::RIGHT:
        state_has_changed = state_machine.right();
        break;
      case JoystickState::UP:
        state_has_changed = state_machine.up();
        break;
      case JoystickState::DOWN:
        state_has_changed = state_machine.down();
        break;
      default:
        break;
    }

    if (!state_has_changed)
    {
      if (joystick_button_state == ButtonState::PUSH)
      {
        state_has_changed = state_machine.select();
      }
      else if (joystick_button_state == ButtonState::DOUBLE)
      {
        state_has_changed = state_machine.back();
      }
      else if (trigger_state == ButtonState::PUSH)
      {
        state_has_changed = state_machine.activate();
      }
    }
  }

  if (state_has_changed)
  {
    drawCurrentImage();

    std::string gait_name = state_machine.getCurrentGaitName();
    if (!gait_name.empty())
    {
      sendGaitMessage(gait_name);
    }
  }

  // Average loop frequency is around 20hz.
  sendAliveMessage();

  nh.spinOnce();
}
