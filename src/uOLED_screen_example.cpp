#include "Screen.h"
#include "SoftwareSerial.h"

#define UART_TX 32 //software serial only
#define UART_RX 34 //software serial only
#define RST 13

void screenReset();
int display_image(Goldelox_Serial_4DLib display, int sectorMode, uint32_t address, int16_t X, int16_t Y);

// SoftwareSerial screenSerial(UART_RX, UART_TX);
// Goldelox_Serial_4DLib display(&screenSerial);
bool mediaInitialized;

void setup() {
  Serial.begin(115200);
  Serial.println("setup() started");

  pinMode(RST, OUTPUT);
  digitalWrite(RST, 0);
  pinMode(UART_TX, OUTPUT);
  pinMode(UART_RX, INPUT);

  SoftwareSerial screenSerial(UART_RX, UART_TX);
  screenSerial.begin(9600);
  Goldelox_Serial_4DLib display(&screenSerial);
  mediaInitialized = false;
  // display.TimeLimit4D = 5000;

  Serial.println("Resetting screen");
  screenReset();
  Serial.println("Setting screen mode to Landscape");
  display.gfx_ScreenMode(LANDSCAPE);
  // display.SSTimeout(0);
  // display.SSSpeed(0);
  // display.SSMode(0);
  Serial.println("Changing background color to white");
  display.gfx_BGcolour(WHITE); //change background color to white
  // display.gfx_Cls();            //clear the screen
  // Serial.println("Printing sector with address 0");
  // display_image(display, 1, 0x00000000, 0, 0);

  // Screen screen(RST, UART_TX, UART_RX, 56000);
  // Serial.println("Starting initialize");
  // screen.initialize();
  Serial.println("setup() done");
}

void loop(void) {
  Serial.println("Loop");
  // display.print("Hello world!");
  // screen.print("Hello world");
  // sleep(1);
  // // screen.initialize();
  // screen.clear();
  // screen.display_image_sector(0x00000000,0,0);
  // display.gfx_Cls();
  // display.print("Hello world in a loop");
  // sleep(1);
  // display_image(display,1,0x00000000,0,0);
  sleep(1);
}

void screenReset(){
  digitalWrite(RST, 1);
  usleep(10000);
  digitalWrite(RST, 0);
  // sleep(3);
}

int display_image(Goldelox_Serial_4DLib display, int sectorMode, uint32_t address, int16_t X, int16_t Y){
    uint16_t response = 0;
    if(!mediaInitialized){
        response = display.media_Init();
        if(response != 0){
            mediaInitialized = true;
        }
        else{
            return -1;
        }
    }
    if(sectorMode){
        display.media_SetSector(address >> 16, address & 0xFFFF);
    }
    else{
        display.media_SetAdd(address >> 16, address & 0xFFFF);
    }
    if(X || Y){
        display.gfx_Clipping(1);
    }
    display.media_Image(X, Y);
    return 0;
};