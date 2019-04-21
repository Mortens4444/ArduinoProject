#include "Morse.h"

Signal morseCodeA[] = { DI, DAH };
Signal morseCodeB[] = { DAH, DI, DI, DI };
Signal morseCodeC[] = { DAH, DI, DAH, DI };
Signal morseCodeD[] = { DAH, DI, DI };
Signal morseCodeE[] = { DI };
Signal morseCodeF[] = { DI, DI, DAH, DI };
Signal morseCodeG[] = { DAH, DAH, DI };
Signal morseCodeH[] = { DI, DI, DI, DI };
Signal morseCodeI[] = { DI, DI };
Signal morseCodeJ[] = { DI, DAH, DAH, DAH };
Signal morseCodeK[] = { DAH, DI, DAH };
Signal morseCodeL[] = { DI, DAH, DI, DI };
Signal morseCodeM[] = { DAH, DAH };
Signal morseCodeN[] = { DAH, DI };
Signal morseCodeO[] = { DAH, DAH, DAH };
Signal morseCodeP[] = { DI, DAH, DAH, DI };
Signal morseCodeQ[] = { DAH, DAH, DI, DAH };
Signal morseCodeR[] = { DI, DAH, DI };
Signal morseCodeS[] = { DI, DI, DI };
Signal morseCodeT[] = { DAH };
Signal morseCodeU[] = { DI, DI, DAH };
Signal morseCodeV[] = { DI, DI, DI, DAH };
Signal morseCodeW[] = { DI, DAH, DAH };
Signal morseCodeX[] = { DAH, DI, DI, DAH };
Signal morseCodeY[] = { DAH, DI, DAH, DAH };
Signal morseCodeZ[] = { DAH, DAH, DI, DI };

Signal morseCode1[] = { DI, DAH, DAH, DAH, DAH };
Signal morseCode2[] = { DI, DI, DAH, DAH, DAH };
Signal morseCode3[] = { DI, DI, DI, DAH, DAH };
Signal morseCode4[] = { DI, DI, DI, DI, DAH };
Signal morseCode5[] = { DI, DI, DI, DI, DI };
Signal morseCode6[] = { DAH, DI, DI, DI, DI };
Signal morseCode7[] = { DAH, DAH, DI, DI, DI };
Signal morseCode8[] = { DAH, DAH, DAH, DI, DI };
Signal morseCode9[] = { DAH, DAH, DAH, DAH, DI };
Signal morseCode0[] = { DAH, DAH, DAH, DAH, DAH };

Signal morseCodeQuestionMark[] = { DI, DI, DAH, DAH, DI, DI };

const struct charMorseCode Morse::A = { .ch = 'A', .code = morseCodeA, .length = 2 };
const struct charMorseCode Morse::B = { .ch = 'B', .code = morseCodeB, .length = 4 };
const struct charMorseCode Morse::C = { .ch = 'C', .code = morseCodeC, .length = 4 };
const struct charMorseCode Morse::D = { .ch = 'D', .code = morseCodeD, .length = 3 };
const struct charMorseCode Morse::E = { .ch = 'E', .code = morseCodeE, .length = 5 };
const struct charMorseCode Morse::F = { .ch = 'F', .code = morseCodeF, .length = 4 };
const struct charMorseCode Morse::G = { .ch = 'G', .code = morseCodeG, .length = 3 };
const struct charMorseCode Morse::H = { .ch = 'H', .code = morseCodeH, .length = 4 };
const struct charMorseCode Morse::I = { .ch = 'I', .code = morseCodeI, .length = 2 };
const struct charMorseCode Morse::J = { .ch = 'J', .code = morseCodeJ, .length = 4 };
const struct charMorseCode Morse::K = { .ch = 'K', .code = morseCodeK, .length = 3 };
const struct charMorseCode Morse::L = { .ch = 'L', .code = morseCodeL, .length = 4 };
const struct charMorseCode Morse::M = { .ch = 'M', .code = morseCodeM, .length = 2 };
const struct charMorseCode Morse::N = { .ch = 'N', .code = morseCodeN, .length = 2 };
const struct charMorseCode Morse::O = { .ch = 'O', .code = morseCodeO, .length = 3 };
const struct charMorseCode Morse::P = { .ch = 'P', .code = morseCodeP, .length = 4 };
const struct charMorseCode Morse::Q = { .ch = 'Q', .code = morseCodeQ, .length = 4 };
const struct charMorseCode Morse::R = { .ch = 'R', .code = morseCodeR, .length = 3 };
const struct charMorseCode Morse::S = { .ch = 'S', .code = morseCodeS, .length = 3 };
const struct charMorseCode Morse::T = { .ch = 'T', .code = morseCodeT, .length = 1 };
const struct charMorseCode Morse::U = { .ch = 'U', .code = morseCodeU, .length = 3 };
const struct charMorseCode Morse::V = { .ch = 'V', .code = morseCodeV, .length = 4 };
const struct charMorseCode Morse::W = { .ch = 'W', .code = morseCodeW, .length = 3 };
const struct charMorseCode Morse::X = { .ch = 'X', .code = morseCodeX, .length = 4 };
const struct charMorseCode Morse::Y = { .ch = 'Y', .code = morseCodeY, .length = 4 };
const struct charMorseCode Morse::Z = { .ch = 'Z', .code = morseCodeZ, .length = 4 };

