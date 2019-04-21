#include "UltraSonicSensor.h"

UltraSonicSensor::UltraSonicSensor(byte sensorEchoPin, byte sensorTrigPin)
{
  this->sensorEchoPin = sensorEchoPin;
  this->sensorTrigPin = sensorTrigPin;
  pinMode(sensorEchoPin, INPUT); 
  pinMode(sensorTrigPin, OUTPUT);
}

unsigned long UltraSonicSensor::GetPulseLengthInMicroseconds()
{
  unsigned long pulseLengthInMicroseconds;
  do
  {
    digitalWrite(sensorTrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensorTrigPin,LOW);
    pulseLengthInMicroseconds = pulseIn(sensorEchoPin, HIGH);
  }
  while (pulseLengthInMicroseconds > 170000); // Correct value, because I think it's not good.
  return pulseLengthInMicroseconds;
}

unsigned long UltraSonicSensor::GetDistanceInCentimeters()
{
  unsigned long pulseLengthInMicroseconds = GetPulseLengthInMicroseconds();
  double valueConverter = GetSpeedOfSound() / (double)20000;
  unsigned long distance = long(pulseLengthInMicroseconds * valueConverter);
  return distance;
}

unsigned long UltraSonicSensor::GetDistanceInInches()
{
  return GetDistanceInCentimeters() / 2.54;
}

double UltraSonicSensor::GetTemperatureInCelsius()
{
  return 20;
}

double UltraSonicSensor::GetSpeedOfSound()
{
  return 331.5 + (0.6 * GetTemperatureInCelsius()); // m/s
}

