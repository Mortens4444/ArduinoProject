#include "LedTube.h"

      // SSL Pin numbers
      // 10 9 8 7 6
      //
      //     AA
      //    F  B
      //     GG
      //    E  C
      //     DD
      //
      // 1 2 3 4 5

// Arduino Pin startPin to Seven Segment LED (SSL) Pin 9.
// Arduino Pin startPin + 1 to SSL Pin 10.
// Arduino Pin startPin + 2 to SSL Pin 4.
// Arduino Pin startPin + 3 to SSL Pin 2.
// Arduino Pin startPin + 4 to SSL Pin 1.
// Arduino Pin startPin + 6 to SSL Pin 7.
// Arduino Pin startPin + 7 to SSL Pin 6.
// Arduino GND to SSL Pin 3 and SSL Pin 8 each connected with 220 ohm resistors.

/*Arduino Pin 2 to Pin 7.
Arduino Pin 3 to Pin 6.
Arduino Pin 4 to Pin 4.
Arduino Pin 5 to Pin 2.
Arduino Pin 6 to Pin 1.
Arduino Pin 8 to Pin 9.
Arduino Pin 9 to Pin 10.
GND to Pin 3 and Pin 8 each connected with 220 ohm resistors.*/
                                                                // A, B, C, D, E, F, G 
const struct sevenSegments LedTube::A = { .ch = 'A', .segments = { 1, 1, 1, 0, 1, 1, 1 } };
const struct sevenSegments LedTube::B = { .ch = 'B', .segments = { 0, 0, 1, 1, 1, 1, 1 } };
const struct sevenSegments LedTube::C = { .ch = 'C', .segments = { 1, 0, 0, 1, 1, 1, 0 } };
const struct sevenSegments LedTube::D = { .ch = 'D', .segments = { 1, 1, 1, 1, 1, 1, 0 } };
const struct sevenSegments LedTube::E = { .ch = 'E', .segments = { 1, 0, 0, 1, 1, 1, 1 } };
const struct sevenSegments LedTube::F = { .ch = 'F', .segments = { 1, 0, 0, 0, 1, 1, 1 } };
const struct sevenSegments LedTube::G = { .ch = 'G', .segments = { 1, 0, 1, 1, 1, 1, 0 } };
const struct sevenSegments LedTube::H = { .ch = 'H', .segments = { 0, 1, 1, 0, 1, 1, 1 } };
const struct sevenSegments LedTube::I = { .ch = 'I', .segments = { 0, 1, 1, 0, 0, 0, 0 } };
const struct sevenSegments LedTube::J = { .ch = 'J', .segments = { 0, 1, 1, 1, 0, 0, 0 } };
const struct sevenSegments LedTube::L = { .ch = 'L', .segments = { 0, 0, 0, 1, 1, 1, 0 } };
const struct sevenSegments LedTube::N = { .ch = 'N', .segments = { 0, 0, 1, 0, 1, 0, 1 } };
const struct sevenSegments LedTube::O = { .ch = 'O', .segments = { 0, 0, 1, 1, 1, 0, 1 } };
const struct sevenSegments LedTube::P = { .ch = 'P', .segments = { 1, 1, 0, 0, 1, 1, 1 } };
const struct sevenSegments LedTube::Q = { .ch = 'Q', .segments = { 1, 1, 1, 0, 0, 1, 1 } };
const struct sevenSegments LedTube::R = { .ch = 'R', .segments = { 1, 1, 1, 0, 1, 1, 1 } };
const struct sevenSegments LedTube::S = { .ch = 'S', .segments = { 1, 0, 1, 1, 0, 1, 1 } };
const struct sevenSegments LedTube::U = { .ch = 'U', .segments = { 0, 1, 1, 1, 1, 1, 0 } };
const struct sevenSegments LedTube::V = { .ch = 'V', .segments = { 0, 0, 1, 1, 1, 0, 0 } };
const struct sevenSegments LedTube::Y = { .ch = 'Y', .segments = { 0, 1, 1, 0, 0, 1, 1 } };
const struct sevenSegments LedTube::Z = { .ch = 'Z', .segments = { 1, 1, 0, 1, 1, 0, 1 } };
const struct sevenSegments LedTube::SPACE = { .ch = ' ', .segments = { 0, 0, 0, 0, 0, 0, 0 } };

