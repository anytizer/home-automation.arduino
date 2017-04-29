#ifndef LDRSECURITY_CPP
#define LDRSECURITY_CPP


// https://stackoverflow.com/questions/11712707/extern-functions-in-c-vs-c
//

#include "Blinker.h"
#include "LDRSecurity.h"


LDRSecurity::LDRSecurity() : Sense() {
  (*this->priority).forever();
}


void LDRSecurity::sensorProbesAt(int *pins)
{
	if(pins)
	{
		// compiler silence
	}
}


void LDRSecurity::blink() {
  //return;

  // signature blink for LDR Security
  Blinker *blinker = new Blinker(LDRSECURITY_LEDPIN);
  blinker->slow(LDRSECURITY_BLINKTIMES);
}


void LDRSecurity::whenNone() {}
void LDRSecurity::whenAny() {}
void LDRSecurity::whenAll() {}


#endif /* LDRSECURITY_CPP */
