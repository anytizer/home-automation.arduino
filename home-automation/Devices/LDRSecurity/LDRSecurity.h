#ifndef LDRSECURITY_H
#define LDRSECURITY_H


#define LDRSECURITY_LEDPIN 8
#define LDRSECURITY_BLINKTIMES 1
// #define MAXIMUM_LDRS_SENSORS 8

#include "Sense.h"

class LDRSecurity : public Sense {
  private:
    void whenNone();
    void whenAny();
    void whenAll();
	
	void sensorProbesAt(int *pins);

  public:
    LDRSecurity();

    void blink();
};


#endif /* LDRSECURITY_H */

