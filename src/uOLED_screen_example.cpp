#include "Goldelox_Serial_4DLib.h"
#include "Screen.h"

#define UART_TX 1
#define UART_RX 3
#define RST 13    

Screen screen(RST, UART_TX, UART_RX, 56000);

void setup() {
  Serial.begin(115200);
  Serial.println("setup() started"); 


}

void loop(void) {

}
