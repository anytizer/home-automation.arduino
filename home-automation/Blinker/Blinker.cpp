#ifndef BLINKER_CPP
#define BLINKER_CPP

#include "Blinker.h"

Blinker::Blinker(int pin)
{
  // whatever be the LED Pin was...
  this->LEDPin = pin;
}

void Blinker::setup()
{
  // @todo Move to SETUP function
  //pinMode(blinker->pin(), OUTPUT);
  // pinMode(this->LEDPin, OUTPUT);
  pinMode(this->LEDPin, OUTPUT);
}

int Blinker::pin()
{
  return this->LEDPin;
}

void Blinker::on(int moment)
{
  digitalWrite(this->LEDPin, HIGH);
  delay(moment);
}

void Blinker::off(int moment)
{
  digitalWrite(this->LEDPin, LOW);
  delay(moment); // just to ensure it was OFF
}

void Blinker::once()
{
  // signature blink
  // https://forum.arduino.cc/index.php?topic=142872.0
  this->on(BLINKER_PULSEDURATION);
  this->off(BLINKER_PULSEDURATION);
  this->on(BLINKER_PULSEDURATION); // double = long
  this->on(BLINKER_PULSEDURATION); // double = long
  this->off(BLINKER_PULSEDURATION);
  this->on(BLINKER_PULSEDURATION);
  this->off(BLINKER_PULSEDURATION);
}

void Blinker::blink(int times, int moment)
{
  for (int l = 0; l < times; ++l)
  {
    this->once();
    delay(moment);
  }
  // leave in off position
  this->off(0);
}

void Blinker::slow(int times)
{
  this->blink(times, BLINKER_SLOW);
}

void Blinker::normal(int times)
{
  this->blink(times, BLINKER_NORMAL);
}

void Blinker::fast(int times)
{
  this->blink(times, BLINKER_FAST);
}


// https://www.arduino.cc/en/tutorial/blink
// https://www.arduino.cc/en/Tutorial/Button






void Blinker::flash()
{
  int short_pulse = 70;
  int long_pulse = 1500;

  digitalWrite(this->LEDPin, LOW);
  delay(short_pulse);

  digitalWrite(this->LEDPin, HIGH);
  delay(short_pulse);
  
  digitalWrite(this->LEDPin, LOW);
  delay(short_pulse);

  digitalWrite(this->LEDPin, HIGH);
  delay(short_pulse);
  
  digitalWrite(this->LEDPin, LOW);
  delay(short_pulse);
  
  digitalWrite(this->LEDPin, HIGH);
  delay(long_pulse);
  
  digitalWrite(this->LEDPin, LOW);
  delay(short_pulse);
  
  digitalWrite(this->LEDPin, HIGH);
  delay(short_pulse);
  
  digitalWrite(this->LEDPin, LOW);
  delay(short_pulse);
  
  digitalWrite(this->LEDPin, HIGH);
  delay(short_pulse);
  
  digitalWrite(this->LEDPin, LOW);
  delay(long_pulse);


}

void Blinker::pulsate() {
  digitalWrite(this->LEDPin, LOW);
  delay(50);
  
  digitalWrite(this->LEDPin, HIGH);
  delay(2000);
  
  digitalWrite(this->LEDPin, LOW);
  delay(2000);
}


// the loop function runs over and over again forever
void Blinker::signature() {
  digitalWrite(this->LEDPin, HIGH);
  delay(50);
  
  digitalWrite(this->LEDPin, LOW);
  delay(50);
  
  digitalWrite(this->LEDPin, HIGH);
  delay(200);
  
  digitalWrite(this->LEDPin, LOW);
  delay(50);

  digitalWrite(this->LEDPin, HIGH);
  delay(50);
  
  digitalWrite(this->LEDPin, LOW);
  delay(1500);
}

void Blinker::original() {
  digitalWrite(this->LEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  
  digitalWrite(this->LEDPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

// experimental only
void Blinker::high() {
  this->on(0);
}

// experimental only
void Blinker::low() {
  this->off(0);
}


#endif /* BLINKER_CPP */
