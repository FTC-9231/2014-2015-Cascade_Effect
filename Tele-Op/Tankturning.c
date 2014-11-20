#include "motorSetup.h"
#include "JoystickDriver.c"
#pragma DebuggerWindows("debugStream")
task main(){
	clearDebugStream();
	int servo1pos = ServoValue[servo1];
	getJoystickSettings(joystick);
	while(true){
		motor[motorD] = ((joystick.joy1_y1 - 32768)*100) / 32768;
		motor[motorE] = ((joystick.joy1_y2 - 32768)*100) / 32768;
		if(joy1Btn(2) == 1){
		writeDebugStreamLine("button 2 check");
		motor[motorF] = 50;
		motor[motorG] = 50;
	}else if(joy1Btn(3) == 1){
	writeDebugStreamLine("button 3 check");
		motor[motorF] = -50;
		motor[motorG] = -50;
	}else{
		motor[motorF] = 0;
		motor[motorG] = 0;
  }if(joy1Btn(1) == 1){
  	writeDebugStreamLine("button 1 check");
  	servo[servo1] = servo1pos++;
  }else if(joy1Btn(4) == 1){
  writeDebugStreamLine("button 4 check");
  	servo[servo1] = servo1pos--;
	}}}
