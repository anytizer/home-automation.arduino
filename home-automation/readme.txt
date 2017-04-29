SuperHouseTV #15: Watchdog timers for Arduino home automation
	- https://youtu.be/GC6dGypGctQ?t=338


How Shift Registers Work! 
	https://youtu.be/6fVbJbNPrEU


How to Control a Ton of Inputs using Shift Registers! 
	- https://youtu.be/nXl4fb_LbcI

How To - Expand Digital Inputs with the 74HC165 + Test Code 
	- https://www.youtube.com/watch?v=hR6qOhUeKMc



// peephole
// passage pir

2	Water Motors
8	Night Lights
8	Room Lights
4	LDR Security
8	Thief Lights
16	Fence Lights
4	Passage Lights
8	Fans
1	Kitchen Chimney
4	Bathroom Exhausts
8	Door Monitors
9	Multi timer clock - Press a button to read the time from a clock
		- different clock modules set with different times
		- The one is pushed will publish the time on the screen


if 6pm onwards...
	if doors open
		tring doors

If all doors closed
	High alert LDRs

If motor running
	check when filled;
	if filled up;
		stop the motor.

If 7pm onwards;
	if PIR;
		turn on lights;

If 6pm onwards; turn on passage lamps



c:
cd C:\Users\dev\Documents\Arduino\libraries
mklink /d Blinker D:\raspeberry\projects\home-automation\home-automation\Blinker
mklink /d Device D:\raspeberry\projects\home-automation\home-automation\Device
mklink /d Priorities D:\raspeberry\projects\home-automation\home-automation\Priorities
mklink /d Sense D:\raspeberry\projects\home-automation\home-automation\Sense
mklink /d LDRSecurity D:\raspeberry\projects\home-automation\home-automation\Devices\LDRSecurity
mklink /d DoorReeds D:\raspeberry\projects\home-automation\home-automation\Devices\DoorReeds
mklink /d TankFiller D:\raspeberry\projects\home-automation\home-automation\Devices\TankFiller
mklink /d FenceLight D:\raspeberry\projects\home-automation\home-automation\Devices\FenceLight


L  .  .  .
L  T  .  .
L  .  D  .
L  T  .  F
L  .  .  .
L  T  D  .
L  .  .  .
L  T  .  F
L  .  D  .
L  T  .  .
L  .  .  .
L  T  D  F

/**
house-protection ON
house-protection OFF

sets alarms and sensors ON or OFF

DRILL water tabnk
drill motor
drill laser
drill


Doors
If all doors are NOT closed; alert with error code

*/