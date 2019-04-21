#ifndef Morse_h
#define Morse_h

#include "Arduino.h"
#include "LedController.h"
#include "Signal.h"

#include <ctype.h>
#include <stdio.h>

struct charMorseCode
{
  char ch;
  Signal* code;
  byte length;
};

class Morse
{
  public:
    Morse(byte);
    ~Morse();

    void Dot();
    void Dash();
    void DeleteLastWord();
    void Text(String);

    void UnitSeparator();
    void LongUnitSeparator();
    void CharSeparator();
    void WordSeparator();

    static const charMorseCode A;
    static const charMorseCode B;
    static const charMorseCode C;
    static const charMorseCode D;
    static const charMorseCode E;
    static const charMorseCode F;
    static const charMorseCode G;
    static const charMorseCode H;
    static const charMorseCode I;
    static const charMorseCode J;
    static const charMorseCode K;
    static const charMorseCode L;
    static const charMorseCode M;
    static const charMorseCode N;
    static const charMorseCode O;
    static const charMorseCode P;
    static const charMorseCode Q;
    static const charMorseCode R;
    static const charMorseCode S;
    static const charMorseCode T;
    static const charMorseCode U;
    static const charMorseCode V;
    static const charMorseCode W;
    static const charMorseCode X;
    static const charMorseCode Y;
    static const charMorseCode Z;
    
    static const charMorseCode _1;
    static const charMorseCode _2;
    static const charMorseCode _3;
    static const charMorseCode _4;
    static const charMorseCode _5;
    static const charMorseCode _6;
    static const charMorseCode _7;
    static const charMorseCode _8;
    static const charMorseCode _9;
    static const charMorseCode _0;
    static const charMorseCode QUESTION_MARK;    

    static const int MORSE_CODE_TABLE_LENGTH = 37;
    static const charMorseCode morseCodeTable[MORSE_CODE_TABLE_LENGTH];
    
  private:
    void Di();
    void Dah();
    charMorseCode Search(char);
    void Play(charMorseCode);    
  
    static const char SPACE = ' ';
    static const int SHORT_MORSE_UNIT = 250;
    static const int LONG_MORSE_UNIT = SHORT_MORSE_UNIT * 3;
    static const int CHARACTER_WAIT = SHORT_MORSE_UNIT * 3;
    static const int WORD_WAIT = SHORT_MORSE_UNIT * 7;
    
    LedController *ledController;
};

#endif
