#ifndef SENSE_CPP
#define SENSE_CPP

// [error|warning|ignored]
// #pragma GCC diagnostic [error]


#include <Arduino.h>
//#include "Device.h"

//#include "Libraries.h"
#include "Sense.h"

Sense::Sense() {
    // @todo MUST call
    // @todo Must be new to point a real new object
    // http://provideyourown.com/2011/advanced-arduino-including-multiple-libraries/
    // http://stackoverflow.com/questions/20590884/base-operand-of-has-non-pointer-type
    // http://stackoverflow.com/questions/35682047/error-base-operand-of-has-non-pointer-type-error-when-calling-a-me
    this->priority = new Priorities();

    //soliloquy("const", true);
    //soliloquy("   '- A sensor instantiated.", true);
}

void Sense::setup(Device *device) {
    //this->sensorProbesAt(probePins);
    //this->interruptionAt(interruptablePin);
	
	// @todo Setup priority too

    //(*this->priority).identity(device->identity); // works with *device
    (*this->priority).identity(device->identity); // works with *device
}


// @TODO
// returns how many sensor probes do we have?
// each sensor may take time
// the app may calculate how much time to spend
// return sizeof(this->devicePins);
int Sense::devices() {
    return 0;
}


/**
   Setup the pins
*/
void Sense::sensorProbesAt(int pins[]) {
    // http://stackoverflow.com/questions/3536153/c-dynamically-growing-array

    // @todo Limit the number of pins it can intake; 1 - 8
    int j;

    j = sizeof(pins);
    // Pickup the min of our maximum capability or really used probes count
    // j = min(MAXIMUM_REEDS_SENSORS, j);

    for (int i = 0; i < j; ++i) {
        this->devicePins[i] = pins[i];
    }
}

/**
   https://www.arduino.cc/en/Reference/AttachInterrupt
   https://www.arduino.cc/en/Reference/DetachInterrupt
   http://playground.arduino.cc/Main/PcInt
   https://www.arduino.cc/en/Reference/Interrupts
   https://github.com/mikaelpatel/Arduino-Scheduler
   http://www.kwartzlab.ca/2010/09/arduino-multi-threading-librar/

   void PCattachInterrupt(uint8_t pin, void (*userFunc)(void), int mode) {
*/
void Sense::interruptionAt(int interruptablePin) {
    // keep compiler silent
    if(interruptablePin)
    {
        // something...
    }
    // void myFunc(myLib *this, int val);
    // https://stackoverflow.com/questions/7455570/how-to-pass-serial-object-by-reference-to-my-class-in-arduino
    // http://arduino.stackexchange.com/questions/14480/pass-a-member-function-pointer-to-a-method-of-a-foreign-class-edb-lib

    // attachInterrupt(digitalPinToInterrupt(interruptablePin), &this->interruptionHandler, RISING);
    // attachInterrupt(digitalPinToInterrupt(interruptablePin), Sense::interruptionHandler, RISING);

    // https://github.com/GreyGnome/PinChangeInt/blob/master/PinChangeInt.h
    // static   int8_t attachInterrupt(uint8_t pin, PCIntvoidFuncPtr userFunc, int mode);
    // #define PCattachInterrupt(pin,userFunc,mode) PCintPort::attachInterrupt(pin, userFunc,mode)
    // typedef void (*PCIntvoidFuncPtr)(void);
    // PCintPin() :
    // PCintFunc((PCIntvoidFuncPtr)NULL),  mode(0) {}

    // &Foo::channelAInterruptDispatch
    // attachInterrupt(digitalPinToInterrupt(interruptablePin), pin_read, RISING);
    // attachInterrupt(digitalPinToInterrupt(interruptablePin), &this->interruptionHandler, RISING);
    // attachInterrupt(digitalPinToInterrupt(interruptablePin), xyz, RISING);

    // cannot convert 'void (Sense::*)()' to 'void (*)()' for argument '2' to 'void attachInterrupt(uint8_t, void (*)(), int)'

    // http://forum.arduino.cc/index.php?topic=362294.5
    // void setupInterruptHandler(uint8_t irq_pin, void (*ISR)(void));

    /**
       Who sent the interrupt?
       Call the corresponding interrupt handler
    */
    // attachInterrupt(digitalPinToInterrupt(interruptablePin), doReedsInterrupts, RISING);
}


