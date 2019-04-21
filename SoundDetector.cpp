#include "SoundDetector.h"

SoundDetector::SoundDetector(byte pin)
{
  pinMode(pin, INPUT);
  this->pin = pin;
  lastSoundDetectionTime = 0;
}

void SoundDetector::CheckForSound()
{
  int soundDetectedVal = analogRead(pin);
  soundDetected = soundDetectedVal == HIGH;
  if (soundDetected)
  {
    unsigned long current = millis();
    long diff = current - lastSoundDetectionTime;
    repeatedSoundDetected = diff < 1500 && diff > 100;
    lastSoundDetectionTime = current;
    if (repeatedSoundDetected)
    {
      lastSoundDetectionTime = 0;
    }
  }
  else
  {
    repeatedSoundDetected = false;
  }
}
