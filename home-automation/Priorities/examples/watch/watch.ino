#include <Priorities.h>

Priorities *task = new Priorities();
char runningStatus[] = "Just Ran :-)";
char rejectedStatus[] = "Rejected";

bool deviceRan;
char *currentID;
char *currentStatus;
char message[100];

void setup()
{
  char ID[] = "Slow Task 001";
  task->identity(ID);
  //task->slow();
  task->forever();

  Serial.begin(9600);
  while (!Serial);
}

void loop()
{
  currentID = task->identity();
  deviceRan = task->watch();
  if (deviceRan)
  {
    currentStatus = runningStatus;
  }
  else
  {
    currentStatus = rejectedStatus;
  }

  sprintf(message, "Task ID [%s] %d of %d - %s", currentID, task->at(), task->next(), currentStatus);
  Serial.println(message);

  delay(1500);
}