const struct charMorseCode Morse::_1 = { .ch = '1', .code = morseCode1, .length = 5 };
const struct charMorseCode Morse::_2 = { .ch = '2', .code = morseCode2, .length = 5 };
const struct charMorseCode Morse::_3 = { .ch = '3', .code = morseCode3, .length = 5 };
const struct charMorseCode Morse::_4 = { .ch = '4', .code = morseCode4, .length = 5 };
const struct charMorseCode Morse::_5 = { .ch = '5', .code = morseCode5, .length = 5 };
const struct charMorseCode Morse::_6 = { .ch = '6', .code = morseCode6, .length = 5 };
const struct charMorseCode Morse::_7 = { .ch = '7', .code = morseCode7, .length = 5 };
const struct charMorseCode Morse::_8 = { .ch = '8', .code = morseCode8, .length = 5 };
const struct charMorseCode Morse::_9 = { .ch = '9', .code = morseCode9, .length = 5 };
const struct charMorseCode Morse::_0 = { .ch = '0', .code = morseCode0, .length = 5 };

const struct charMorseCode Morse::QUESTION_MARK = { .ch = '?', .code = morseCodeQuestionMark, .length = 6 };

const charMorseCode Morse::morseCodeTable[] =
{
  Morse::A, Morse::B, Morse::C, Morse::D, Morse::E,
  Morse::F, Morse::G, Morse::H, Morse::I, Morse::J,
  Morse::K, Morse::L, Morse::M, Morse::N, Morse::O,
  Morse::P, Morse::Q, Morse::R, Morse::S, Morse::T,
  Morse::U, Morse::V, Morse::X, Morse::Y, Morse::Z,
  Morse::_1, Morse::_2, Morse::_3, Morse::_4, Morse::_5,
  Morse::_6, Morse::_7, Morse::_8, Morse::_9, Morse::_0, Morse::QUESTION_MARK
};

Morse::Morse(byte pin)
{
  ledController = new LedController(pin);
}

Morse::~Morse()
{
  delete ledController;
}

void Morse::Dot()
{
  ledController->On();
  UnitSeparator();
  ledController->Off();
}

void Morse::Dash()
{
  ledController->On();
  LongUnitSeparator();
  ledController->Off();
}

void Morse::DeleteLastWord()
{
  for (int i = 0; i < 8; i++)
  {
    Di();
  }
}

void Morse::Text(String text)
{
  char ch;
  int i = 0;
  
  while ((ch = text[i]) != '\0')
  {
    if (ch == SPACE)
    {
      WordSeparator();
    }
    else
    {
      charMorseCode morse = Search(ch);
      
      Play(morse);
      if (text[i + 1] != SPACE)
      {
        CharSeparator();
      }
    }
    i++;
  }
}

void Morse::Di()
{
  Dot();
  UnitSeparator();
}

void Morse::Dah()
{
  Dash();
  UnitSeparator();
}

charMorseCode Morse::Search(char ch)
{
  char upperCaseCh = toupper(ch);
  for (int i = 0; i < MORSE_CODE_TABLE_LENGTH; i++)
  {
    if (morseCodeTable[i].ch == upperCaseCh)
    {
      return morseCodeTable[i];
    }
  }
  return morseCodeTable[MORSE_CODE_TABLE_LENGTH - 1];
}

void Morse::Play(charMorseCode morse)
{
    int length = morse.length;
    
    for (int i = 0; i < length; i++)
    {
      if (morse.code[i] == DI)
      {
        Di();
      }
      else
      {
        Dah();
      }
    }
}

void Morse::UnitSeparator()
{
  delay(SHORT_MORSE_UNIT);
}

void Morse::LongUnitSeparator()
{
  delay(LONG_MORSE_UNIT);
}

void Morse::CharSeparator()
{
  delay(CHARACTER_WAIT);
}

void Morse::WordSeparator()
{
  delay(WORD_WAIT);
}
