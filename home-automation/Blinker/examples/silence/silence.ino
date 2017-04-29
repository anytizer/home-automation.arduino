void setup()
{
  Serial.begin(9600);
  while(!Serial);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  Serial.println("Writing zero.");

  digitalWrite(LED_BUILTIN, 0);
  delay(5000);
}

