#include "Screen.h"

//Constructors
Screen::Screen(Goldelox_Serial_4DLib * screen, SoftwareSerial * screenSerial, int rst, int baud, int waitTimeUs)
{
    // Serial.println("Constructor");
    
    // this->m_serial = new SoftwareSerial(rx, tx);
    // this->m_screen = new Goldelox_Serial_4DLib(m_serial);

    this->m_serial = screenSerial;
    this->m_screen = screen;
    this->m_mediaInitialized = 0;
    this->m_baud = baud;
    this->m_rst = rst;
    this->m_waitTimeUs = waitTimeUs;

    // Serial.println("Constructor done");
}

void Screen::initialize(){

    // Serial.println("Initialize");

    // pinMode(m_rst, OUTPUT);
    digitalWrite(m_rst, 1);
    // pinMode(m_tx, OUTPUT);
    // pinMode(m_rx, INPUT);
    // usleep(m_waitTimeUs);

    // Serial.println("Starting screenserial");
    m_serial->begin(m_baud);
    // usleep(m_waitTimeUs);

    // Serial.println("Resetting screen");

    this->reset();

    // Serial.println("Initing media");

    m_mediaInitialized = m_screen->media_Init();
    usleep(m_waitTimeUs);

    char str[100];
    sprintf(str, "SD Init status = 0x%02X\n", m_mediaInitialized);
    m_screen->print(str);
    usleep(m_waitTimeUs);

    this->clear();

    // Serial.println("Initialization done");
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
    // usleep(m_waitTimeUs);

    m_screen->media_Image(0,0);
    usleep(m_waitTimeUs);
}
