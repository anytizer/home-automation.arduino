#include <Blinker.h>

Blinker *blinker = new Blinker(LED_BUILTIN);

void setup()
{
  blinker->setup();
}

void loop()
{
  //blinker->pulsate();
  //delay(2000);
e
  //int blinkTimes = 6;
  //blinker->normal(blinkTimes);

  //delay(2000);

  blinker->signature();
  delay(2000);
}

