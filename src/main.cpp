#include <Arduino.h>
#include <ros.h>
#include "Adafruit_DRV2605.h"
#include <std_msgs/String.h>
#include "Button.h"
#include "Led.h"

// Define Pins for Peripherals
#define Pin_led 33
#define Pin_button 34

#define led_cycle 50  // This value x2 is the period in ms
#define Baudrate 9600

// Create instances
Led led(Pin_led);
Button button(Pin_button);
Adafruit_DRV2605 driver;

int button_state;
uint8_t effect = 47; // Select the desired effect, for now test effect "Buzz 100%"

// Create ros nodehandle with publishers
ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher scroller_publisher = ros::Publisher("/scroller", &str_msg);

void setup() {
  Serial.begin(Baudrate);

  // Setup I2C protocol`
  driver.begin();

  // Select the effect library
  driver.selectLibrary(2);

  // I2C trigger by sending 'go' command
  // default, internal trigger when sending GO command
  driver.setMode(DRV2605_MODE_INTTRIG);

  // Initialize the ros nodehandle and publishers
  nh.initNode();
  nh.advertise(scroller_publisher);
}

void sendScrollerMessage(String direction){
  str_msg.data = direction.c_str();
  scroller_publisher.publish( &str_msg );
}

void loop() {
  // Set the effect to be played
  // Waveforms can be combined, to create new wavefroms, see datasheet Adafruit
  // DRV2605
  driver.setWaveform(0, effect);  // Setup the waveform(s)
  driver.setWaveform(1, 0);       // end of waveform waveform

  // When button is pressed, vibrae
  if (button.read_state()) {
    // play the effect!
    Serial.println("Push detected!"); 
    sendScrollerMessage("left");
    driver.go();
  }
  Serial.println("TEST");
  sendScrollerMessage("right");
  led.Blink(led_cycle);

  // Spin the nodehandle to send and receive messages
  nh.spinOnce();
  delay(100);
}