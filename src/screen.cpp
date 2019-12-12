#include "screen.h"

Screen::Screen(Goldelox_Serial_4DLib* screen, SoftwareSerial* screen_serial,
               uint8_t rst, uint32_t baud)
    : screen_(screen), serial_(screen_serial), rst_(rst), baud_(baud) {}

void Screen::initialize() {
  digitalWrite(this->rst_, 1);

  serial_->begin(this->baud_);

  this->reset();

  this->media_initialized_ = this->screen_->media_Init();
  usleep(this->wait_time_ms_);

  this->clear();

  this->last_draw_time_ = millis();
}

void Screen::clear() {
  this->screen_->gfx_Cls();
  usleep(this->wait_time_ms_);
}

void Screen::reset() {
  digitalWrite(this->rst_, 0);
  usleep(this->wait_time_ms_);

  digitalWrite(this->rst_, 1);
  sleep(3);
}

void Screen::draw_image(word addr_hi, word addr_lo) {
  if ((millis() - this->last_draw_time_) * 1000 > this->wait_time_ms_) {
    screen_->media_SetSector(addr_hi, addr_lo);
    screen_->media_Image(0, 0);
    this->last_draw_time_ = millis();
  }
}
