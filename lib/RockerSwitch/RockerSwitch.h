#ifndef RockerSwitch_h
#define RockerSwitch_h

#include <Arduino.h>

class RockerSwitch {
public:
    RockerSwitch(int upPin, int downPin);
    String get_position();

private:
    int pinUp;
    int pinDown;
    String lastPosition;
    unsigned long lastPrintTime;
    const unsigned int bounceTime = 20000; //us. May introduce unwanted behaviour if changed
    const unsigned long holdTime = 1000; //ms. Determines how often up or down are returned if the rocker switch is held up or down.
};

#endif