D:\raspeberry\projects\reed.ino\reeds\Sense

C:\Users\dev\Documents\Arduino\libraries>
mklink /d Sense D:\raspeberry\projects\reed.ino\reeds\Sense


    // @todo callable function of an interruption
    //virtual void interruptionHandler() = 0;
    //virtual void sensorProbesAt(int probesPins[]) = 0;

    // to be defined in individual sensor level
    //virtual void interruptionAt(int pin) = 0;

    // http://arduino.stackexchange.com/questions/14480/pass-a-member-function-pointer-to-a-method-of-a-foreign-class-edb-lib
    // http://stackoverflow.com/questions/7455570/how-to-pass-serial-object-by-reference-to-my-class-in-arduino
    // void myFunc(myLib *this, int val);


PIN - SENSOR - Priority - watch/run/reject - DEVICE

Sensor = Logical, eg. Water Motor to Fill Tanks.
Deivce = actual, eg. motor01, motor02, ...
Sensor
	 - controls when to run and not...
	 - timing
	 - number of devices
	 - status reading...
	 
