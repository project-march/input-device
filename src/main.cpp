#include <Arduino.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include "Scroller.h"
#include "Joystick.h"

// Define pins for joystick 
#define Pin_left 15
#define Pin_right 2
#define Pin_up 0
#define Pin_down 4
#define Pin_press 5

// Define pins for scroller left
#define Pin_L_left 33
#define Pin_L_right 32

// Define pins for scroller right
#define Pin_R_left 26
#define Pin_R_right 25

#define Baudrate 9600

// Create instances
Joystick joystick(Pin_left, Pin_right, Pin_up, Pin_down, Pin_press);
Scroller scrollerLeft(Pin_L_left, Pin_L_right);
Scroller scrollerRight(Pin_R_left, Pin_R_right);

int scrollerThreshold;

// Create ros nodehandle with publishers
ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher scroller_publisher = ros::Publisher("/scroller", &str_msg);

void messageCb( const std_msgs::Int16& toggle_msg){
  scrollerThreshold = toggle_msg.data;
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

  scrollerThreshold = 2;

  // Initialize the ros nodehandle and publishers
  nh.initNode();
  nh.advertise(scroller_publisher);
  nh.subscribe(sub_sensitivity);
}

void loop() {

  // Joystick
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

  // Left scroller
  int positionLeft = scrollerLeft.get_position();
  if(positionLeft >= scrollerThreshold){
      sendScrollerMessage("right");
      Serial.println("Left scroller to the right");
      scrollerLeft.reset_position();
  }
  if(positionLeft <= -scrollerThreshold){
      sendScrollerMessage("left");
      Serial.println("Left scroller to the left");
      scrollerLeft.reset_position();
  }

  // Right scroller
  int positionRight = scrollerRight.get_position();
  if(positionRight >= scrollerThreshold){
      sendScrollerMessage("right");
      Serial.println("Right scroller to the right");
      scrollerRight.reset_position();
  }
  if(positionRight <= -scrollerThreshold){
      sendScrollerMessage("left");
      Serial.println("Right scroller to the left");
      scrollerRight.reset_position();
  }

  // Spin the nodehandle to send and receive messages
  nh.spinOnce();
  // Serial.println("Test");
  // sleep(1);
}