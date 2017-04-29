#include <Blinker.h>

Blinker *blinker = new Blinker(LED_BUILTIN);

void setup()
{
  blinker->setup();
}

void loop()
{
  int blinkTimes = 3;
  blinker->fast(blinkTimes);

  delay(1500);
}

