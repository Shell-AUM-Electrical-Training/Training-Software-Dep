#ifndef _CAR_SEC_H
#define _CAR_SEC_H

#include <Arduino.h>
#include "keyypad.h"

void Open();
void cleararray();
void wrongpass();
void start_motors();
void servomotor();
void dc_motor();
void end_motors();


#endif