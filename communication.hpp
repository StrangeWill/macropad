#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include <Arduino.h>

class Communication {
  public:
    Communication();
    void send(arduino::String command);
  private:
    
};

#endif