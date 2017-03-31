task main()
{
  while(1)
  {
    int light_right = sensorValue[S1];
    int light_left = sensorValue[S2];
    int ultrasonic = sensorValue[S4];

     motor[motorB] = (2*(light_right-light_left*0.5-15));
    motor[motorC] = (2*(light_left-light_right*0.5-15));
    if(light_right < 37 && light_left < 37)
    {
      motor0();
      if(richting() == 'L') // Alle for loops versnellen wiel X in richting Y tot 20 en draaien daarna voor 1 seconde op die snelheid door. Daarna gaat de standaardfunctie weer verder
      {
        deg90left();
      }
      else if(richting() == 'R')
      {
        deg90right();
      }
      else if (richting() == 'B')
       {
         deg180left();
      }
      else
      {
        forward();
      }
    }
  wait1Msec(1);
  }
}