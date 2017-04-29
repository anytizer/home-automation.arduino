#include <Priorities.h>

Priorities *slowTask = new Priorities();
Priorities *fastTask = new Priorities();


char slow_runningStatus[] = "Just Ran :-)";
char slow_rejectedStatus[] = "Rejected";

char fast_runningStatus[] = "Just Ran :-)";
char fast_rejectedStatus[] = "Rejected";

void setup()
{
  char slow_ID[] = "Slow Task 001";
  slowTask->identity(slow_ID);
  slowTask->slow();

  char fast_ID[] = "fast Task 001";
  fastTask->identity(fast_ID);
  fastTask->forever();

  Serial.begin(9600);
  while (!Serial);
}

char *slow_currentStatus;
char slow_message[100];

char *fast_currentStatus;
char fast_message[100];

char *slow_currentID;
char *fast_currentID;

void loop()
{
  if (slowTask->runnable())
  {
    slowTask->run();
    slow_currentStatus = slow_runningStatus;
  }
  else
  {
    slowTask->reject();
    slow_currentStatus = slow_rejectedStatus;
  }
  slow_currentID = slowTask->identity();
  sprintf(slow_message, "[%s] at %d of %d - %s", slow_currentID, slowTask->at(), slowTask->next(), slow_currentStatus);
  Serial.println(slow_message);



  if (fastTask->runnable())
  {
    fastTask->run();
    fast_currentStatus = fast_runningStatus;
  }
  else
  {
    fastTask->reject();
    fast_currentStatus = fast_rejectedStatus;
  }
  fast_currentID = fastTask->identity();
  sprintf(fast_message, "[%s] at %d of %d - %s", fast_currentID, fastTask->at(), fastTask->next(), fast_currentStatus);
  Serial.println(fast_message);

  delay(1000);
}

