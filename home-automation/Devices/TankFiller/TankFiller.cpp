#ifndef TANKFILLER_CPP
#define TANKFILLER_CPP


// https://stackoverflow.com/questions/11712707/extern-functions-in-c-vs-c
//#define MAXIMUM_WATERPROBE_SENSORS 8

#include "Blinker.h"
#include "TankFiller.h"

TankFiller::TankFiller() : Sense() {
    // @todo if motor is running and tank is 75% full, increase the priority
    // save water being spilled
    (*this->priority).slow();

    //soliloquy("    '- Lazy - the Tank Filler", false);
}

void TankFiller::blink() {
    // signature blink for tank filler
    Blinker *blinker = new Blinker(TANKFILLER_LEDPIN);
    blinker->fast(TANKFILLER_BLINKTIMES);
}

void TankFiller::whenNone() {}
void TankFiller::whenAny() {}
void TankFiller::whenAll() {}

#endif /* TANKFILLER_H */
