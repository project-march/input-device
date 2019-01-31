#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{
    public: 
        Button(int pin);
        int read_state();
    private:
        int input_pin;
};

#endif