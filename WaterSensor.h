#ifndef WaterSensor_h
#define WaterSensor_h

#include "Arduino.h"

class WaterSensor
{
  public:
    WaterSensor(byte);
    
    void CheckWaterLevel();
    
    int waterLevel;
    bool isWaterDetected;

  private:
    byte analogPin;
};

#endif
