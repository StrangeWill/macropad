#include "communication.hpp"
#include <Arduino.h>

Communication::Communication() {
  Serial.begin(115200);
}

void Communication::send(arduino::String command) {
  Serial.println(command);
}