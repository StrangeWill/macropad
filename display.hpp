#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Adafruit_SH110X.h>

class Display {
  public:
    Display();
    void drawMenu();
    void printText(arduino::String text, int16_t x, int16_t y);
    void printText(arduino::String text, int16_t x, int16_t y, uint16_t color, uint16_t backgroundColor);
    void menuUp();
    void menuDown();
  private:
    Adafruit_SH1106G* _display = NULL;
    int _selected = 0;
};

#endif