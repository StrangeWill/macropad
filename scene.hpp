#ifndef _SCENE_H_
#define _SCENE_H_

#include "display.hpp"
#include <RotaryEncoder.h>

class Scene {
  public: 
    Scene(Display* display, RotaryEncoder* encoder) {
      _display = display;
      _encoder = encoder;      
    }
    virtual void render();
    virtual void input();
  protected:
    Display* _display = NULL;
    RotaryEncoder* _encoder;
    int _encoder_pos = 0;
};

#endif