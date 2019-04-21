#include "CarbonMonoxidSensor.h"

CarbonMonoxidSensor::CarbonMonoxidSensor(byte analogOutPin, byte digitalOutPin)
{
  pinMode(digitalOutPin, INPUT);
  this->analogOutPin = analogOutPin;
  this->digitalOutPin = digitalOutPin;
}

void CarbonMonoxidSensor::Check()
{
  carbonMonoxidLevel = analogRead(analogOutPin);
  int limit= digitalRead(digitalOutPin);
  isLimitReached = limit == LOW;
}