const struct sevenSegments LedTube::_1 = { .ch = '1', .segments = { 0, 1, 1, 0, 0, 0, 0 } };
const struct sevenSegments LedTube::_2 = { .ch = '2', .segments = { 1, 1, 0, 1, 1, 0, 1 } };
const struct sevenSegments LedTube::_3 = { .ch = '3', .segments = { 1, 1, 1, 1, 0, 0, 1 } };
const struct sevenSegments LedTube::_4 = { .ch = '4', .segments = { 0, 1, 1, 0, 0, 1, 1 } };
const struct sevenSegments LedTube::_5 = { .ch = '5', .segments = { 1, 0, 1, 1, 0, 1, 1 } };
const struct sevenSegments LedTube::_6 = { .ch = '6', .segments = { 1, 0, 1, 1, 1, 1, 1 } };
const struct sevenSegments LedTube::_7 = { .ch = '7', .segments = { 1, 1, 1, 0, 0, 0, 0 } };
const struct sevenSegments LedTube::_8 = { .ch = '8', .segments = { 1, 1, 1, 1, 1, 1, 1 } };
const struct sevenSegments LedTube::_9 = { .ch = '9', .segments = { 1, 1, 1, 0, 0, 1, 1 } };
const struct sevenSegments LedTube::_0 = { .ch = '0', .segments = { 1, 1, 1, 1, 1, 1, 0 } };

const sevenSegments LedTube::sevenSegmentsTable[] =
{
  LedTube::A, LedTube::B, LedTube::C, LedTube::D, LedTube::E, LedTube::F, LedTube::G, LedTube::H, LedTube::I, LedTube::J, LedTube::L, LedTube::N, LedTube::O, LedTube::P, LedTube::Q, LedTube::R, LedTube::S, LedTube::U, LedTube::V, LedTube::Y, LedTube::Z,
  LedTube::_1, LedTube::_2, LedTube::_3, LedTube::_4, LedTube::_5, LedTube::_6, LedTube::_7, LedTube::_8, LedTube::_9, LedTube::_0, LedTube::SPACE
};

LedTube::LedTube(byte startPin)
{
  this->startPin = startPin;
  pinMode(startPin, OUTPUT); // 
  pinMode(startPin + 1, OUTPUT);
  pinMode(startPin + 2, OUTPUT);
  pinMode(startPin + 3, OUTPUT);
  pinMode(startPin + 4, OUTPUT);
  pinMode(startPin + 5, OUTPUT);
  pinMode(startPin + 6, OUTPUT);
  pinMode(startPin + 7, OUTPUT);  
}

void LedTube::DotOn()
{
  digitalWrite(startPin + 7, HIGH);
}

void LedTube::DotOff()
{
  digitalWrite(startPin + 7, LOW);
}

void LedTube::Show(char ch)
{
  sevenSegments segments = Search(ch);
  
  if (ch == '.')
  {
    DotOn();
  }
  else if (ch == ' ')
  {
    DotOff();
  }
  
  for (size_t i = 0; i < 7; i++)
  {
    byte value = segments.segments[i];
    digitalWrite(startPin + i, value);
  }
  delay(500);
}

void LedTube::Show(String text)
{
  for (size_t i = 0; i < text.length(); i++)
  {
    Show(text[i]);
  }
}

sevenSegments LedTube::Search(char ch)
{
  char upperCaseCh = toupper(ch);
  for (int i = 0; i < SEVEN_SEGMENTS_TABLE_LENGTH; i++)
  {
    if (sevenSegmentsTable[i].ch == upperCaseCh)
    {
      return sevenSegmentsTable[i];
    }
  }
  return sevenSegmentsTable[SEVEN_SEGMENTS_TABLE_LENGTH - 1];
}
