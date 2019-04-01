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
    this->lastPosition = "NEUTRAL";
}

String Joystick::get_position() {
    // TODO: make this work with timestamps (same as rocker) to allow holding and still return instantly
    String position;
    if(!digitalRead(this->left_pin)){
        position = "LEFT";
    }else if(!digitalRead(this->right_pin)){
        position = "RIGHT";
    }else if(!digitalRead(this->up_pin)){
        position = "UP";
    }else if(!digitalRead(this->down_pin)){
        position = "DOWN";
    }else{
        position = "NEUTRAL";
    }
    return position;
}

bool Joystick::get_press(){
    return (!digitalRead(this->press_pin));
}