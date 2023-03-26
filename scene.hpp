#ifndef _SCENE_H_
#define _SCENE_H_

#include "display.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>

class Scene {
  public: 
    Scene(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels) {
      _display = display;
      _encoder = encoder;
      _pixels = pixels;
    }
    virtual void render();
    virtual Scene* input(int keyNum);
  protected:
    Display* _display = NULL;
    RotaryEncoder* _encoder = NULL;
    Adafruit_NeoPixel* _pixels = NULL;
    int _encoder_pos = 0;
};

#endif