//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "motorSetup.h"
#include "functionsLibrary.h"
//#include "joystickDriver.c"

void irPosition1(){
	stopMotors(1);
	goLeft(90);
	back(0.5, 50);
	straight(2, 50);
	goLeft(20);
	goRight(20);
	back (2, 50);
}
void irPosition2(){
	stopMotors(1);
	goLeft(30);
	straight(2.5, 50);
	back(2, 50);
}
void irPosition3(){
	stopMotors(1);
	goLeft(30);
	straight(2.5, 50);
	back(2, 50);
}
task main(){
	int irValue = 0;
	//waitForStart();
	servo[servo2] = 180;
	motor[motorG] = 50;
	motor[motorF] = 50;
	sleep(800);
	stopMotors(1);
	irValue = SensorValue[S4];
	straight(2, 50);
	irPosition1();
	//irPosition2();
	//irPosition3();
	motor[motorG] = -50;
	motor[motorF] = -50;
	sleep(825);
	//Sandstorm();
}
