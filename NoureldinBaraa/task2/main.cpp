#include <Keypad.h> //I added the library in PlatformIO
//Put Variables and Inializations here
const int ROWS=4;
const int COLS=3;
char digits[ROWS][COLS]={
  '1','2','3',
  '4','5','6',
  '7','8','9',
  '*','0','#'
};
byte ROW_PINS[ROWS]={0,1,2,3}; //Can't use int here
byte COL_PINS[COLS]={4,5,6};  // I tried but it didn't work because of the Keypad Function
Keypad keypad=Keypad(makeKeymap(digits),ROW_PINS,COL_PINS,ROWS,COLS);
// put Function Declarations here:


void setup() {
  // put your setup code here, to run once:
  
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key=keypad.getKey();
  if(key){
    switch (key){
    case '0':
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      break;
    case '1':
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      break;
    case '2':
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      break;
    case '3':
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      break;
    case '4':
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      break;
    case '5':
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      break;
    case '6':
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      break;
    case '7':
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      break;
    case '8':
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      break;
    case '9':
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      break;
    default:
      
      break;
    }
  }
}
// put Function Definitions here:
