#ifndef CarbonMonoxidSensor_h
#define CarbonMonoxidSensor_h

#include "Arduino.h"

class CarbonMonoxidSensor
{
  public:
    CarbonMonoxidSensor(byte, byte);
    
    void Check();
    
    bool isLimitReached;
    int carbonMonoxidLevel;

  private:
    byte analogOutPin;
    byte digitalOutPin;
};

#endif
