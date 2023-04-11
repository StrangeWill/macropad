#include "serialdebug.hpp"
#include "scene.hpp"
#include <RotaryEncoder.h>
#include <Adafruit_NeoPixel.h>


SerialDebug::SerialDebug(Display* display, RotaryEncoder* encoder, Adafruit_NeoPixel* pixels, Scene* menu) : Scene(display, encoder, pixels) {
  _menu = menu;
}

SerialDebug::~SerialDebug() {

}

void SerialDebug::render() {
  _display->printText(arduino::String(Serial.availableForWrite()), 0, 10);
  _display->printText(arduino::String(millis()), 0, 20);
  Serial.write("ZZFA;");

  auto input = Serial.readString();
  if(input.length() != 0) {
    _display->printText("                   ", 0, 0);
    _display->printText(input, 0, 0);
  }

  _pixels->setBrightness(0);
  for(int i = 0; i < _pixels->numPixels(); i++) {
    _pixels->setPixelColor(i, 255, 255, 255); 
  }

  _pixels->show();
  delay(1000);
}

Scene* SerialDebug::input(int keyNum) {
  if(keyNum == 0) {
    delay(1000);
    return _menu;
  }

  return NULL;
}