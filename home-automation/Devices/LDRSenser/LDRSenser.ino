#include <Arduino.h>
#include "LDRSenser.h"

LDRSenser *ldr1;
LDRSenser *ldr2;
LDRSenser *ldr3;
LDRSenser *ldr4;

void setup()
{
  ldr1 = new LDRSenser(A1);
  (*ldr1).setup();

  ldr2 = new LDRSenser(A2);
  (*ldr2).setup();

  ldr3 = new LDRSenser(A3);
  (*ldr3).setup();

  ldr4 = new LDRSenser(A4);
  (*ldr4).setup();

  Serial.begin(9600);

}

char message[30];
bool response;
void loop()
{

  sprintf(message, "A1: %d, A2: %d, A3: %d, A4: %d", (*ldr1).value(), (*ldr2).value(), (*ldr3).value(), (*ldr4).value());
  //,| %d,%d, A0, A5);

  Serial.println(message);
  /*
    if (LDRValue < LightSensitivity)
      response = HIGH;
    }
    else
    {
    response = LOW;
    }
    digitalWrite(LED_BUILTIN, response);
  */

  delay(500); // sensitivity speed
}


