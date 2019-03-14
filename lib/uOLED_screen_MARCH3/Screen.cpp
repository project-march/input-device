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

// #include "DBS_pindefs.h"
#include "SoftwareSerial.h"
#include "Screen.h"

//Constructors
Screen::Screen(int res, int tx, int rx, int baud)
{
    pinMode(res, OUTPUT);
    pinMode(tx, OUTPUT);
    pinMode(rx, INPUT);
    m_res = res;
    SoftwareSerial * tmp = new SoftwareSerial(tx, rx);
    tmp->begin(baud);
    m_screen = new Goldelox_Serial_4DLib(tmp);
    m_baud = baud;
    this->initialize();
} //Screen(int res, int tx, int rx, int baud)


//Public member functions
void Screen::reset(){
    digitalWrite(this->m_res, 0);
    usleep(10000);
    digitalWrite(this->m_res, 1);
    sleep(3);
    return;
}; //reset()

void Screen::clear(){
    this->m_screen->gfx_Cls();
    return;
}; //clear()

void Screen::print(char * string){
    this->m_screen->gfx_ScreenMode(PORTRAIT_R);
    this->m_screen->putstr(string);
    this->m_screen->gfx_ScreenMode(LANDSCAPE);
    return;
}; //print(char * string)

int Screen::display_image_sector(uint32_t sector, int16_t X, int16_t Y){
    return this->display_image_any(1, sector, X, Y);
};

int Screen::display_image_byte(uint32_t byte, int16_t X, int16_t Y){
    return this->display_image_any(0, byte, X, Y);
};

//Private member functions
void Screen::initialize(){
    this->m_mediaInitialized = false;
    this->reset();
    this->m_screen->gfx_ScreenMode(LANDSCAPE);
    this->m_screen->gfx_Cls();
    return;
} //initialize()

int Screen::display_image_any(int sectorMode, uint32_t address, int16_t X, int16_t Y){
    uint16_t response = 0;
    if(!this->m_mediaInitialized){
        response = this->m_screen->media_Init();
        if(response != 0){
            this->m_mediaInitialized = true;
        }
        else{
            return -1;
        }
    }
    if(sectorMode){
        this->m_screen->media_SetSector(address >> 16, address & 0xFFFF);
    }
    else{
        this->m_screen->media_SetAdd(address >> 16, address & 0xFFFF);
    }
    if(X || Y){
        this->m_screen->gfx_Clipping(1);
    }
    this->m_screen->media_Image(X, Y);
    return 0;
}; //display_image_any(int sectorMode, uint32_t address, int16_t X, int16_t Y)