#include <Blinker.h>

Blinker *blinker = new Blinker(LED_BUILTIN);

void setup()
{
  blinker->setup();
}

void loop()
{
  blinker->pulsate();
}

