int D7 = 7;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(D7, INPUT);

  Serial.begin(9600);
}

int ain;
char message[50];
void loop()
{
  ain = digitalRead(D7);
  sprintf(message, "D7: %d", ain);
  Serial.println(message);

  if(ain == HIGH)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }

  delay(500);
}

