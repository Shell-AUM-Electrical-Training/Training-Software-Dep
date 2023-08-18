#include <Arduino.h>
#include <Keypad.h>

const byte rows = 4;
const byte col = 3;

char hexa[rows][col] = {
    {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};
byte rowPIN[rows] = {4, 3, 2, 1};
byte colPIN[col] = {5, 6, 7};
Keypad ckl = Keypad(makeKeymap(hexa), rowPIN, colPIN, rows, col);
int data;

void setup()
{
  /*pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(8,OUTPUT);*/
  data = 0;
}

void loop()
{
  DDRB = 15;
  char ck = ckl.getKey();
  switch (ck)
  {
  case '1':
    PORTB = 1;
    data = PORTB;
    break;
  case '2':
    PORTB = 2;
    data = PORTB;
    break;
  case '3':
    PORTB = 3;
    data = PORTB;
    break;
  case '4':
    PORTB = 4;
    data = PORTB;
    break;

  case '5':
    PORTB = 5;
    data = PORTB;
    break;
  case '6':
    PORTB = 6;
    data = PORTB;
    break;
  case '7':
    PORTB = 7;
    data = PORTB;
    break;
  case '8':
    PORTB = 8;
    data = PORTB;
    break;
  case '9':
    PORTB = 9;
    data = PORTB;
    break;
  case '0':
    PORTB = 0;
    data = PORTB;
    break;

  default:
 PORTB= data ;
    break;
  }
}
