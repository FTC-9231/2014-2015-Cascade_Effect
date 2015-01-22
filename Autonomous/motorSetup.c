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
//You can use this instead of the Motor Config program, it will allow you to keep everything stock.