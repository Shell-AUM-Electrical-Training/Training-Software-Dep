#include <Keypad.h>
void SevenSegmnt(char num);

const byte ROWS = 4; //four rows


const byte COLS = 3; //four columns


char keys[ROWS][COLS] = {


  {'1','2','3'},


  {'4','5','6'},


  {'7','8','9'},


  {'*','0','#'}


};


byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad


byte colPins[COLS] = {4, 5, 6}; //connect to the column pinouts of the keypad


//Create an object of keypad


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){

////////7 SEG//////////
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
  


} 


void loop(){


  char key = keypad.getKey();// Read the key
  

  // Print if key pressed


  if (key)
  {
    SevenSegmnt(key);

  }


}

void SevenSegmnt(char num)
{
  switch(num)
  {
    case '0':
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);  
      break;
     
     case '1':
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW); 
      break;
      
     case '2':
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);  
      break;
     
     case '3':
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);  
      break;
     
     case '4': 
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);

      break;
     case '5':
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);  
      break;
    case '6':
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);  
      break;
    case '7':
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);  
      break;
    case '8':
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);  
      break;
    case '9':
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);  
      break;
    
    default:
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);  
      break;
      
  
  
  }
}
