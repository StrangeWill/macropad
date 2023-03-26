#include "menu.hpp"
#include "scene.hpp"
#include "sleep.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>
#include <array>

Menu::Menu(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels) : Scene(display, encoder, pixels) {
  _menuItems = {
    (MenuItem) { .label = "Test - 1", .scene = NULL },
    (MenuItem) { .label = "Test - 2", .scene = NULL },
    (MenuItem) { .label = "Test - 3", .scene = NULL },
    (MenuItem) { .label = "Test - 4", .scene = NULL },
    (MenuItem) { .label = "Test - 5", .scene = NULL },
    (MenuItem) { .label = "Sleep", .scene = new Sleep(display, encoder, pixels, this) }
  };
}

Menu::~Menu() {

}

void Menu::render() {  
  _pixels->setBrightness(10);
  for(int i=0; i< _pixels->numPixels(); i++) {
    _pixels->setPixelColor(i, 255, 255, 255); 
  }

  _pixels->show();

  for(int i = 0; i < _menuItems.size(); i++) {
    _display->printText(_menuItems[i].label, 0, i * 10, i == _selected ? SH110X_BLACK : SH110X_WHITE, i == _selected ? SH110X_WHITE :SH110X_BLACK);
  }
}

Scene* Menu::input(int keyNum) {
  int newPos = _encoder->getPosition();
  //communication->send("pos: " + arduino::String(_encoder_pos) + " newPos:" + arduino::String(newPos) + " direction:" + arduino::String((int)encoder.getDirection()));
  if (_encoder_pos != newPos) {
    if(_encoder_pos > newPos) {
      while(_encoder_pos > newPos) {
        menuUp();
        _encoder_pos--;
      }
    } else {
      while(_encoder_pos < newPos) {
        menuDown();
        _encoder_pos++;
      }
    }
  }

  if(keyNum == 0) {
    return _menuItems[_selected].scene; 
  }

  return NULL;
}

void Menu::menuUp() {
  if(_selected == _menuItems.size() - 1) {
    _selected = 0;
  } else {
    _selected++;
  }
}

void Menu::menuDown() {
  if(_selected == 0) {
    _selected = _menuItems.size() - 1;
  } else {
    _selected--;
  }
}