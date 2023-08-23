#include "stepper_motor.h"

u8 coilA = 5;
u8 coilB = 4;
u8 coilC = 3;
u8 coilD = 2;

u8 biPinOne = 13;
u8 biPinTwo = 12;
u8 biPinThree = 11;
u8 biPinFour = 10;


void stepperMotorSetup()
{
    Serial.begin(9600);
    pinMode(coilA,OUTPUT);
    pinMode(coilB,OUTPUT);
    pinMode(coilC,OUTPUT);
    pinMode(coilD,OUTPUT);
    // pinMode(biPinOne,OUTPUT);
    // pinMode(biPinTwo,OUTPUT);
    // pinMode(biPinThree,OUTPUT);
    // pinMode(biPinFour,OUTPUT);
}   

void fullStepBiCW()
{
    digitalWrite(biPinOne,HIGH);
    digitalWrite(biPinFour,HIGH);
    delay(2000);
    digitalWrite(biPinOne,LOW);
    digitalWrite(biPinFour,LOW);
    delay(2000);
    digitalWrite(biPinTwo,HIGH);
    digitalWrite(biPinThree,HIGH);
    delay(2000);
    digitalWrite(biPinTwo,LOW);
    digitalWrite(biPinThree,LOW);

}


static void fullStepCW()
{
    //step 1
    digitalWrite(coilA,HIGH);
    digitalWrite(coilB,LOW);
    digitalWrite(coilC,LOW);
    digitalWrite(coilD,LOW);
    delay(100);

    //step 2
    digitalWrite(coilA,LOW);
    digitalWrite(coilB,HIGH);
    digitalWrite(coilC,LOW);
    digitalWrite(coilD,LOW);
    delay(100);
    //step 3
    
    digitalWrite(coilA,LOW);
    digitalWrite(coilB,LOW);
    digitalWrite(coilC,HIGH);
    digitalWrite(coilD,LOW);
    delay(100);
    //step 4
    digitalWrite(coilA,LOW);
    digitalWrite(coilB,LOW);
    digitalWrite(coilC,LOW);
    digitalWrite(coilD,HIGH);
    delay(100);
}


static void fullStepCCW()
{
    //step 1
    digitalWrite(coilA,LOW);
    digitalWrite(coilB,LOW);
    digitalWrite(coilC,LOW);
    digitalWrite(coilD,HIGH);
    delay(100);
    //step 2
    digitalWrite(coilA,LOW);
    digitalWrite(coilB,LOW);
    digitalWrite(coilC,HIGH);
    digitalWrite(coilD,LOW);
    delay(100);
    //step 3
    digitalWrite(coilA,LOW);
    digitalWrite(coilB,HIGH);
    digitalWrite(coilC,LOW);
    digitalWrite(coilD,LOW);
    delay(100);
    //step 4
    digitalWrite(coilA,HIGH);
    digitalWrite(coilB,LOW);
    digitalWrite(coilC,LOW);
    digitalWrite(coilD,HIGH);
    delay(100);
}
void stepperMotorTurnAngle(u8 angle)
{
    //determine the number of steps to turn
    u16 numOfSteps = angle / SINGLE_STEP_ANGLE; 
    //Serial.print(numOfSteps);
    for(u16 i = 0; i<numOfSteps; i++)
    {
        fullStepCW();
    }
    

} 




void stepperMotorTurnAngleCCW(u8 angle)
{
    //determine the number of steps to turn
    u16 numOfSteps = angle / SINGLE_STEP_ANGLE; 
    //Serial.print(numOfSteps);
    for(u16 i = 0; i<numOfSteps; i++)
    {
        fullStepCCW();
    }
    

} 


