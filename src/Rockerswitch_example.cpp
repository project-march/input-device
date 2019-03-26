#include <Arduino.h>
#include "RockerSwitch.h"

// Pin definitions
#define ROCKER_UP     0
#define ROCKER_DOWN   5

RockerSwitch rocker(ROCKER_UP, ROCKER_DOWN);

void setup(){
  Serial.begin(9600);
  Serial.println("Started Serial communication");
}

void loop(){
  String rockerStatus = rocker.get_position();
  if(rockerStatus != "NEUTRAL"){
    Serial.print("Rocker status: ");
    Serial.print(rockerStatus);
    Serial.print("\n");
  }
}