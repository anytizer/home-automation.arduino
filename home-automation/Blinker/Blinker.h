#ifndef BLINKER_H
#define BLINKER_H

#include <Arduino.h>

// Set staying speeds (ms)
#define BLINKER_PULSEDURATION 20
#define BLINKER_FAST 20
#define BLINKER_NORMAL 75
#define BLINKER_SLOW 150

#define PULSATING_PIN 13

class Blinker {
private:
    int LEDPin;

    void on(int moment);

    void off(int moment);

    void blink(int loops, int moment);

public:
    Blinker(int pin);

    void setup();

    /**
       On which pin is the LED Connected to?
    */
    int pin();

    void once();

    void slow(int times);
    void normal(int times);
    void fast(int times);

    // other
    void flash();
    void pulsate();
    void signature();
    void original();
	
	// experiemental only
	void high(); // ON
	void low(); // OFF
};

#endif /* BLINKER_H */
