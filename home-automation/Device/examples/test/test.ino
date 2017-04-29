#include <Arduino.h>
#include <Device.h>

Device *device;

void setup()
{
  int probes[] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, };
  int responses[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int interrupt = 4;
  char identity[] = "Device 001";

  device = new Device();
  (*device).probes = probes;
  (*device).responses = responses;
  (*device).interrupt = interrupt;
  (*device).identity = identity;

  Serial.begin(9600);
  while(!Serial);
}

char message[100];
void loop()
{
  sprintf(message, "Device ID [%s] at Interrupt: #%d", device->identity, device->interrupt);
  Serial.println(message);
  
  sprintf(message, "Device Probes: %d, %d, %d, %d, %d, %d, %d, %d", device->probes[0], device->probes[1], device->probes[2], device->probes[3], device->probes[4], device->probes[5], device->probes[6], device->probes[7]);
  Serial.println(message);

  sprintf(message, "Device Response: %d, %d, %d, %d, %d, %d, %d, %d", device->responses[0], device->responses[1], device->responses[2], device->responses[3], device->responses[4], device->responses[5], device->responses[6], device->responses[7]);
  Serial.println(message);
  Serial.println("");
  
  delay(3000);
}
