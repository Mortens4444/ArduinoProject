#include "LedController.h"

LedController::LedController(byte pin)
{
  pinMode(pin, OUTPUT);
  this->pin = pin;

  int currentValue = digitalRead(pin);
  isOn = currentValue != 0;
}

void LedController::On()
{
  digitalWrite(pin, HIGH);
  isOn = true;
}

void LedController::Off()
{
  digitalWrite(pin, LOW);
  isOn = false;
}

void LedController::Toggle()
{
  if (isOn)
  {
    Off();
  }
  else
  {
    On();
  }
}

void LedController::Blink()
{
  Toggle();
  delay(250);
}
