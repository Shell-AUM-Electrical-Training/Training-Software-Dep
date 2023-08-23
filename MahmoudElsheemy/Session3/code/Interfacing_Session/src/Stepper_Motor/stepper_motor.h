#include "Arduino.h"

#define SINGLE_STEP_ANGLE (5.625)

void stepperMotorSetup();
// static void fullStepCW();
// static void fullStepCCW();
void stepperMotorTurnAngle(u8 angle);
void stepperMotorTurnAngleCCW(u8 angle);
void fullStepBiCW();