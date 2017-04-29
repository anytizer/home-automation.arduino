#include <Blinker.h>

Blinker *blinker = new Blinker(LED_BUILTIN);

void setup()
{
  blinker->setup();
}

void loop()
{
  int blinkOnce = 1;
  blinker->fast(blinkOnce);

  delay(1500);

  int blinkLessTimes = 2;
  blinker->fast(blinkLessTimes);

  delay(1500);

  int blinkMoreTimes = 6;
  blinker->fast(blinkMoreTimes);

  delay(1500);
}

