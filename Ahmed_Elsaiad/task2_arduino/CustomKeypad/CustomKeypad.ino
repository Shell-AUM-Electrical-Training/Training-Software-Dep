/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
int i;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {11, 12, 13}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  for(i=2 ; i < 6 ; i++)
  {
    pinMode(i,OUTPUT);
  }
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
  if(customKey == '1')
  {
      digitalWrite(2,1);
      digitalWrite(3,0);
      digitalWrite(4,0);
      digitalWrite(5,0);
  }
  else if(customKey == '2')
  {
      digitalWrite(2,0);
      digitalWrite(3,1);
      digitalWrite(4,0);
      digitalWrite(5,0);
  }
  else if(customKey == '3')
  {
      digitalWrite(2,1);
      digitalWrite(3,1);
      digitalWrite(4,0);
      digitalWrite(5,0);
  }
  else if(customKey == '4')
  {
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,1);
      digitalWrite(5,0);
  }
  else if(customKey == '5')
  {
      digitalWrite(2,1);
      digitalWrite(3,0);
      digitalWrite(4,1);
      digitalWrite(5,0);
  }
  else if(customKey == '6')
  {
      digitalWrite(2,0);
      digitalWrite(3,1);
      digitalWrite(4,1);
      digitalWrite(5,0);
  }
  else if(customKey == '7')
  {
      digitalWrite(2,1);
      digitalWrite(3,1);
      digitalWrite(4,1);
      digitalWrite(5,0);
  }
  else if(customKey == '8')
  {
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,0);
      digitalWrite(5,1);
  }
  else if(customKey == '9')
  {
      digitalWrite(2,1);
      digitalWrite(3,0);
      digitalWrite(4,0);
      digitalWrite(5,1);
  }
  else if(customKey == '0')
  {
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,0);
      digitalWrite(5,0);
  }


}
