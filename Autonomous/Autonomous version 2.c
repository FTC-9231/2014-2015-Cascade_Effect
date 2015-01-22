#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S3,     ArmOptoSensor,  sensorLightActive)
#pragma config(Sensor, S4,     irSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     leftWheel,     tmotorTetrix, openLoop, reversed, driveLeft)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel,    tmotorTetrix, openLoop, driveRight)
#pragma config(Motor,  mtr_S1_C2_1,     leftArm,       tmotorTetrix, openLoop, driveLeft)
#pragma config(Motor,  mtr_S1_C2_2,     rightArm,      tmotorTetrix, openLoop, reversed, driveRight)
#pragma config(Servo,  srvo_S1_C3_1,    gate,                 tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_2,    hook,                 tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//#include "motorSetup.h"
#include "functionsLibrary.h"
#include "joystickDriver.c"
void irPosition1(){
	stopMotors(1);
	goLeft(65);
	back(2, 50);
}
void irPosition2(){
	stopMotors(1);
	goLeft(80);
	back(2, 50);
}
void irPosition3(){
	stopMotors(1);
	goLeft(55);
	back(2, 50);
	goRight(80);
	straight(0.5, 50);
}
task main(){
	waitForStart();
	stopMotors(1);
	back(2.8, 50);
	servo[hook] = 0
	motor[leftArm] = 50;
	motor[rightArm] = 50;
	sleep(1700);
	motor[leftArm] = 0;
	motor[rightArm] = 0;
	sleep(800);
	motor[leftArm] = -50;
	motor[rightArm] = -50;
	sleep(1600);
	servo[hook] = 180;
	straight(1, 50);
	goRight(90);
	back(1, 10)
	int irValue = SensorValue[irSeeker];
	nxtDisplayStringAt();
	//irPosition1();
	//irPosition2();
	//irPosition3();

	//Sandstorm();
}
