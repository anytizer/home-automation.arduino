#include <Blinker.h>

Blinker *blinker = new Blinker(LED_BUILTIN);

int blinkTimes;
int wait;

void setup()
{
  blinkTimes = 3;
  wait = 2000;

  blinker->setup();

  Serial.begin(9600);
  while(!Serial);
}

void loop()
{
  delay(wait);
  blinker->slow(blinkTimes);
  Serial.println("Slow test");

  delay(wait);
  blinker->fast(blinkTimes);
  Serial.println("Fast test");

  delay(wait);
  blinker->normal(blinkTimes);
  Serial.println("Normal test");

  delay(wait);
  blinker->pulsate();
  Serial.println("Pulsate test");

  delay(wait);
  blinker->flash();
  Serial.println("Flash test");

  delay(wait);
}

