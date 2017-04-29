#ifndef DEVICE_H
#define DEVICE_H

struct Device
{
    // array of sensor pins
    // @todo Rather use shift register contents
    int *probes; // input
    int *responses; // output
	
	int blinkPin; // where is the blink LED connected to?

    // micro-controller interruptable pin
	// input signal request
    int interrupt = 0;

    // device identifier
	char *identity;
};

#endif /* DEVICE_H */
