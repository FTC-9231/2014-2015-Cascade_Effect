//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "motorSetup.h"
#include "functionsLibrary.h"
#include "joystickDriver.c"
task main(){
	waitForStart();
	motor[motorG] = 50;
	motor[motorF] = 50;
	sleep(450);
	stopMotors(1);
	straight(2.5, 50);
	stopMotors(1);
	goLeft(90);
	back(2.7, 50);
	goLeft(100)
	back(2, 50)
	//Sandstorm();
}
