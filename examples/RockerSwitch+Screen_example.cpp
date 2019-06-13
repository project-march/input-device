#include <Arduino.h>
#include "RockerSwitch.h"
#include "SoftwareSerial.h"
#include "Goldelox_Serial_4DLib.h"
#include "Screen.h"
#include "SD_sector_addresses.h"

// Pin definitions
#define ROCKER_UP         2
#define ROCKER_DOWN       5
#define UART_TX           32 //software serial
#define UART_RX           34 //software serial
#define RST               13
#define BAUD_SCREEN       9600

// Rocker switch
RockerSwitch rocker(ROCKER_UP, ROCKER_DOWN);
// Serial communication between Lolin and Screen
SoftwareSerial screenSerial(UART_RX, UART_TX);
// Instance of the screen as in Goldelox_Serial library
Goldelox_Serial_4DLib screenGoldelox(&screenSerial);
// Wrapper instance of the screen
Screen screen(&screenGoldelox, &screenSerial, RST, BAUD_SCREEN);

int pictureList[] = { SOFA_ADDRESS_HI, SOFA_ADDRESS_LO,
                      CUP_ADDRESS_HI, CUP_ADDRESS_LO, 
                      SLOPE_ADDRESS_HI, SLOPE_ADDRESS_LO,
                      STAIRS_ADDRESS_HI, STAIRS_ADDRESS_LO,
                      SIT_ADDRESS_HI, SIT_ADDRESS_LO};

int currentPicture = 4;

void setup(){
  Serial.begin(9600);
  Serial.println("Rockerswitch + screen test");

  // Set pins as either input or output
  pinMode(RST, OUTPUT);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.initialize();
  screen.draw_image(SLOPE_ADDRESS_HI, SLOPE_ADDRESS_LO);
  sleep(1);
}

void loop(){
  String rockerStatus = rocker.get_position();
  if(rockerStatus != "NEUTRAL" && rockerStatus != "HOLDING UP" && rockerStatus != "HOLDING DOWN"){
    Serial.print("Rocker status: ");
    Serial.print(rockerStatus);
    Serial.print("\n");

    if(rockerStatus == "UP"){
      // Show picture above current picture
      if(currentPicture >= 8){
        currentPicture = 0;
      }
      else{
        currentPicture += 2;
      }
      screen.draw_image(pictureList[currentPicture], pictureList[currentPicture+1]);
    }
    if(rockerStatus == "DOWN"){
      // Show picture below current picture
      if(currentPicture <= 0){
        currentPicture = 8;
      }
      else{
        currentPicture -= 2;
      }
      screen.draw_image(pictureList[currentPicture], pictureList[currentPicture+1]);
    }
  }
  else{
    screen.draw_image(pictureList[currentPicture], pictureList[currentPicture+1]);
  }
}