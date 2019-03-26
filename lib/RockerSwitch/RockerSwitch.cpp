#include "RockerSwitch.h"

RockerSwitch::RockerSwitch(int upPin, int downPin){
    pinMode(upPin, INPUT_PULLDOWN);
    pinMode(downPin, INPUT_PULLDOWN);

    this->pinUp = upPin;
    this->pinDown = downPin;
    this->lastPosition = "NEUTRAL";
    this->lastPrintTime = millis();
}

// Returns either "NEUTRAL", "UP", "HOLDING UP", "DOWN" or "HOLDING DOWN"
// It is advised to treat "HOLDING X" the same as "NEUTRAL" outside this function
String RockerSwitch::get_position(){
    String returnString;
    if (digitalRead(this->pinUp)){
        if(this->lastPosition != "UP" || (millis() - this->lastPrintTime) > this->holdTime){
            // reset lastPrintTime
            this->lastPrintTime = millis();
            this->lastPosition = "UP";
            returnString = "UP";
        }
        else{
            returnString = "HOLDING UP";
        }
    }
    else if (digitalRead(this->pinDown)){
        if(this->lastPosition != "DOWN" || (millis() - this->lastPrintTime) > this->holdTime){
            // reset lastPrintTime
            this->lastPrintTime = millis();
            this->lastPosition = "DOWN";
            returnString = "DOWN";
        }
        else{
            returnString = "HOLDING DOWN";
        }
    }
    else{
        this->lastPosition = "NEUTRAL";
        returnString = "NEUTRAL";
    }
    // To prevent multiple 'up's and 'down's per press due to bouncing
    usleep(this->bounceTime);
    return returnString;
}