void turn_left()
{
  motor[motorB] = 30;
  motor[motorC] = 0;
  wait10Msec(5);
}

void turn_right()
{
  motor[motorB] = 0;
  motor[motorC] = 30;
  wait10Msec(5);
}

void move_forward()
{
	motor[motorB] = 30;
	motor[motorC] = 30;
	wait10Msec(5);
}

void turn_backward()
{
  motor[motorB] = 30;
  motor[motorC] = -30;
  wait10Msec(5);
}

void stop_motor()
{
  motor[motorB] = 0;
  motor[motorC] = 0;
  wait10Msec(5);
}
