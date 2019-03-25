#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Goldelox_Serial_4DLib.h"
#include "Screen.h"
#include "SD_sector_addresses.h"

// Developed by M. van der Marel for Project MARCH
// Required tools for running this code:
//  Arduino ESP32 board (we use Lolin D32 Pro)
//  A uOLED-160G2 screen by 4D Systems
//  The GoldeLox_Serial library for Arduino
//  A uSD card set up with the 4D Systems software with images, placed in the uOLED-160G2 board
//  The sector addresses returned by the 4D Systems software can be placed in 'SD_sector_addresses.h' for easy access


#define UART_TX           32 //software serial
#define UART_RX           34 //software serial
#define RST               13
#define BAUD_SCREEN       9600

// Serial communication between Lolin and Screen
SoftwareSerial screenSerial(UART_RX, UART_TX);
// Instance of the screen as in Goldelox_Serial library
Goldelox_Serial_4DLib screenGoldelox(&screenSerial);
// Wrapper instance of the screen
Screen screen(&screenGoldelox, &screenSerial, RST, BAUD_SCREEN);

void setup() {
  // Set pins as either input or output
  pinMode(RST, OUTPUT);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  // initialize screen by resetting, initing uSD card, clearing screen
  screen.initialize();
}

void loop(void) {
  // Draw different images from the uSD card in a loop
  screen.draw_image(CUP_ADDRESS_HI, CUP_ADDRESS_LO);
  sleep(1);
  screen.draw_image(STAIRS_ADDRESS_HI, STAIRS_ADDRESS_LO);
  sleep(1);
  screen.draw_image(SIT_ADDRESS_HI, SIT_ADDRESS_LO);
  sleep(1);
  screen.draw_image(SOFA_ADDRESS_HI, SOFA_ADDRESS_LO);
  sleep(1);
}
