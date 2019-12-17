#include "screen.h"
#include "version.h"

// 16-bit color March blue converted from 24bit 0x126287
const word MARCH_COLOR = 0x218B;

Screen::Screen(Goldelox_Serial_4DLib* screen, SoftwareSerial* screen_serial,
               uint8_t rst, uint32_t baud)
    : screen_(screen), serial_(screen_serial), rst_(rst), baud_(baud) {
  pinMode(rst, OUTPUT);
}

void Screen::init() {
  this->reset();

  this->serial_->begin(this->baud_);

  // Set screen saver (SS) timeout and scroll speed
  this->screen_->SSTimeout(this->screen_saver_timeout_ms_);
  this->screen_->SSSpeed(this->screen_saver_scroll_speed_);

  this->clear();

  this->screen_->gfx_ScreenMode(PORTRAIT);
  this->printVersion();
  this->mountImages();
  this->screen_->gfx_ScreenMode(LANDSCAPE);

  sleep(5);
  this->clear();

  this->last_draw_time_ = millis();
}

void Screen::clear() {
  this->screen_->gfx_Cls();
  usleep(this->wait_time_ms_);
}

void Screen::reset() {
  digitalWrite(this->rst_, 1);
  usleep(100000);
  digitalWrite(this->rst_, 0);
  usleep(this->wait_time_ms_);
  digitalWrite(this->rst_, 1);

  // Let the display start up
  sleep(3);
}

void Screen::draw_image(word addr_hi, word addr_lo) {
  if ((millis() - this->last_draw_time_) > this->draw_speed_ms_) {
    this->screen_->media_SetSector(addr_hi, addr_lo);
    this->screen_->media_Image(0, 0);
    this->last_draw_time_ = millis();
  }
}

void Screen::printVersion() {
  this->screen_->txt_Bold(ON);
  this->screen_->txt_Width(2);
  this->screen_->txt_Height(2);
  this->screen_->txt_FGcolour(MARCH_COLOR);
  this->screen_->println(ORGANIZATION);
  this->screen_->println("");

  this->screen_->txt_Bold(OFF);
  this->screen_->txt_Width(1);
  this->screen_->txt_Height(1);
  this->screen_->txt_FGcolour(WHITE);
  this->screen_->println(PROJECT_NAME);
  this->screen_->println(VERSION);
  this->screen_->println("");
}

void Screen::mountImages() {
  word initialized = this->screen_->media_Init();
  if (initialized != Err4D_OK) {
    this->screen_->txt_FGcolour(RED);
    this->screen_->println("Pls insert SD");
    while (initialized != Err4D_OK) {
      sleep(1);
      initialized = this->screen_->media_Init();
    }
    this->screen_->txt_FGcolour(WHITE);
    this->screen_->println("Done");
  }
}
