#ifndef LedTube_h
#define LedTube_h

#include "Arduino.h"

#include <stdlib.h>

struct sevenSegments
{
  char ch;
  byte segments[7];
};

class LedTube
{
  public:
    LedTube(byte);
    
    void DotOn();
    void DotOff();
    void Show(char);
    void Show(String text);

    static const sevenSegments A;
    static const sevenSegments B;
    static const sevenSegments C;
    static const sevenSegments D;
    static const sevenSegments E;
    static const sevenSegments F;
    static const sevenSegments G;
    static const sevenSegments H;
    static const sevenSegments I;
    static const sevenSegments J;
    static const sevenSegments L;
    static const sevenSegments N;
    static const sevenSegments O;
    static const sevenSegments P;
    static const sevenSegments Q;
    static const sevenSegments R;
    static const sevenSegments S;
    static const sevenSegments U;
    static const sevenSegments V;
    static const sevenSegments Y;
    static const sevenSegments Z;
    static const sevenSegments SPACE;

    static const sevenSegments _1;
    static const sevenSegments _2;
    static const sevenSegments _3;
    static const sevenSegments _4;
    static const sevenSegments _5;
    static const sevenSegments _6;
    static const sevenSegments _7;
    static const sevenSegments _8;
    static const sevenSegments _9;
    static const sevenSegments _0;
    
    static const int SEVEN_SEGMENTS_TABLE_LENGTH = 32;
    static const sevenSegments sevenSegmentsTable[SEVEN_SEGMENTS_TABLE_LENGTH];
    
  private:
    sevenSegments Search(char);
    
    byte startPin;
};

#endif
