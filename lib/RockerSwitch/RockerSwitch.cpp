#include "RockerSwitch.h"

RockerSwitch::RockerSwitch(int upPin, int downPin){
    pinMode(upPin, INPUT);
    pinMode(downPin, INPUT);

    this->pinUp = upPin;
    this->pinDown = downPin;
}

String RockerSwitch::get_position(){
    if (digitalRead(this->pinUp)){
        return "UP";
    }
    else if (digitalRead(this->pinDown)){
        return "DOWN";
    }
    else{
        return "NEUTRAL";
    }
}