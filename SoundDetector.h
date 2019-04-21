#ifndef SoundDetector_h
#define SoundDetector_h

#include "Arduino.h"

#include <stdio.h>

class SoundDetector
{
  public:
    SoundDetector(byte);
    
    void CheckForSound();
    bool soundDetected;
    bool repeatedSoundDetected;
    
  private:
    int pin;
    unsigned long lastSoundDetectionTime;
};

#endif
