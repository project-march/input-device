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
  Serial.begin(115200);
  Serial.println("Setup");

  pinMode(RST, OUTPUT);
  // digitalWrite(RST, 1);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  // screenSerial.begin(BAUD_SCREEN);

  // digitalWrite(RST, 0);
  // usleep(SLEEPTIME_SCREEN);
  // digitalWrite(RST, 1);
  // sleep(3);

  // int status = screenGoldelox.media_Init();
  // usleep(SLEEPTIME_SCREEN);
  // char str[100];
  // sprintf(str, "SD Init status = 0x%02X\n", status);
  // screenGoldelox.print(str);
  // usleep(SLEEPTIME_SCREEN);

  // screenGoldelox.gfx_Cls();
  // usleep(SLEEPTIME_SCREEN);


  screen.initialize();
}

void loop(void) {
  Serial.println("Loop");

  // screenGoldelox.media_SetSector(0,0);
  // screenGoldelox.media_Image(0,0);
  // usleep(SLEEPTIME_SCREEN);

  // screenGoldelox.media_SetSector(0x0000, 0x0051);
  // screenGoldelox.media_Image(0,0);
  // usleep(SLEEPTIME_SCREEN);

  screen.draw_image(CUP_ADDRESS_HI, CUP_ADDRESS_LO);
  sleep(1);
  screen.draw_image(STAIRS_ADDRESS_HI, STAIRS_ADDRESS_LO);
  sleep(1);
}
