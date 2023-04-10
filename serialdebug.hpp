#ifndef _SERIALDEBUG_H_
#define _SERIALDEBUG_H_

#include "scene.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>

class SerialDebug : public Scene {
  public:
    SerialDebug(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels, Scene* menu);
    ~SerialDebug();
    void render();    
    Scene* input(int keyNum);
  private:
    Scene* _menu;
};

#endif