#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "joystickDriver.c"
#include "toggleButton.c"
#include "filters.c"
#include "joystickButtons.h"

#define ButtonArmUp ButtonRB
#define ButtonArmDown ButtonRT
#define ButtonGateUp ButtonLB
#define ButtonGateDown ButtonLT
#define ButtonHookUp ButtonA
#define ButtonHookDown ButtonB

#define ButtonGateToggle ButtonLB
#define ButtonHookToggle ButtonLT

#define ButtonReverseToggle ButtonB

#define PowerArmUp 50
#define PowerArmDown -50

#define AngleGateUp 87
#define AngleGateDown 360

#define AngleHookUp 0
#define AngleHookDown 180

#define JoyThreshold 10

#define WheelMotorRampLimit 5
#define ArmMotorRampLimit 2

task main()
{
	ToggleButton gateTB;
	ToggleButton_init(&gateTB, ButtonGateToggle, 2, 0);

	ToggleButton hookTB;
	ToggleButton_init(&hookTB, ButtonHookToggle, 2, 0);

	ToggleButton reverseTB;
	ToggleButton_init(&reverseTB, ButtonReverseToggle, 2, 0);

	// since the ThresholdFilter is stateless, we can share it between both joysticks
	ThresholdFilter joyTF;
	ThresholdFilter_init(&joyTF, JoyThreshold);

	// but we need a separate filter for each joystick because it remembers state
	RampFilter rampJoy1;
	RampFilter_init(&rampJoy1, WheelMotorRampLimit, 0);
	RampFilter rampJoy2;
	RampFilter_init(&rampJoy2, WheelMotorRampLimit, 0);

	// here's a filter for the arm motors
	RampFilter rampArm;
	RampFilter_init(&rampArm, ArmMotorRampLimit, 0);

	servo[gate] = AngleGateDown;
	servo[hook] = AngleHookUp;

	while (true)
	{
		getJoystickSettings(joystick);

		ToggleButton_process(&reverseTB);
		if (ToggleButton_value(&reverseTB)==1)
		{
			motor[leftWheel] = RampFilter_process(&rampJoy1, ThresholdFilter_process(&joyTF, -joystick.joy1_y2));
			motor[rightWheel] = RampFilter_process(&rampJoy2, ThresholdFilter_process(&joyTF, -joystick.joy1_y1));
		}
		else
		{
			// feed the joystick inputs through filters before assigning to the wheel motors
			motor[leftWheel] = RampFilter_process(&rampJoy1, ThresholdFilter_process(&joyTF, joystick.joy1_y1));
			motor[rightWheel] = RampFilter_process(&rampJoy2, ThresholdFilter_process(&joyTF, joystick.joy1_y2));
		}

		// also filter the power value we send to the arm motors when those buttons are pushed
		short armPower = 0;
		if (joy1Btn(ButtonArmUp))
			armPower = RampFilter_process(&rampArm, PowerArmUp);
		else
		if (joy1Btn(ButtonArmDown))
			armPower = RampFilter_process(&rampArm, PowerArmDown);
		motor[leftArm] = armPower;
		motor[rightArm] = armPower;


#if 0
		// use two buttons to lower and raise hook
		if (joy1Btn(ButtonHookUp))
			servo[hook] = AngleHookUp;
		else
		if (joy1Btn(ButtonHookDown))
			servo[hook] = AngleHookDown;
#else
		// use one toggle button to lower and raise hook
		if (ToggleButton_process(&hookTB))
			servo[hook] = ToggleButton_value(&hookTB) ? AngleHookDown : AngleHookUp;
#endif

#if 0
		// use two buttons to lower and raise gate
		if (joy1Btn(ButtonGateUp))
			servo[gate] = AngleGateUp;
		else
		if (joy1Btn(ButtonGateDown))
			servo[gate] = AngleGateDown;
#else
		// use one toggle button to lower and raise hook
		if (ToggleButton_process(&gateTB))
			servo[gate] = ToggleButton_value(&gateTB) ? AngleGateDown : AngleGateUp;
#endif

	}
}
