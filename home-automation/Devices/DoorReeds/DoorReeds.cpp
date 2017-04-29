#ifndef DOORREEDS_CPP
#define DOORREEDS_CPP

// https://stackoverflow.com/questions/11712707/extern-functions-in-c-vs-c
// #define MAXIMUM_REEDS_SENSORS 8

//#include <Arduino.h>
//#include "Libraries.h"

#include "Blinker.h"
#include "DoorReeds.h"

DoorReeds::DoorReeds() : Sense() {
    (*this->priority).lazy();
    //soliloquy("    '- Slow - the Door Reeds", true);
}

void DoorReeds::blink() {
    //return;

    // signature blink for reeds
    Blinker *blinker = new Blinker(DOORREEDS_LEDPIN);
    blinker->normal(DOORREEDS_BLINKTIMES);
}

void DoorReeds::whenNone() {}

void DoorReeds::whenAny() {}

void DoorReeds::whenAll() {}

#endif /* DOORREEDS_CPP */
