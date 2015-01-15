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
	straight(2, 50);
	stopMotors(1);
	goRight(95);
	motor[motorG] = -50;
	motor[motorF] = -50;
	sleep(850);
	straight(2.9, 50);
	back(1.7, 50);
	goRight(15);
	straight(2.7, 50);
	//Sandstorm();
}
