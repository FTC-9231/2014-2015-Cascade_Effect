#include "motorSetup.h"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//YOU HAVE TO HAVE THIS IN THE SAME FOLDER AS THE FILE FOR IT TO WORK LIKE SERIOUSLY DONT ASK ME WHY IT ISNT WORKING IF YOU DONT HAVE THE FILE DOWNLOADED -- Jordan
//YOU HAVE TO HARD CODE THIS FOR YOUR ROBOT BECAUSE WE CAN'T GET ENCODERS
void goRight(int degree){
//degree in... degrees
	motor[motorD] = 100;
	motor[motorE] = -100;
	sleep(degree*8);
}
void goLeft(int degree){
//degree in... degrees
	motor[motorD] = -100;
	motor[motorE] = 100;
	sleep(degree*8);
}
void straight(float time, int speed){
// Time in seconds, speed in percent
	motor[motorD] = speed;
	motor[motorE] = speed;
	sleep(time*1000);
}
void back(float time, int speed){
// Time in seconds, speed in percent
	motor[motorD] = -speed;
	motor[motorE] = -speed;
	sleep(time*1000);
}
void stopMotors(int time){
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorF] = 0;
	motor[motorG] = 0;
	sleep(time * 1000);

}