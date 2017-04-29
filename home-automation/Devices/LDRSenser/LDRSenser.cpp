#include <Arduino.h>

#include "LDRSenser.h"

LDRSenser::LDRSenser(int pin)
{
  (*this).pin = pin;
}

void LDRSenser::setup()
{
  pinMode((*this).pin, INPUT);
}

int LDRSenser::value()
{
  int value = analogRead((*this).pin);
  return value;
}
