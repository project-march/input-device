/* * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *\
 *  Library implementing the software interface for a 4D Systems uOLED-160G2 microOLED  *
 *      GOLDELOX Display.                                                               *
 *  Hardware consists of a screen with a set of ten pins on the back.                   *
 *      Pins "+5V" and "GND" should be connected to their respective voltages.          *
 *      Pin "RES" should be connected to a digital output pin.                          *
 *      Pins "RX" and "TX" should be connected to the pins of a UART peripheral         *
 *          interface. Note that the "RX" pin of the screen should be connected to the  *
 *          "TX" pin of the UART interface, and vice versa.                             *
 *      The other pins should be unconnected.                                           *
 *          ┌────────────────────┐                                                      *
 *          │         3.3V ──O O─┼── RES                                                *
 *          │          GND ──O O─┼── GND                                                *
 *          │          IO1 ──O O─┼── RX                                                 *
 *          │          IO2 ──O O─┼── TX                                                 *
 *          │       5V OUT ──O O─┼── +5V                                                *
 *          │                    │                                                      *
 *          │                    │                                                      *
 *          │                    │                                                      *
 *          └────────────────────┘                                                      *
 *                                                                                      *
 * Created by P. Verton and M. van der Marel for Project MARCH                          *
 * Date: 27-MAR-2018                                                                    *
\* * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * */

#ifndef SCREEN_
#define SCREEN_
#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Goldelox_Serial_4DLib.h"

class Screen
{
public:
//Constructors
    Screen(Goldelox_Serial_4DLib * screen, SoftwareSerial * screenSerial, int rst, int baud, int waitTimeUs);

//Public member functions
    void initialize();
    void clear();
    void reset();
    void draw_image(int addr_hi, int addr_lo);

private:
    SoftwareSerial *            m_serial;
    Goldelox_Serial_4DLib *     m_screen;
    int                         m_mediaInitialized;
    int                         m_baud;
    int                         m_rst;
    int                         m_tx;
    int                         m_rx;
    int                         m_waitTimeUs;

};

#endif //SCREEN_