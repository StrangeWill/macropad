#include "sleep.hpp"
#include "scene.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>

Sleep::Sleep(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels, Scene* menu) : Scene(display, encoder, pixels) {
  _menu = menu;
}

Sleep::~Sleep() {

}

void Sleep::render() {
  _display->clear();
  _pixels->setBrightness(0);
  for(int i=0; i< _pixels->numPixels(); i++) {
    _pixels->setPixelColor(i, 255, 255, 255); 
  }

  _pixels->show();
  delay(1000);
}

Scene* Sleep::input(int keyNum) {
  if(keyNum == 0) {
    delay(1000);
    return _menu;
  }

  return NULL;
}