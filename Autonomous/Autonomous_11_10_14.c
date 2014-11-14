#include "motorSetup.h"
#include "functionsLibrary.h"
task main(){
	goRight(90);
	goLeft(90);
	straight(5, 100);
	back(5,100);
	motor[motorF] = 50;
	motor[motorG] = 50;
	sleep(500);
	motor[motorF] = -50;
	motor[motorG] = -50;
	sleep(500);
	stopMotors(5);
	goRight(360);
}
