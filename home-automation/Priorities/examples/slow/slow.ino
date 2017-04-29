#include <Priorities.h>

Priorities *task = new Priorities();

char ID[] = "Slow Task 001";
char runningStatus[] = "Just Ran :-)";
char rejectedStatus[] = "Rejected";

void setup()
{
  task->identity(ID);
  task->slow();

  Serial.begin(9600);
  while(!Serial);
}

char *currentStatus;
char message[100];

void loop()
{
  if(task->runnable())
  {
    task->run();
    currentStatus = runningStatus;
  }
  else
  {
    task->reject();
    currentStatus = rejectedStatus;
  }

  sprintf(message, "Task ID [%s] at %d of %d - %s", task->identity(), task->at(), task->next(), currentStatus);
  Serial.println(message);
  
  delay(1000);
}

