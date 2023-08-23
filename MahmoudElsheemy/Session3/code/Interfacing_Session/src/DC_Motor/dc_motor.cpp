#include "dc_motor.h"

u8 Q1 = 10;
u8 Q2 = 9;
u8 motorSpeed = 255;

void motorSetup()
{
    pinMode(Q1, OUTPUT);
    pinMode(Q2, OUTPUT);
    pinMode(A0,INPUT);
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

void updateMotorSpeed()
{
    motorSpeed = map(analogRead(A0),0,1023,0,255);
}