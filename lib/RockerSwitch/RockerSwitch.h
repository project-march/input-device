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
};

#endif