#include "display.hpp"
#include <array>
#include <Adafruit_SH110X.h>

typedef struct {
  arduino::String label;
} MenuItem;

std::array<MenuItem,6> menuItems {
  (MenuItem) { .label = "Test - 1" },
  (MenuItem) { .label = "Test - 2" },
  (MenuItem) { .label = "Test - 3" },
  (MenuItem) { .label = "Test - 4" },
  (MenuItem) { .label = "Test - 5" },
  (MenuItem) { .label = "Test - 6" }
};

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

void Display::menuUp() {
  if(_selected == menuItems.size() - 1) {
    _selected = 0;
  } else {
    _selected++;
  }
}
void Display::menuDown() {
  if(_selected == 0) {
    _selected = menuItems.size() - 1;
  } else {
    _selected--;
  }
}

void Display::drawMenu() {
  for(int i = 0; i < menuItems.size(); i++) {
    printText(menuItems[i].label, 0, i * 10, i == _selected ? SH110X_BLACK : SH110X_WHITE, i == _selected ? SH110X_WHITE :SH110X_BLACK);
  }
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