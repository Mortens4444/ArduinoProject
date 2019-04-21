#ifndef LedController_h
#define LedController_h

#include "Arduino.h"

class LedController
{
  public:
    LedController(byte);
    
    void On();
    void Off();
    void Toggle();
    void Blink();

  private:
    byte pin;
    bool isOn;
};

#endif
