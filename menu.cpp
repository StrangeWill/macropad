#include "menu.hpp"
#include <RotaryEncoder.h>
#include <array>

typedef struct {
  arduino::String label;
} MenuItem;

std::array<MenuItem,6> menuItems {
  (MenuItem) { .label = "Test - 1" },
  (MenuItem) { .label = "Test - 2" },
  (MenuItem) { .label = "Test - 3" },
  (MenuItem) { .label = "Test - 4" },
  (MenuItem) { .label = "Test - 5" },
  (MenuItem) { .label = "Test - 6" }
};

Menu::Menu(Display* display, RotaryEncoder* encoder) : Scene(display, encoder) {
}

Menu::~Menu() {

}

void Menu::render() {
  for(int i = 0; i < menuItems.size(); i++) {
    _display->printText(menuItems[i].label, 0, i * 10, i == _selected ? SH110X_BLACK : SH110X_WHITE, i == _selected ? SH110X_WHITE :SH110X_BLACK);
  }
}

void Menu::input() {
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
}

void Menu::menuUp() {
  if(_selected == menuItems.size() - 1) {
    _selected = 0;
  } else {
    _selected++;
  }
}

void Menu::menuDown() {
  if(_selected == 0) {
    _selected = menuItems.size() - 1;
  } else {
    _selected--;
  }
}