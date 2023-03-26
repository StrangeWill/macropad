#include "n1mm.hpp"
#include "scene.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>
#include <Mouse.h>
#include <Keyboard.h>

N1MM::N1MM(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels, Scene* menu) : Scene(display, encoder, pixels) {
  _menu = menu;
}

N1MM::~N1MM() {

}

void N1MM::render() {
  _display->printText("N1MM Mode", 0, 0);
  _pixels->setBrightness(25);
  for(int i=0; i< _pixels->numPixels(); i++) {
    _pixels->setPixelColor(i, 0, 0, 255); 
  }

  _pixels->show();

  delay(100);
}

Scene* N1MM::input(int keyNum) {
  int newPos = _encoder->getPosition(); //If it changed position
  if (_encoder_pos != newPos) {
    switch (_encoder->getDirection()){  //Switch on getDirection and increment scroll wheel 1 in correct direction
      case RotaryEncoder::Direction::NOROTATION:
        break;
      case RotaryEncoder::Direction::CLOCKWISE:
        Mouse.move(0,0,1);
        break;
      case RotaryEncoder::Direction::COUNTERCLOCKWISE:
        Mouse.move(0,0,-1);
        break;
    }

    _encoder_pos = newPos;
  }

  switch (keyNum) {
    case 0: 
      delay(1000);
      return _menu;
    case 1:
      Keyboard.write(193+keyNum);
      delay(500);
      break;
    case 2:
      Keyboard.write(KEY_F2);
      delay(500);
      break;
    case 3:
      Keyboard.write(KEY_F3);
      delay(500);
      break;
    case 4:
      Keyboard.write(KEY_F4);
      delay(500);
      break;
    case 5:
      Keyboard.write(KEY_F5);
      delay(500);
      break;
    case 6:
      Keyboard.write(KEY_F6);
      delay(500);
      break;
    case 7:
      Keyboard.write(KEY_F7);
      delay(500);
      break;
    case 8:
      Keyboard.write(KEY_F8);
      delay(500);
      break;
    case 9:
      Keyboard.write(KEY_F8);
      delay(500);
      break;
    case 10:
      Keyboard.write(KEY_F8);
      delay(500);
      break;
    case 11:
      Keyboard.write(KEY_F8);
      delay(500);
      break;
    case 12:
      Keyboard.write(KEY_F12);
      delay(500);
  }  

  return NULL; 
}