void turn_left()
{
	for(int i = 0; i < 19; i++){
		motor[motorB] = i;
		motor[motorC] = -i * 0.55;
		wait1Msec(50);
	}
	wait1Msec(100);
}

void turn_right()
{
	for(int i = 0; i < 19; i++){
		motor[motorC] = i;
		motor[motorB] = -i * 0.55;
		wait1Msec(50);
	}
	wait1Msec(100);
}

void move_forward()
{
	motor[motorB] = 30;
	motor[motorC] = 30;
	wait1Msec(50);
}

void turn_backwards()
{
	motor[motorB] = 30;
	motor[motorC] = -30;
	wait1Msec(50);
}

void stop_motor()
{
	motor[motorB] = 0;
	motor[motorC] = 0;
	wait1Msec(50);
}

void shoot()
{
	motor(motorA) = 2;
	wait1Msec(3000);
	motor(motorA) = 0;
}
