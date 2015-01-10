#include "motorSetup.h"

//YOU HAVE TO HAVE THIS IN THE SAME FOLDER AS THE FILE FOR IT TO WORK LIKE SERIOUSLY DONT ASK ME WHY IT ISNT WORKING IF YOU DONT HAVE THE FILE DOWNLOADED -- Jordan
//YOU HAVE TO HARD CODE THIS FOR YOUR ROBOT BECAUSE WE CAN'T GET ENCODERS
void goRight(int degree){
//degree in... degrees
	motor[motorD] = 100;
	motor[motorE] = -100;
	sleep(degree*9.05);
	motor[motorD] = 0;
	motor[motorE] = 0;
}
void goLeft(int degree){
//degree in... degrees
	motor[motorD] = -100;
	motor[motorE] = 100;
	sleep(degree*9.05);
	motor[motorD] = 0;
	motor[motorE] = 0;
}
void straight(float time, int speed){
// Time in seconds, speed in percent
	motor[motorD] = speed;
	motor[motorE] = speed;
	sleep(time*1000);
	motor[motorD] = 0;
	motor[motorE] = 0;
}
void back(float time, int speed){
	straight(time, -speed);
}
void stopMotors(int time){
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorF] = 0;
	motor[motorG] = 0;
	sleep(time * 1000);

}
void Sandstorm(){
  //        224 = Tempo
  //          5 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   32); wait1Msec( 353);  // Note(G6)
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   32); wait1Msec( 353);  // Note(F6)
  PlayTone(  784,   16); wait1Msec( 176);  // Note(C6, Duration(Eighth))
  PlayTone(  784,   16); wait1Msec( 176);  // Note(C6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone( 1320,   16); wait1Msec( 176);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   16); wait1Msec( 176);  // Note(A6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   16); wait1Msec( 176);  // Note(G6, Duration(Eighth))
  PlayTone( 1175,   32); wait1Msec( 353);  // Note(G6)
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   16); wait1Msec( 176);  // Note(F6, Duration(Eighth))
  PlayTone( 1047,   32); wait1Msec( 353);  // Note(F6)
  PlayTone(  784,   16); wait1Msec( 176);  // Note(C6, Duration(Eighth))
  PlayTone(  784,   16); wait1Msec( 176);  // Note(C6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone( 1320,   16); wait1Msec( 176);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   16); wait1Msec( 176);  // Note(A6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   32); wait1Msec( 353);  // Note(D6)
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  PlayTone(  880,   16); wait1Msec( 176);  // Note(D6, Duration(Eighth))
  return;
}
