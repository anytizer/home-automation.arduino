#ifndef FENCELIGHT_H
#define FENCELIGHT_H

#define FENCELIGHT_LEDPIN 11
#define FENCELIGHT_BLINKTIMES 3

#include "Sense.h"

class FenceLight : public Sense {
  private:
    void whenNone();
    void whenAny();
    void whenAll();
	
	void sensorProbesAt(int *pins);

  public:
    FenceLight();

    void blink();
};

#endif /* FENCELIGHT_H */
