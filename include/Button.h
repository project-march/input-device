#ifndef Button_h
#define Button_h

#include <Arduino.h>


class Button
{
    public: 
        Button(int pin);
        void detect_push();
    private:
    int output_pin;
};
#endif