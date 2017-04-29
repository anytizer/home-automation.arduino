#include <Arduino.h>

#include <Device.h>
#include <Sense.h>
#include <TankFiller.h>

TankFiller *tf;

void setup()
{
  int probes[] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, };
  int responses[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int interrupt = 4;
  char identity[] = "Motor 001";

  Device *motor;
  motor = new Device();
  (*motor).probes = probes;
  (*motor).responses = responses;
  (*motor).interrupt = interrupt;
  (*motor).identity = identity;

  tf = new TankFiller();
  tf->setup(motor);

  Serial.begin(9600);
  while(!Serial);
}

void loop()
{
  Serial.println("Running TF");
  (*tf).watch();
  

  delay(1000);
}

