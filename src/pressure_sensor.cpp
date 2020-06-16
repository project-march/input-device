#include "pressure_sensor.h"

PressureSensor::PressureSensor(uint8_t pin_a, uint8_t pin_b) : input_pin_a_(pin_a), input_pin_b_(pin_b)
{
  pinMode(pin_a, INPUT);
  pinMode(pin_b, INPUT);
}

float PressureSensor::read()
{
  int readout_pin_a = analogRead(input_pin_a_);
  int readout_pin_b = analogRead(input_pin_b_);

  float voltage_diff = (io_voltage_ / analog_read_resolution) * (readout_pin_a - readout_pin_b);

  return voltage_diff;
}