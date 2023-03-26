#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Adafruit_SH110X.h>

class Display {
  public:
    Display();
    void clear();
    void printText(arduino::String text, int16_t x, int16_t y);
    void printText(arduino::String text, int16_t x, int16_t y, uint16_t color, uint16_t backgroundColor);
  private:
    Adafruit_SH1106G* _display = NULL;
};

#endif