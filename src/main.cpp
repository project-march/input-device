#include <Arduino.h>
#include <ros.h>
// #include "Adafruit_DRV2605.h"
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
// #include "Button.h"
// #include "Led.h"
#include "Joystick.h"

// Define Pins forJoystick 
#define Pin_left 15
#define Pin_right 2
#define Pin_up 0
#define Pin_down 4
#define Pin_press 5

// #define Pin_led 33
// #define Pin_button 34

// #define led_cycle 50  
#define Baudrate 9600

// Create instances
Joystick joystick(Pin_left, Pin_right, Pin_up, Pin_down, Pin_press);
// Led led(Pin_led);
// Button button(Pin_button);
// Adafruit_DRV2605 driver;

int button_state;
// uint8_t effect = 47; // Select the desired effect, for now test effect "Buzz 100%"
bool pressed = false;

// Scroller
int encoder0PinA = 33;
int encoder0PinB = 32;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;
int threshold = 2;

// Create ros nodehandle with publishers
ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher scroller_publisher = ros::Publisher("/scroller", &str_msg);
void messageCb( const std_msgs::Int16& toggle_msg){
  threshold = toggle_msg.data;
}
ros::Subscriber<std_msgs::Int16> sub_sensitivity("/sensitivity", &messageCb );


void sendScrollerMessage(String direction){
  str_msg.data = direction.c_str();
  scroller_publisher.publish( &str_msg );
}

void sendScrollerMessagePress(){
  str_msg.data = "press";
  scroller_publisher.publish( &str_msg );
}

void setup() {
  Serial.begin(Baudrate);

  // Setup I2C protocol`
  // driver.begin();
  
  // I2C trigger by sending 'go' command
  // default, internal trigger when sending GO command
  // driver.setMode(DRV2605_MODE_INTTRIG);

  // Set the effect to be played
  // Waveforms can be combined, to create new wavefroms, see datasheet Adafruit
  // DRV2605
  // driver.setWaveform(0, effect);  // Setup the waveform(s)
  // driver.setWaveform(1, 0);       // end of waveform waveform

  // Initialize the ros nodehandle and publishers

  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);

  nh.initNode();
  nh.advertise(scroller_publisher);
  nh.subscribe(sub_sensitivity);
}

void scroller(){
  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
  }
  if(encoder0Pos >= threshold){
      sendScrollerMessage("right");
      encoder0Pos = 0;
  }
  if(encoder0Pos <= -threshold){
      sendScrollerMessage("left");
      encoder0Pos = 0;
  }
  
  Serial.println(encoder0Pos);
  encoder0PinALast = n;
}

void loop() {

  String pos = joystick.get_new_position();
  if(pos != "unchanged" && pos != "down"){
    Serial.print("New Joystick position: ");
    Serial.print(pos);
    Serial.print("\n");
    sendScrollerMessage(pos);
  }

  if(joystick.get_new_press()){
    Serial.println("Joystick press detected");
    sendScrollerMessagePress();
  }


  // When button is pressed, vibrate
  // if (button.read_state()) {
  //   // play the effect!
  //   Serial.println("Push detected!"); 
  //   driver.go();
  // }

  // Serial.println("TEST");
  // led.Blink(led_cycle);

  scroller();

  // Spin the nodehandle to send and receive messages
  nh.spinOnce();
  // Serial.println("Test");
  // sleep(1);
}