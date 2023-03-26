#ifndef _N1MM_H_
#define _N1MM_H_

#include "scene.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>

class N1MM : public Scene {
  public:
    N1MM(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels, Scene* menu);
    ~N1MM();
    void render();    
    Scene* input(int keyNum);
  private:
    Scene* _menu;
};

#endif