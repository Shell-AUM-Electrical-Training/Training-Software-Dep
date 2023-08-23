#include "Arduino.h"
#include "keypad.h"


u8 keyCharMap[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};

u8 colPins[4] = {2,3,4,5};
u8 rowPins[4] = {7,8,9,6};




void keyPadSetup(void)
{
    for(u8 i =0; i<4;i++)
    {
        pinMode(colPins[i],INPUT_PULLUP);
        pinMode(rowPins[i],OUTPUT);
    }

}


u8 getKeyPressed()
{
    for(u8 row = 0; row < 4; row++)
    {
        //turn all rows high
        digitalWrite(rowPins[0],HIGH);
        digitalWrite(rowPins[1],HIGH);
        digitalWrite(rowPins[2],HIGH);
        digitalWrite(rowPins[3],HIGH);

        digitalWrite(rowPins[row], LOW);
        //digitalWrite(rowPins[],)
        for(u8 col=0; col<4; col++)
        {
            if(!digitalRead(colPins[col]))
            {
                return keyCharMap[row][col];
            }
        }
        //digitalWrite(rowPins[row],HIGH);
    }
    return NULL;
}