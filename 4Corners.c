#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)//sets up touch
#pragma config(Motor,  motorB,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)//sets up the left wheel
#pragma config(Motor,  motorC,          motorRight,    tmotorEV3_Large, PIDControl, encoder)//sets up the right wheel
#pragma config(Sensor, S2, Gyro,     sensorEV3_Gyro)//sets up the gyro
#pragma config(sensor, S3, Color, sensorEV3_Color, modeEV3Color_Color)//sets up the light sensor to pickup colour
#pragma config(Sensor, S4,     Sonar,    sensorEV3_IRSensor, modeEV3IR_Proximity)//sets up the sonar to sense depth

void fireRoom()
{
		drawBmpfile(0, 127, "Fire");
		resetGyro(Gyro);
		wait1Msec(1000);

		repeatUntil(getGyroDegrees(Gyro) == 170)
		{
				setMotorSpeed(motorLeft, 30);
				setMotorSpeed(motorRight, -30);
		}

	  //setMotorSyncTime(motorLeft,motorRight,0, 500, -20);
		setMotorSpeed(motorLeft, -20);
		setMotorSpeed(motorRight, -20);
		wait1Msec(500);
		resetGyro(Gyro);
		wait1Msec(1000);

		repeatUntil(getGyroDegrees(Gyro) == 75)
		{
				setMotorSpeed(motorLeft, 30);
				setMotorSpeed(motorRight, -30);
		}
		//setMotorSyncTime(motorLeft,motorRight,0, 2000, 50);
		setMotorSpeed(motorLeft, 50);
		setMotorSpeed(motorRight, 50);
		wait1Msec(2000);

}


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

void rescueRoom() {
	drawBmpfile(0, 127, "Evil");
}

void wallRoom() {
	drawBmpfile(0, 127, "US sensor");
}

task main()
{
	if(SensorValue(Sonar) > 65) {
		repeatUntil(SensorValue(Color) == 5 || SensorValue(Touch) == 1){
			setMotorSpeed(motorLeft, 50);
			setMotorSpeed(motorRight, 50);
		}
		if(SensorValue(Color) == 5){
			setMotorSpeed(motorLeft, 0);
			setMotorSpeed(motorRight, 0);
			fireRoom();
		}
		else{
			analyzeRoom();
		}
	}
	else {
		if(SensorValue(Sonar) < 40) {
			rescueRoom();
		}
		else {
			wallRoom();
		}
	}
}
