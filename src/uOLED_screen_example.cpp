#include "Screen.h"
#include "SoftwareSerial.h"
#include "SD_sector_addresses.h"

// Developed by M. van der Marel for Project MARCH
// Required tools for running this code:
//  Arduino ESP32 board (we use Lolin D32 Pro)
//  A uOLED-160G2 screen by 4D Systems
//  The GoldeLox_Serial library for Arduino
//  An SD card set up with the 4D Systems software with images, placed in the uOLED-160G2 board
//  The sector addresses returned by the 4D Systems software can be placed in 'SD_sector_addresses.h' for easy access


#define UART_TX       32 //software serial only
#define UART_RX       34 //software serial only
#define RST           13
#define BAUD_SCREEN   9600
#define SLEEPTIME_SCREEN  100000


SoftwareSerial screenSerial(UART_RX, UART_TX);
Goldelox_Serial_4DLib screenGoldelox(&screenSerial);
Screen screen(&screenGoldelox, &screenSerial, RST, BAUD_SCREEN, SLEEPTIME_SCREEN);

void setup() {
  // Serial.begin(115200);
  // Serial.println("Setup");

  pinMode(RST, OUTPUT);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  screen.initialize();
}

void loop(void) {
  // Serial.println("Loop");

  screen.draw_image(CUP_ADDRESS_HI, CUP_ADDRESS_LO);
  sleep(1);
  screen.draw_image(STAIRS_ADDRESS_HI, STAIRS_ADDRESS_LO);
  sleep(1);
  screen.draw_image(SIT_ADDRESS_HI, SIT_ADDRESS_LO);
  sleep(1);
  screen.draw_image(SOFA_ADDRESS_HI, SOFA_ADDRESS_LO);
  sleep(1);
}
