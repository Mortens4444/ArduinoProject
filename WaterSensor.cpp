#include "WaterSensor.h"

WaterSensor::WaterSensor(byte analogPin)
{
  this->analogPin = analogPin;
}

void WaterSensor::CheckWaterLevel()
{
  waterLevel = -(analogRead(analogPin) - 1023);
  isWaterDetected = waterLevel > 0;
}

