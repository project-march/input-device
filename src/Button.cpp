#include <Button.h>

Button::Button(int pin) {
  pinMode(pin, INPUT_PULLUP);

  this->input_pin = pin;
  this->lastPrintTime = millis();
  this->lastPosition = "NEUTRAL";
}

// Returns either "NEUTRAL", "PUSH" or "HOLDING"
// It is advised to treat "HOLDING" the same as "NEUTRAL" outside this function
String Button::read_state() {
  String returnString;
  if(!digitalRead(this->input_pin)){
    if(this->lastPosition != "PUSH" || (millis() - this->lastPrintTime) > this->holdTime){
      this->lastPrintTime = millis();
      this->lastPosition = "PUSH";
      returnString = "PUSH";
    }
    else{
      returnString = "HOLDING";
    }
  }
  else{
    this->lastPosition = "NEUTRAL";
    returnString = "NEUTRAL";
  }
  // To prevent multiple 'up's and 'down's per press due to bouncing
  usleep(this->bounceTime);
  return returnString;
}