#include <Blinker.h>

// LED_BUILTIN
Blinker *blinker = new Blinker(0x04);

void setup()
{
  blinker->setup();
}

void loop()
{
  blinker->flash();
}
