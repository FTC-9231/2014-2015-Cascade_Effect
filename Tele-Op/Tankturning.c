#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "JoystickDriver.c"
#include "functionsLibrary.h"
task main(){
	int currentSpeedLeft=0;
	int currentSpeedRight=0;
	bool reverse;
	const int maxAcceleration=20;
	while(true){
		getJoystickSettings(joystick);
		const int threshold = 4;
		currentSpeedRight = speedFilter(thresholdValue(threshold,-joystick.joy1_y2),maxAcceleration,currentSpeedRight);
		currentSpeedLeft = speedFilter(thresholdValue(threshold,-joystick.joy1_y1),maxAcceleration,currentSpeedLeft);
		if(joy1Btn(6)){
		 reverse = true;
	 	}
		if(reverse){
			motor[motorD] = -currentSpeedLeft;
			motor[motorE] = currentSpeedRight;
		}else{
		motor[motorD] = currentSpeedLeft;
		motor[motorE] = currentSpeedRight;
	  }
		if(joy1Btn(2)){
		motor[motorF] = 20;
		motor[motorG] = 20;
	}else if(joy1Btn(3)){
		motor[motorF] = -20;
		motor[motorG] = -20;
	}else{
		motor[motorF] = 0;
		motor[motorG] = 0;
  }if(joy1Btn(1)){
  	servo[servo1] = 360;
  }else if(joy1Btn(4)){
  	servo[servo1] = 90;
	}}}
