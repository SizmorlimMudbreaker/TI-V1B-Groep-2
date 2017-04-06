void turn_left()
{
	motor[motorB] = 30;
	motor[motorC] = 0;
	wait1Msec(50);
}

void turn_right()
{
	motor[motorB] = 0;
	motor[motorC] = 30;
	wait1Msec(50);
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
