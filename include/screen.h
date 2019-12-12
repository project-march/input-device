/* * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * *
* * * * *\
 *  Library implementing the software interface for a 4D Systems uOLED-160G2
microOLED  *
 *      GOLDELOX Display. *
 *  Hardware consists of a screen with a set of ten pins on the back. *
 *      Pins "+5V" and "GND" should be connected to their respective voltages. *
 *      Pin "RES" should be connected to a digital output pin. *
 *      Pins "RX" and "TX" should be connected to the pins of a UART peripheral
*
 *          interface. Note that the "RX" pin of the screen should be connected
to the  *
 *          "TX" pin of the UART interface, and vice versa. *
 *      The other pins should be unconnected. *
 *          ┌────────────────────┐ *
 *          │         3.3V ──O O─┼── RES *
 *          │          GND ──O O─┼── GND *
 *          │          IO1 ──O O─┼── RX *
 *          │          IO2 ──O O─┼── TX *
 *          │       5V OUT ──O O─┼── +5V *
 *          │                    │ *
 *          │                    │ *
 *          │                    │ *
 *          └────────────────────┘ *
 * *
 * Created by P. Verton and M. van der Marel for Project MARCH *
 * Date: 27-MAR-2018 *
\* * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * *
* * * * */
#ifndef SCREEN_H
#define SCREEN_H
#include <Arduino.h>
#include <Goldelox_Serial_4DLib.h>
#include <SoftwareSerial.h>

class Screen {
public:
  // Constructors
  Screen(Goldelox_Serial_4DLib* screen, SoftwareSerial* screen_serial,
         uint8_t rst, uint32_t baud);

  // Public member functions
  void initialize();
  void clear();
  void reset();
  void draw_image(word addr_hi, word addr_lo);

private:
  Goldelox_Serial_4DLib* screen_;
  SoftwareSerial* serial_;
  word media_initialized_ = 0;
  unsigned long last_draw_time_ = 0;

  const uint8_t rst_;
  const uint32_t baud_;

  const useconds_t wait_time_ms_ =
      500000; // Needed for functioning, can still be optimized
};

#endif // SCREEN_H