/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include "SPI.h"
#include "SD.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Adafruit_ImageReader.h" // Image-reading functions

//On-board SD + TFT connector
#define _cs   14  // goes to TFT CS
#define _dc   27  // goes to TFT DC
#define _mosi 23  // goes to TFT MOSI
#define _sclk 18  // goes to TFT SCK/CLK
#define _rst  33  // goes to TFT RESET
#define _miso 19  // Not connected
#define _sd_cs 4 // goes to TFT SD_CS

//       3.3V     // Goes to TFT LED  
//       5v       // Goes to TFT Vcc
//       Gnd      // Goes to TFT Gnd        

// Use hardware SPI
Adafruit_ILI9341 tft = Adafruit_ILI9341(_cs, _dc, _rst);
Adafruit_ImageReader reader;     // Class w/image-reading functions

// If using software SPI change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(_cs, _dc, _mosi, _sclk, _rst);

void setup() {
  Serial.begin(115200);
  Serial.println("setup() started"); 
 
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);

  Serial.print("Initializing SD card...");
  if (!SD.begin(_sd_cs, SPI, 1000000000)) {              //ili9341 screen turns white and wont respond anymore until it resets...
    Serial.println("Initialization Failed");
  }
  Serial.println("Initialization done.");

}

void loop(void) {
  reader.drawBMP("/stairs2.bmp", tft, 0, 0);
  reader.drawBMP("/sofa2.bmp", tft, 0, 0);
}

