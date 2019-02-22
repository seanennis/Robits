#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)//sets up touch
#pragma config(Motor,  motorB,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)//sets up the left wheel
#pragma config(Motor,  motorC,          motorRight,    tmotorEV3_Large, PIDControl, encoder)//sets up the right wheel
#pragma config(Sensor, S2, Gyro,     sensorEV3_Gyro)//sets up the gyro
#pragma config(sensor, S3, Color, sensorEV3_Color, modeEV3Color_Color)//sets up the light sensor to pickup colour
#pragma config(Sensor, S4,     Sonar,    sensorEV3_IRSensor, modeEV3IR_Proximity)//sets up the sonar to sense depth

void rescueRoom() {
	drawBmpfile(0, 127, "Evil");
}