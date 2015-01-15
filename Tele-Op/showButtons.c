// simple test program that displays button hits on NXT

#include "joystickDriver.c"

task main()
{
	while (true)
	{
		getJoystickSettings(joystick);

		// display button code on NXT
		eraseDisplay();
		for (int i=0, j=0; i<16; i++)
			if (joy1Btn(i))
				nxtDisplayStringAt(0,60-10*j++,"button%d",i);
	}
}
