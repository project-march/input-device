#include "Joystick.h"

Joystick::Joystick(int pin_left, int pin_right, int pin_up, int pin_down, int pin_press) {
    pinMode(pin_left, INPUT_PULLUP);
    pinMode(pin_right, INPUT_PULLUP);
    pinMode(pin_up, INPUT_PULLUP);
    pinMode(pin_down, INPUT_PULLUP);
    pinMode(pin_press, INPUT_PULLUP);

    this->left_pin = pin_left;
    this->right_pin = pin_right;
    this->up_pin = pin_up;
    this->down_pin = pin_down;
    this->press_pin = pin_press;

    this->lastPrintTime = millis();
    this->lastPushPrintTime = millis();
    this->lastPosition = "NEUTRAL";
    this->lastPushPosition = "NEUTRAL";
}

// Returns either "NEUTRAL", "[DIRECTION]" or "HOLDING"
// It is advised to treat "HOLDING" the same as "NEUTRAL" outside this function
String Joystick::get_position() {
    String returnString;
    if(!digitalRead(this->left_pin)){
        if(this->lastPosition != "LEFT" || (millis()-this->lastPrintTime) > this->holdTime){
            returnString = "LEFT";
            this->lastPrintTime = millis();
            this->lastPosition = "LEFT";
        }
        else{
            returnString = "HOLDING";
        }
    }else if(!digitalRead(this->right_pin)){
        if(this->lastPosition != "RIGHT" || (millis()-this->lastPrintTime) > this->holdTime){
            returnString = "RIGHT";
            this->lastPrintTime = millis();
            this->lastPosition = "RIGHT";
        }
        else{
            returnString = "HOLDING";
        }
    }else if(!digitalRead(this->up_pin)){
        if(this->lastPosition != "UP" || (millis()-this->lastPrintTime) > this->holdTime){
            returnString = "UP";
            this->lastPrintTime = millis();
            this->lastPosition = "UP";
        }
        else{
            returnString = "HOLDING";
        }
    }else if(!digitalRead(this->down_pin)){
        if(this->lastPosition != "DOWN" || (millis()-this->lastPrintTime) > this->holdTime){
            returnString = "DOWN";
            this->lastPrintTime = millis();
            this->lastPosition = "DOWN";
        }
        else{
            returnString = "HOLDING";
        }
    }else{
        returnString = "NEUTRAL";
        this->lastPosition = "NEUTRAL";
    }
    // To prevent multiple prints per action due to bouncing
    usleep(this->bounceTime);
    return returnString;
}

// Returns either "NEUTRAL", "PUSH" or "HOLDING"
// It is advised to treat "HOLDING" the same as "NEUTRAL" outside this function
String Joystick::get_press(){  
  String returnString;
  if(!digitalRead(this->press_pin)){
    if(this->lastPushPosition != "PUSH" || (millis() - this->lastPushPrintTime) > this->holdTime){
      this->lastPushPrintTime = millis();
      this->lastPushPosition = "PUSH";
      returnString = "PUSH";
    }
    else{
      returnString = "HOLDING";
    }
  }
  else{
    this->lastPushPosition = "NEUTRAL";
    returnString = "NEUTRAL";
  }
  // To prevent multiple prints per action due to bouncing
  usleep(this->bounceTime);
  return returnString;
}