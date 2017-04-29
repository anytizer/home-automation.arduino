#ifndef PRIORITIES_CPP
#define PRIORITIES_CPP

#include "Priorities.h"

Priorities::Priorities() {
    this->counter_current = 0;
    this->counter_max = 0;
	
	// to be a pointer
    this->identityText[0] = '\0'; // null
}

/**
   Set the ID
*/
char* Priorities::identity(char *_identity) {
	(*this).identityText = _identity;

	return this->identity();
}

/**
   Read the ID
*/
char* Priorities::identity() {
    return this->identityText;
}




void Priorities::stop_at(int max_value) {
    // @todo Do NOT allow too high
    // Must be within the defined range
    this->counter_max = max_value;
}

int Priorities::at()
{
	return this->counter_current;
}

int Priorities::next()
{
	return this->counter_max;
}

void Priorities::never() {
    this->stop_at(PRIORITIES_NEVER);
}

void Priorities::lazy() {
    this->stop_at(PRIORITIES_LAZY);
}

void Priorities::slow() {
    this->stop_at(PRIORITIES_SLOW);
}

void Priorities::forever() {
    this->stop_at(PRIORITIES_FOREVER);
}



/**
   Decides if a sensor needs to run right now
   Logic: Run 1 time for every N loops.
   Get current loop count; if modulo, run...
*/
bool Priorities::runnable() {
    bool run_device; // = false;

    // @todo on each round, first one is always always missing
    ++this->counter_current;
    if (this->counter_current >= this->counter_max) {
        this->counter_current = 0;
        run_device = true;
    } else {
        // do nothing
        run_device = false;
    }

    /**
       To reach here, looks like it is instantiating 8 times...
    */
    return run_device;
}



#endif /* PRIORITIES_CPP */
