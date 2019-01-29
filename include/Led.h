#ifndef Led_h
#define Led_h

#include <Arduino.h>

class Led {

    public:
        Led(int pin);
        void Blink(int led_delay);
    private:
    int output_pin; // Each Led instance has a output pin
};

#endif