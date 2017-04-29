#ifndef SENSE_H
#define SENSE_H

#include "SensorInterface.h"
#include "Priorities.h"
#include "Device.h"

class Sense : public SenseInterface {
private:
    void interruptionHandler();

protected:
    Priorities *priority;
	
	// to support multiple devices at once

	// rather, copy from devices, rather...
    virtual void sensorProbesAt(int probesPins[]);
    virtual void interruptionAt(int interruptablePin);
    int devices();

    bool valueOfProbe(int ProbePin);

    int totalHigh();

    // informs visually that sensor is about to activate
    virtual void blink() = 0;

    // talk to an external world: run application logic
    void run();

public:
    Sense();

    void setup(Device *device);

    bool watch();

    bool any();

    bool all();

    bool none();
};

#endif /* SENSE_H */
