#include <Arduino.h>

#include <Device.h>
#include <Sense.h>
#include <LDRSecurity.h>
#include <TankFiller.h>
#include <DoorReeds.h>

LDRSecurity *ldrs;
TankFiller *tf;
DoorReeds *reed;

void setup()
{
  int ldrs_probes[] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, };
  int ldrs_responses[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int ldrs_interrupt = 4;
  char ldrs_identity[] = "Device 001";

  Device *device;
  device = new Device();
  (*device).probes = ldrs_probes;
  (*device).responses = ldrs_responses;
  (*device).interrupt = ldrs_interrupt;
  (*device).identity = ldrs_identity;

  ldrs = new LDRSecurity();
  ldrs->setup(device);


  int tf_probes[] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, };
  int tf_responses[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int tf_interrupt = 4;
  char tf_identity[] = "Motor 001";

  Device *motor;
  motor = new Device();
  (*motor).probes = tf_probes;
  (*motor).responses = tf_responses;
  (*motor).interrupt = tf_interrupt;
  (*motor).identity = tf_identity;

  tf = new TankFiller();
  tf->setup(motor);


  int reeds_probes[] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, };
  int reeds_responses[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, };
  int reeds_interrupt = 4;
  char reeds_identity[] = "Device 001";

  Device *reeds_device;
  reeds_device = new Device();
  (*reeds_device).probes = reeds_probes;
  (*reeds_device).responses = reeds_responses;
  (*reeds_device).interrupt = reeds_interrupt;
  (*reeds_device).identity = reeds_identity;

  reed = new DoorReeds();
  reed->setup(reeds_device);

  Serial.begin(9600);
  while (!Serial);
}

void loop()
{
  Serial.println("Running LDRSecurity");
  (*ldrs).watch();

  Serial.println("Running TF");
  (*tf).watch();

  Serial.println("Running Reeds");
  (*reed).watch();

  delay(1000);
}
