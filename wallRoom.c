#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     sonor,          sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     colour,         sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorA,          A,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          B,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          C,             tmotorNXT, PIDControl, encoder)

void wallRoom() {
	//drawBmpfile(0, 127, "US sensor");
	
	while (SensorValue(S4) > 10){
		motor[motorA] = 70;
		motor[motorB] = 70;
	}
	motor[motorA] = -100;
	motor[motorB] = -100;
	wait1Msec(200);


  motor[motorA] = 100;
	motor[motorB] = -100;
	wait1Msec(300);

    while (SensorValue(S4) > 10){
      motor[motorA] = 70;
  		motor[motorB] = 70;
    }
motor[motorA] = -100;
	motor[motorB] = -100;
	wait1Msec(200);
    motor[motorA] = -100;
  	motor[motorB] = 100;
  	wait1Msec(250);

    while (SensorValue(S4) > 15){
      motor[motorA] = 70;
  		motor[motorB] = 70;
    }
motor[motorA] = -100;
	motor[motorB] = -100;
	wait1Msec(300);
    motor[motorA] = 100;
  	motor[motorB] = -100;
  	wait1Msec(230);

    motor[motorA] = 100;
  	motor[motorB] = 100;
  	wait1Msec(300);
}
