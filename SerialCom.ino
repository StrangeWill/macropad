
#include <Adafruit_NeoPixel.h>
#include <RotaryEncoder.h>
#include "display.hpp"
#include "communication.hpp"
#include <Arduino.h>

Display* display = NULL;
Communication* communication = NULL;
auto pixels = Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

RotaryEncoder encoder(PIN_ROTA, PIN_ROTB, RotaryEncoder::LatchMode::FOUR3);
int encoder_pos = 0;

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
  display->drawMenu();
}

void loop() {
  for (int i = 0; i <= 12; i++){
    if (digitalRead(i) == PinStatus::LOW) {
      doKeyPress(i);
    }
  }
  
  display->drawMenu();
  communication->send("DRAW");
  delay(50);
}

void doKeyPress(int keyNum) {
  switch (keyNum) {
    default:
      communication->send("key: " + arduino::String(keyNum));
  }
}

void checkPosition() {  
  encoder.tick();
  int newPos = encoder.getPosition();
  communication->send("pos: " + arduino::String(encoder_pos) + " newPos:" + arduino::String(newPos) + " direction:" + arduino::String((int)encoder.getDirection()));
  if (encoder_pos != newPos) {
    if(encoder_pos > newPos) {
      while(encoder_pos > newPos) {
        display->menuUp();
        encoder_pos--;
      }
    } else {
      while(encoder_pos < newPos) {
        display->menuDown();
        encoder_pos++;
      }
    }
  }
}