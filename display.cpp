#include "display.hpp"
#include <Adafruit_SH110X.h>

Display::Display() {
  _display = new Adafruit_SH1106G(128, 64, &SPI1, OLED_DC, OLED_RST, OLED_CS);
  _display->begin(0, true);
  _display->setTextSize(2);
  _display->setTextWrap(false);
  _display->println("INIT");
  _display->setTextColor(SH110X_WHITE, SH110X_BLACK);
  _display->display();
  _display->clearDisplay();
}

void Display::clear() {
  _display->clearDisplay();
  _display->display();
}

void Display::printText(arduino::String text, int16_t x, int16_t y) {
  printText(text, x, y, SH110X_WHITE, SH110X_BLACK);
}

void Display::printText(arduino::String text, int16_t x, int16_t y, uint16_t color, uint16_t backgroundColor) {
  _display->setTextSize(1);
  _display->setTextWrap(false);
  _display->setTextColor(color, backgroundColor);
  _display->setCursor(x, y);
  _display->println(text);
  _display->display();
}