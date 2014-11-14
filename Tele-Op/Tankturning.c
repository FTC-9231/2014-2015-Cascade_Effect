#include "motorSetup.h"
#include "functionsLibrary.h"
#include "JoystickDriver.c"
task main(){
	while(true){
		getJoystickSettings(joystick);
		motor[motorD] = joystick.joy1_y1;
		motor[motorE] = joystick.joy1_y2;
		if(joy1Btn(2)){
		motor[motorF] = 50;
		motor[motorG] = 50;
	}else if(joy1Btn(3)){
		motor[motorF] = -50;
		motor[motorG] = -50;
	}else{
		motor[motorF] = 0;
		motor[motorG] = 0;
	}

	}
}
