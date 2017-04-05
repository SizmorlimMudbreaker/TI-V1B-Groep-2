void turn_left()
{
  for(int i = 0; i <= 20; i++){
    motor[motorC] = 0;
    motor[motorB] = i;
    wait1Msec(50);
  }
  wait1Msec(1300);
}


void turn_right()
{
  for(int i = 0; i <= 20; i++){
    motor[motorC] = i;
    motor[motorB] = 0;
    wait1Msec(50);
  }
  wait1Msec(1300);
}


void move_forward()
{
  for(int i = 0; i <= 20; i++){
    motor[motorC] = i;
    motor[motorB] = i;
    wait1Msec(50);
  }
  wait1Msec(1300);
}


void turn_backward()
{
  for(int i = 0; i <= 20; i++){
    motor[motorC] = -i;
    motor[motorB] = i;
    wait1Msec(50);
  }
  wait1Msec(1300);
}


void stop_motor()
{
  for(int i = 20; 0 < i; i--){
    motor[motorC] = i;
    motor[motorB] = i;
    wait1Msec(50);
  }
}
