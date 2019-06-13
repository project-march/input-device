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

// Returns either "NEUTRAL", "PUSH" or "DOUBLE"
String Joystick::get_press(){  
    String returnString;
    if(this->recentDoubleClick){
        if(millis() - this->lastDoubleClickTime > this->doubleClickTimeoutTime){
            this->recentDoubleClick = false; // Go back to an mode where we can publish stuff
        }
    }
    if(this->recentInitialClick && !this->recentDoubleClick){
        if(millis() - this->lastPushReleaseTime > this->doubleClickTime && digitalRead(this->press_pin)){ // Enough time has elapsed since last push release time and not pressed
            this->lastPush = false;
            returnString = "PUSH"; // No second click, so publish the single click
            this->recentInitialClick = false;
        }
        else if(!digitalRead(this->press_pin)){ // Joystick is pressed
            this->lastPush = true;
            returnString = "DOUBLE"; // A second click, so publish the double click
            this->recentInitialClick = false;
            this->recentDoubleClick = true;
            this->lastDoubleClickTime = millis();
        }
        else{ // Joystick not pressed, not just released and recent enough initial click
            this->lastPush = false;
            returnString = "NEUTRAL";
        }
    }
    else{ // No recent initial click or a recent double click
        if(!digitalRead(this->press_pin)){ // Pressed
            this->lastPush = true;
        }
        else{ // Not pressed
            if(this->lastPush){ // Just released
                this->recentInitialClick = true;
                this->lastPushReleaseTime = millis();
            }
            else{
                this->recentInitialClick = false;
            }
            this->lastPush = false;
        }
        returnString = "NEUTRAL";
    }
    // To prevent multiple prints per action due to bouncing
    usleep(this->bounceTime);
    return returnString;
}