#include "keyypad.h"

unsigned char keymapchar[4][4]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

unsigned char col_pins[4]={6,7,8};
unsigned char row_pins[4]={9,10,A4,A5};
unsigned int i;
unsigned int row;
unsigned int col;
void keypad_setup(void)
{
  for(i=0 ; i<4 ; i++)
  {
    pinMode(col_pins[i],INPUT_PULLUP);
    pinMode(row_pins[i],OUTPUT);
  }
}

unsigned char getkey()
{
  for(row=0 ; row<4 ; row++)
  {
    digitalWrite(row_pins[0],1);
    digitalWrite(row_pins[1],1);
    digitalWrite(row_pins[2],1);
    digitalWrite(row_pins[3],1);


    digitalWrite(row_pins[row],0);

    for(col=0 ; col<4 ; col++)
    {
      if(!digitalRead(col_pins[col]))
      {
        return keymapchar[row][col];
      }
    }
    
    
  }
  return NULL;
}