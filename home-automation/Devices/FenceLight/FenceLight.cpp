#ifndef FENCELIGHT_CPP
#define FENCELIGHT_CPP


#include "Blinker.h"
#include "FenceLight.h"

FenceLight::FenceLight() : Sense() {
  (*this->priority).never();
}


void FenceLight::sensorProbesAt(int *pins)
{
	if(pins)
	{
		// compiler silence
	}
}


void FenceLight::blink() {
  //return;

  // signature blink for FenceLight
  Blinker *blinker = new Blinker(FENCELIGHT_LEDPIN);
  blinker->slow(FENCELIGHT_BLINKTIMES);
}

void FenceLight::whenNone() {}
void FenceLight::whenAny() {}
void FenceLight::whenAll() {}


#endif /* FENCELIGHT_CPP */
