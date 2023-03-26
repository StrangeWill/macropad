#ifndef _MENU_H_
#define _MENU_H_

#include "scene.hpp"
#include <RotaryEncoder.h>

class Menu : public Scene {
  public:
    Menu(Display* display, RotaryEncoder* encoder);
    ~Menu();
    void render();    
    void input();
  private:
    int _selected = 0;
    void menuUp();
    void menuDown();
};

#endif