#include "KeyPad.h"

KeyPad::KeyPad(byte rows, byte columns, byte rowStartPin, byte columnStartPin)
{
  this->rows = rows;
  this->columns = columns;
  this->rowStartPin = rowStartPin;
  this->columnStartPin = columnStartPin;
  
  for (byte pin = columnStartPin; pin < columnStartPin + columns; pin++)
  {
    pinMode(pin, OUTPUT);
  }
  for (byte pin = rowStartPin; pin < rowStartPin + rows; pin++)
  {
    pinMode(pin, INPUT);
    digitalWrite(pin, HIGH);
  }
  oldKey = 0;
  resetCounter = 0;
}

void KeyPad::Scan()
{
  GetCurrentKey();
  if (currentKey == 0)
  {
    keyPressed = false;
    return;
  }

  if ((millis() >= 500 + lastKeyPressedTime) || (resetCounter >= 1000))
  {
    oldKey = 255;
  }
  lastKeyPressedTime = millis();

  keyPressed = oldKey != currentKey;
  if (keyPressed)
  {
    oldKey = currentKey;
    resetCounter = 0;
  }
  else
  {
    resetCounter++;
  }
}

void KeyPad::GetCurrentKey()
{
  currentKey = 0;
  
  byte i = 0;
  while (i < rows)
  {
    SetColumnPinStates(i++);
    if (i <= columns)
    {
      GetRowPinStates(i);
    }
  }
}

void KeyPad::SetColumnPinStates(byte lowColumnPinDelta)
{
  for (byte pinDelta = 0; pinDelta < columns; pinDelta++)
  {
    byte value = pinDelta == lowColumnPinDelta ? LOW : HIGH;
    digitalWrite(columnStartPin + pinDelta, value);
  }
}

void KeyPad::GetRowPinStates(byte delta)
{
  for (byte pinDelta = 0; pinDelta < rows; pinDelta++)
  {
    if (!digitalRead(rowStartPin + pinDelta))
    {
      byte pressedKeyValue = (pinDelta + 1) * 10 + delta;
      byte rowIndex = pressedKeyValue / 10 - 1;
      byte columnIndex = pressedKeyValue % 10 - 1;
      currentKey = keys[rowIndex][columnIndex];
    }
  }
}

bool KeyPad::KeyPressed()
{
  return keyPressed;
}

char KeyPad::GetKey()
{
  return currentKey;
}
