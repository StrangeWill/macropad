
#include <Adafruit_NeoPixel.h>
#include <RotaryEncoder.h>
#include "display.hpp"
#include "menu.hpp"
#include "communication.hpp"
#include <Arduino.h>

Scene* scene = NULL;
Display* display = NULL;
Communication* communication = NULL;
auto pixels = Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

RotaryEncoder* encoder = new RotaryEncoder(PIN_ROTA, PIN_ROTB, RotaryEncoder::LatchMode::FOUR3);

void setup() {  
  for (uint8_t i=0; i<=12; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(PIN_ROTA, INPUT_PULLUP);
  pinMode(PIN_ROTB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(18), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(17), checkPosition, CHANGE);

  communication = new Communication();
  pixels.begin();
  pixels.setBrightness(10);
  for(int i=0; i< pixels.numPixels(); i++) {
    pixels.setPixelColor(i, 255, 255, 255); 
  }

  pixels.show();
  display = new Display();
  scene = new Menu(display, encoder);
}

void loop() {
  for (int i = 0; i <= 12; i++){
    if (digitalRead(i) == PinStatus::LOW) {
      doKeyPress(i);
    }
  }
  
  scene->render();
  communication->send("DRAW");
}

void doKeyPress(int keyNum) {
  switch (keyNum) {
    default:
      communication->send("key: " + arduino::String(keyNum));
  }
}

void checkPosition() {
  encoder->tick();
  scene->input();  
}