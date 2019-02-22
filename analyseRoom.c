#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)//sets up touch
#pragma config(Motor,  motorB,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)//sets up the left wheel
#pragma config(Motor,  motorC,          motorRight,    tmotorEV3_Large, PIDControl, encoder)//sets up the right wheel
#pragma config(Sensor, S2, Gyro,     sensorEV3_Gyro)//sets up the gyro
#pragma config(sensor, S3, Color, sensorEV3_Color, modeEV3Color_Color)//sets up the light sensor to pickup colour
#pragma config(Sensor, S4,     Sonar,    sensorEV3_IRSensor, modeEV3IR_Proximity)//sets up the sonar to sense depth

void analyzeRoom()
{
	drawBmpfile(0, 127, "Talking");
		setMotorSpeed(motorLeft, -10);
		setMotorSpeed(motorRight, -10);
		wait1Msec(500);
		resetGyro(Gyro);
		wait1Msec(1000);
	//Speaker.Play(100, "ev3_sounds/Analyze");
		setSoundVolume(100);
		playSoundFile("Robotics/ev3_sounds/ev3_Sounds/Sounds/Files/Informaton/Analyze");
		//wait1Msec(1000);
	repeatUntil(getGyroDegrees(Gyro) == -75)
		{
				setMotorSpeed(motorLeft, -20);
				setMotorSpeed(motorRight, 20);
		}

		setMotorSpeed(motorLeft, 50);
		setMotorSpeed(motorRight, 50);
		wait1Msec(1000);

}