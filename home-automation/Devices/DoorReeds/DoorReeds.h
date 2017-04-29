#ifndef DOORREEDS_H
#define DOORREEDS_H

#include "Sense.h"

#define DOORREEDS_LEDPIN 10
#define DOORREEDS_BLINKTIMES 3

class DoorReeds : public Sense {
private:
    void whenNone();

    void whenAny();

    void whenAll();

public:
    DoorReeds();

    void blink();
};

#endif /* DOORREEDS_H */
