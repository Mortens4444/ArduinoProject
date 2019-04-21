#ifndef KeyPad_h
#define KeyPad_h

#include "Arduino.h"

class KeyPad
{
  public:
    KeyPad(byte, byte, byte, byte);
    
    void Scan();
    bool KeyPressed();
    char GetKey();

  private:  
    void GetCurrentKey();  
    void SetColumnPinStates(byte);
    void GetRowPinStates(byte);

    char keys[4][4] =
      {
        { '1', '2', '3', 'A' },
        { '4', '5', '6', 'B' },
        { '7', '8', '9', 'C' },
        { '*', '0', '#', 'D' }
      };

    byte rows;
    byte columns;
    byte rowStartPin;
    byte columnStartPin;
    unsigned long lastKeyPressedTime;
  
    char oldKey;
    char currentKey;
    bool keyPressed;
    volatile unsigned short resetCounter;
};

#endif
