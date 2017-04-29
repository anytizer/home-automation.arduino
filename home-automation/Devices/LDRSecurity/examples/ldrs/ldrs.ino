#include <Arduino.h>

#include <Device.h>
#include <Sense.h>
#include <LDRSecurity.h>

LDRSecurity *ldrs;

void setup()
{
  int probes[] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, };
  int responses[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int interrupt = 4;
  char identity[] = "Device 001";

  Device *device;
  device = new Device();
  (*device).probes = probes;
  (*device).responses = responses;
  (*device).interrupt = interrupt;
  (*device).identity = identity;

  ldrs = new LDRSecurity();
  ldrs->setup(device);

  Serial.begin(9600);
  while(!Serial);
}

void loop()
{
  Serial.println("Running LDRSecurity");
  (*ldrs).watch();
  

  delay(1000);
}