void Sense::interruptionHandler() {
    // @todo It is NOT being compiled/used
    // Do something when interruption was received
    // eg. noise continuously
}

bool Sense::valueOfProbe(int ProbePin) {
    // https://www.arduino.cc/en/Reference/digitalRead

    // read the current status of the probe with logic HIGH
    // for compatibility; always work with logic high
    // HIGH, LOW
    // @todo Pin has to be in OUTPUT mode
    int value = digitalRead(ProbePin);
    return value == HIGH;
}

/**
   Total number of sensors with HIGH status
*/
int Sense::totalHigh() {
    int totalHigh = 0;
    int devices = this->devices();
    for (int i = 0; i < devices; ++i) {
        if (this->valueOfProbe(i)) {
            // this probe is high;
            // Look for all probes
            ++totalHigh;
        }
    }

    return totalHigh;
}

bool Sense::any() {
    bool any = false;
    int devices = this->devices();
    for (int i = 0; i < devices; ++i) {
        // this probe is high;
        if (this->valueOfProbe(i)) {
            any = true;
            // no need to check for further probes
            break;
        }
    }

    // OR for any device pins
    // for all device pins, check if the pin is high
    // is any of the pin active?
    return any;
}

bool Sense::all() {
    // AND for all pins == 1
    // reverse of NONE
    // are all the pins active?
    int devices = this->devices();
    int totalHigh = this->totalHigh();

    // all devices are high
    return devices == totalHigh;
}

bool Sense::none() {
    // !FOR ALL PINS == 1
    // reverse of ALL
    // are all of the pins inactive?
    int totalHigh = this->totalHigh();
    return 0 == totalHigh;
}

// do something when pins high
// do something when pins low
// digitalWrite(myPins[1], HIGH); // turns on pin 7
// tell master about the current status


/**
   Watch
*/
bool Sense::watch() {
    //soliloquy("**", true);
    //soliloquy("    '- Sense is watching ID: ", false); soliloquy((*this->priority).identity(), true);

    bool runnable;
    runnable = (*this->priority).runnable();

    //soliloquy("", true);
    if (runnable) {
        // optional
		// this->blink(); // signifies sensor is activating right now
        
		// must do
		this->run();

        //soliloquy("    '- * Sense RUNS: ", false);
    } else {
        //soliloquy("    '- *** Sense rejects: ", false);
		
		// optional
		//this->reject();
    }

    //soliloquy((*this->priority).identity(), true);

    return runnable;
}


void Sense::run() {
    //soliloquy("", true);
    //soliloquy("    '- *** Sense runs for NONE, ANY, ALL...", false);
    //soliloquy((*this->priority).identity(), true);

    // when no door is closed; ALL OPEN
    // No door is closed
    // No probe is active
    // water below critical level
    // run the motor!
    if (this->none()) {
        this->whenNone();
    }

    // time based; if evening, alert high
    // are some doors are still open?

    // some sensors are broken
    // this->alarm();
    // some of the water probes are active
    // do not have to do anything special
    // starts with low priority and motor is ON
    // if motor is running...
    // if water level filled so far > 80%;
    // set priority = HIGH
    // if tank filled > 95%; switch off the motor
    if (this->any()) {
        this->whenAny();
    }

    // if all doors are closed; enable loud alarms
    // house doors closed from inside
    // enable:
    // LDR Security Hardware with loud sensors;
    // attach LDR broken lights
    // eq. stop the motor
    // this->alarm();
    // if all doors are closed; enable loud alarms when there is a break
    // if all house doors are closed from inside
    // enable: LDR Security Hardware with loud sensors;
    // attach LDR broken lights
    if (this->all()) {
        this->whenAll();
    }
}

#endif /* SENSE_CPP */
