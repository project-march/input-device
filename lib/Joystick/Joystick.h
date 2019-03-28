#ifndef Joystick_h
#define Joystick_h

#include <Arduino.h>

class Joystick {
public:
    Joystick(int pin_left, int pin_right, int pin_up, int pin_down, int pin_press);
    String get_position();
    bool get_press();

private:
    int left_pin;
    int right_pin;
    int up_pin;
    int down_pin;
    int press_pin;

    String lastPosition;
    unsigned long lastPrintTime;
    const int bounceTime = 100000; //us. May introduce unwanted behaviour if changed
    const unsigned long holdTime = 1000; //ms. Determines how often up or down are returned if the joystick is held.
};

#endif