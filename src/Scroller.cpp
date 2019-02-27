#include "Scroller.h"
#include <Arduino.h>

Scroller::Scroller(int pin_left, int pin_right, int pin_up, int pin_down, int pin_press) {
  pinMode(pin_left, INPUT_PULLDOWN);
  pinMode(pin_right, INPUT_PULLDOWN);

  left_pin = pin_left;
  right_pin = pin_right;

  last_position = "neutral";
  last_press = false;
}

String Joystick::get_new_position() {
  String position;
  if(digitalRead(left_pin)){
      position = "left";
  }else if(digitalRead(right_pin)){
      position = "right";
  }else if(digitalRead(up_pin)){
      position = "up";
  }else if(digitalRead(down_pin)){
      position = "down";
  }else{
      position = "neutral";
  }
  if(position == last_position){
      return "unchanged";
  }
  last_position = position;
  return position;
}