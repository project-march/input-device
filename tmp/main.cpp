#include <Arduino.h>
#include <ros.h>
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Adafruit_ImageReader.h"

void setup(){
  Serial.begin(9600);
  Serial.println("Started Setup");
}

void loop(){
  Serial.println("In the loop");
  sleep(1);
}