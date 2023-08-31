#include "dc_motor.h"


u8 Q1 = 5;
u8 Q2 = 3;
u8 motorSpeed = 255;

void motorSetup()
{
    pinMode(Q1, OUTPUT);
    pinMode(Q2, OUTPUT);
    pinMode(A2,INPUT);
}


void motorTurnRight()
{
    analogWrite(Q1,motorSpeed);
    digitalWrite(Q2,LOW);
}

void motorTurnLeft()
{
    analogWrite(Q2,motorSpeed);
    digitalWrite(Q1,LOW);
}

void motorStop()
{
    digitalWrite(Q1,LOW);
    digitalWrite(Q2,LOW);
}

void updateMotorSpeed()
{
    motorSpeed = map(analogRead(A2),0,1023,0,255);
}