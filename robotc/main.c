#pragma config(Sensor, S1,     light1,         sensorLightActive)
#pragma config(Sensor, S2,     light2,         sensorColorNxtRED)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          leopold,       tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, driveLeft, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Links 34, 67, S2
//Rechts 35, 66, S1

#pragma platform(NXT)

#include "remote_control.c";

long nLastXmitTimeStamp = nPgmTime;
long nDeltaTime = 0;

const int kMaxSizeOfMessage = 30;
const int INBOX = 5;

// Toggle tussen automatisch en handmatig.
bool toggle_mode = false;

// Controleert of er een object voor het apparaat staat.
void measure_sonar(int sensor_value)
{
	if(sensor_value <= 15){
		for(int i = 20; 0 <= i; --i){
			motor(motorB) = i;
			motor(motorC) = i;
			wait10Msec(5);
		}
		motor(motorA) = 2;
		wait10Msec(600);
		motor(motorA) = 0;
	}
}

// Toggle tussen automatisch en handmatig.
void switch_mode()
{
	TFileIOResult nBTCmdRdErrorStatus;
	int nSizeOfMessage;
	ubyte nRcvBuffer[kMaxSizeOfMessage];
	
	while(1){
		if (nSizeOfMessage > kMaxSizeOfMessage)
			nSizeOfMessage = kMaxSizeOfMessage;
		if (nSizeOfMessage > 0){
			nBTCmdRdErrorStatus = cCmdMessageRead(nRcvBuffer, nSizeOfMessage, INBOX);
			nRcvBuffer[nSizeOfMessage] = '\0';
			string input = "";
			stringFromChars(input, (char *) nRcvBuffer);
			
			if(input == "B"){
				toggle_mode = true;
				nxtDisplayCenteredTextLine(4, "start remote");
			} else if(input == "C"){
				nxtDisplayCenteredTextLine(4, "stop remote");
			}
		}
  }
}

// Handmatige besturing via bluetooth.
void remote_control()
{
	TFileIOResult nBTCmdRdErrorStatus;
	int nSizeOfMessage;
	ubyte nRcvBuffer[kMaxSizeOfMessage];
	
	while(1){
		if (nSizeOfMessage > kMaxSizeOfMessage)
			nSizeOfMessage = kMaxSizeOfMessage;
		if (nSizeOfMessage > 0){
			nBTCmdRdErrorStatus = cCmdMessageRead(nRcvBuffer, nSizeOfMessage, INBOX);
			nRcvBuffer[nSizeOfMessage] = '\0';
			string input = "";
			stringFromChars(input, (char *) nRcvBuffer);
			displayCenteredBigTextLine(4, input);
			
			if(input == "LEFT"){
				turn_left();
			} else if(input == "RIGHT"){
				turn_right();
			} else if(input == "DOWN"){
				turn_backward();
			} else if(input == "UP"){
				move_forward();
			} else if(input == "A"){
				stop_motor();
			} else if(input == "FIRE"){
				// Vuurt een elastiekje af.
			}
		}
	}
}


// Volgt de zwarte lijn automatisch.
void follow_line()
{
	int light_right = SensorValue[S1];
	int light_left = SensorValue[S2];
	int ultrasonic = SensorValue[S4];
	
	motor[motorB] = (2*(light_right-light_left*0.5-15));
	motor[motorC] = (2*(light_left-light_right*0.5-15));
	
	//if(light_right < 37 && light_left < 37){
	//	stop_motor();
	//	remote_control();
	//}
	
	measure_sonar(ultrasonic);
}


task main()
{
	while(1){
		switch_mode();
		if(toggle_mode == true){
			remote_control();
		} else {
			follow_line();
		}
		wait1Msec(1);
	}
}
