/**
 * Use this to take out the 3.3 volts for LED
 */
void setup()
{
  Serial.begin(9600);
  while(!Serial);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  Serial.println("Writing high.");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
}

