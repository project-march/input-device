#include "Screen.h"

Screen::Screen(Goldelox_Serial_4DLib * screen, SoftwareSerial * screenSerial, int rst, int baud)
{
    this->m_serial = screenSerial;
    this->m_screen = screen;
    this->m_mediaInitialized = 0;
    this->m_baud = baud;
    this->m_rst = rst;
}

void Screen::initialize(){

    digitalWrite(m_rst, 1);

    m_serial->begin(m_baud);

    this->reset();

    m_mediaInitialized = m_screen->media_Init();
    usleep(m_waitTimeUs);

    char str[100];
    sprintf(str, "SD Init status = 0x%02X\n", m_mediaInitialized);
    m_screen->print(str);
    usleep(m_waitTimeUs);

    this->clear();
};

void Screen::clear(){
    m_screen->gfx_Cls();
    usleep(m_waitTimeUs);
}

void Screen::reset(){
    digitalWrite(m_rst, 0);
    usleep(m_waitTimeUs);

    digitalWrite(m_rst, 1);
    sleep(3);
};

void Screen::draw_image(int addr_hi, int addr_lo){
    m_screen->media_SetSector(addr_hi, addr_lo);
    m_screen->media_Image(0,0);
    usleep(m_waitTimeUs);
}
