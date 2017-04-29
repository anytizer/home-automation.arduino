#ifndef PRIORITIES_H
#define PRIORITIES_H

// How frequently to scan the device?
// 100000 is too high!
// 10000
// Power of 2?
#define PRIORITIES_NEVER   0x04
#define PRIORITIES_LAZY    0x03
#define PRIORITIES_SLOW    0x02
#define PRIORITIES_FOREVER 0x01
// eg. FOREVER - LDRS
// eg. SLOW - Water Tank
// eg. Lazy - Fence Lights


// @todo Find out time spent per loop per device
// eg. 4 device connected, "forever" is scanned once per 20ms?

class Priorities {
  private:
    int counter_current = 0; // current loop
    int counter_max = 0; // when to reset; DO NOT MODIFY it programtically after it is set once

    // device must overwrite and define this value with their name
    char *identityText;

    void stop_at(int max_value);

    // Run once every nth-micro-seconds
    // high number: less priority
    // low number: high priorities (multiple times per moment or counter per loop)

  public:
    Priorities();

    char* identity(char *_identity);
    char* identity();

    // updates priority
	// select what to do?
    bool runnable();

	
	// counters
	int at(); // current pass counter
	int next(); // when will it run again

    // @todo Force all sensors to reset this call
	// setup functions only
    void never();
    void lazy();
    void slow();
    void forever();
};

#endif /* PRIORITIES_H */
