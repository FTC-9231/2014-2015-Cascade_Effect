#include "motorSetup.h"
#include "functionsLibrary.h"
#include "joystickDriver.c"
task main(){
	waitForStart();
	servo[servo2] = 180;
	motor[motorG] = 50;
	motor[motorF] = 50;
	sleep(850);
	stopMotors(1);

	Sandstorm();
}
