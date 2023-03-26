#ifndef _MENU_H_
#define _MENU_H_

#include "scene.hpp"
#include <RotaryEncoder.h>
#include <array>
#include <Adafruit_NeoPixel.h>

typedef struct {
  arduino::String label;
  Scene* scene;
} MenuItem;

class Menu : public Scene {
  public:
    Menu(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels);
    ~Menu();
    void render();    
    Scene* input(int keyNum);
  private:
    int _selected = 0;
    void menuUp();
    void menuDown();
    std::array<MenuItem,6> _menuItems;
};

#endif