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
 * Created by P. Verton for the MARCH 3 team of Project MARCH                           *
 * Date: 27-MAR-2018                                                                    *
\* * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * */

#ifndef SCREEN_
#define SCREEN_
#include <Arduino.h>
#include "Goldelox_Serial_4DLib.h"

class Screen
{
public:
//Constructors
    Screen(int res, int tx, int rx, int baud = 56000);

//Public member functions
    
    //Resets the screen through the hardware pin
    void reset();
    
    //Clears the screen through the serial communication (quicker)
    void clear();

    //Prints the specified string to the screen.
    //  Formatting can be done with sprintf
    void print(char * string);

    //Displays the image at the specified address and location.
    //  uint32_t    sector              Memory sector where the image starts 
    //  uint32_t    byte                Memory byte address where the image starts
    //  int16_t     X       default = 0 X coordinate where the top left corner of the image 
    //                                  should be (long side being the X axis)
    //  int16_t     Y       default = 0 Y coordinate where the top left corner of the image 
    //                                  should be (short side being the Y axis)
    //
    //  int         return  Status indicating whether it succeeded. 0 means success. 
    //                      -1 indicates sd Card initialisation didn't work 
    //                      everything else indicates unknown error
    int display_image_sector(uint32_t sector,  int16_t X = 0, int16_t Y = 0);
    int display_image_byte(uint32_t byte, int16_t X = 0, int16_t Y = 0);

    //Nice to haves
        /*
        void reinitialize(DEBUG_DEC) //resets device, initializes again
        int test(DEBUG_DEC);    //tests connection
        void text_line_up(DEBUG_DEC);   //moves cursor one line up
        void text_change_color(uint32 colorFore, uint32 colorBack, DEBUG_DEC);
        void text_change_font(int fontIndex);
        void text_change_size(int verticalSize, int horizontalSize);
        void display_video(uint32 sector, int X = 0, int Y = 0, DEBUG_DEC);
        */
private:
//Private member functions
    
    //Initializes the screen and makes sure all settings are correct.
    void initialize();
    //Displays an image in either mode. 
    //  int     sectorMode      Indicates whether to use a sector address or byte address.
    //                              value 1 indicates sector address, value 0 indicates 
    //                              byte address.
    //  byte address
    int display_image_any(int sectorMode, uint32_t address, int16_t X = 0, int16_t Y = 0);

//Private class members
    
    Goldelox_Serial_4DLib * m_screen;
    int m_res;
    int m_baud;
    bool m_mediaInitialized;
}; //class Screen

#endif //SCREEN_