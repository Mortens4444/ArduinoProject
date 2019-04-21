#ifndef UltraSonicSensor_h
#define UltraSonicSensor_h

#include "Arduino.h"

#include <stdlib.h>

class UltraSonicSensor
{
  public:
    UltraSonicSensor(byte, byte);
    
    unsigned long GetPulseLengthInMicroseconds();
    unsigned long GetDistanceInCentimeters();
    unsigned long GetDistanceInInches();
    
  private:
    double GetTemperatureInCelsius();
    double GetSpeedOfSound();

    byte sensorEchoPin;
    byte sensorTrigPin;
};

#endif
