#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include <Arduino.h> 

class PressureSensor 
{
public:
    explicit PressureSensor(uint8_t pin_a, uint8_t pin_b);
    float read();
private:
    const float io_voltage_ = 3.3;
    const int analog_read_resolution = 4095; 
    const uint8_t input_pin_a_, input_pin_b_;
};

#endif  // PRESSURE_SENSOR_H
