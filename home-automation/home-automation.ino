#include <Arduino.h>

#include <LDRSecurity.h>
#include <TankFiller.h>
#include <DoorReeds.h>
#include <FenceLight.h>

LDRSecurity *ldrs;
TankFiller *tf;
DoorReeds *doorreed;
FenceLight *fencelight;

void setup()
{
  int ldrs_probes[] = { 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, };
  int ldrs_responses[] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int ldrs_blink = 0x08;
  int ldrs_interrupt = 0x04;
  char ldrs_identity[] = "LDRS 001";

  Device *lightSecurity;
  lightSecurity = new Device();
  (*lightSecurity).probes = ldrs_probes;
  (*lightSecurity).responses = ldrs_responses;
  (*lightSecurity).blinkPin = ldrs_blink;
  (*lightSecurity).interrupt = ldrs_interrupt;
  (*lightSecurity).identity = ldrs_identity;

  ldrs = new LDRSecurity();
  ldrs->setup(lightSecurity);

  int tf_probes[] = { 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, };
  int tf_responses[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, };
  int tf_blink = 0x09;
  int tf_interrupt = 0x05;
  char tf_identity[] = "Motor 001";

  Device *watermotor;
  watermotor = new Device();
  (*watermotor).probes = tf_probes;
  (*watermotor).responses = tf_responses;
  (*watermotor).blinkPin = tf_blink;
  (*watermotor).interrupt = tf_interrupt;
  (*watermotor).identity = tf_identity;

  tf = new TankFiller();
  tf->setup(watermotor);

  int reeds_probes[] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int reeds_responses[] = { 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, };
  int reeds_blink = 0x0A;
  int reeds_interrupt = 0x06;
  char reeds_identity[] = "Reed 001";

  Device *door_sensor;
  door_sensor = new Device();
  (*door_sensor).probes = reeds_probes;
  (*door_sensor).responses = reeds_responses;
  (*door_sensor).blinkPin = reeds_blink;
  (*door_sensor).interrupt = reeds_interrupt;
  (*door_sensor).identity = reeds_identity;

  doorreed = new DoorReeds();
  doorreed->setup(door_sensor);

  int fence_probes[] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int fence_responses[] = { 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, };
  int fence_blink = 0x0B;
  int fence_interrupt = 0x07;
  char fence_identity[] = "Fence Light 001";

  Device *fence_device;
  fence_device = new Device();
  (*fence_device).probes = fence_probes;
  (*fence_device).responses = fence_responses;
  (*fence_device).blinkPin = fence_blink;
  (*fence_device).interrupt = fence_interrupt;
  (*fence_device).identity = fence_identity;

  fencelight = new FenceLight();
  fencelight->setup(fence_device);

  Serial.begin(9600);
  while (!Serial);
}

/**
   Did the individual devices just run?
*/
bool ldr, tank, doors, fence;
// serial message
char message[20];
void loop()
{
  // read time
  // early morning
  // day, noon, afternoon
  // evening
  // night
  // HH:MM:SS

  ldr = (*ldrs).watch();
  tank = (*tf).watch();
  doors = (*doorreed).watch();
  fence = (*fencelight).watch();

  // blink for each
  if (ldr) (*ldrs).blink();
  if (tank) (*tf).blink();
  if (doors) (*doorreed).blink();
  if (fence) (*fencelight).blink();

  sprintf(message, "%s  %s  %s  %s", ldr ? "L" : ".", tank ? "T" : ".", doors ? "D" : ".", fence ? "F" : ".");
  Serial.println(message);

  //delay(2000); // no delay required in live implementation
}

// http://stackoverflow.com/questions/13663919/pass-child-class-to-method-as-parent-class
