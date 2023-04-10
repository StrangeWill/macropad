#include "communication.hpp"
#include <Arduino.h>

uint8_t CTS = 4;
uint8_t RTS = 5;

Communication::Communication() {
  Serial.begin(115200);
}

void Communication::send(arduino::String command) {
  Serial.println(command);
}