#ifndef TANKFILLER_H
#define TANKFILLER_H

#include "Sense.h"

#define TANKFILLER_LEDPIN 9
#define TANKFILLER_BLINKTIMES 3

class TankFiller : public Sense {
private:
    void whenNone();

    void whenAny();

    void whenAll();

public:
    TankFiller();

    void blink();
};

// @todo Implement using Ultrasonic Range Finder to get water level
// @todo Implement using reed switches
// implement using mercury switches
// implement using mechanical switches
// implement using air-balloon
// https://www.arduino.cc/en/Tutorial/Ping

#endif /* TANKFILLER_H */
