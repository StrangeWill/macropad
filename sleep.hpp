#ifndef _SLEEP_H_
#define _SLEEP_H_

#include "scene.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>

class Sleep : public Scene {
  public:
    Sleep(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels, Scene* menu);
    ~Sleep();
    void render();    
    Scene* input(int keyNum);
  private:
    Scene* _menu;
};

#endif