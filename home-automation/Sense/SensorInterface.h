#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include "Device.h"

class SenseInterface {
protected:
	int blinkPin;
    int interrruptPin;
    int devicePins[] = {};
	// Rather, remove both list of devices

    virtual void blink() = 0;

    virtual void run() = 0;

    // do something based on sensor status
    // for sensor devices with probes
    virtual void whenNone() = 0;

    virtual void whenAny() = 0;

    virtual void whenAll() = 0;

public:
    virtual void setup(Device *device) = 0;

    // do NOT spend time here because there could be another thing to work in another sensor
	// remove watch from device...
    virtual bool watch() = 0;
};

#endif /* SENSORINTERFACE_H */
