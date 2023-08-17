#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};     
byte colPins[COLS] = {5, 4, 3};        

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int segmentPins[7] = {A0, A1, A2, A3, A4, A5, 10}; 

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.println(key);
    displayNumber(key);
  }
}

void displayNumber(char number) {
  switch (number) {
    case '0':
      digitalWrite(segmentPins[0], HIGH);
      digitalWrite(segmentPins[1], HIGH);
      digitalWrite(segmentPins[2], HIGH);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], LOW);
      break;
    case '1':
      digitalWrite(segmentPins[0], LOW);
      digitalWrite(segmentPins[1], LOW);
      digitalWrite(segmentPins[2], LOW);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], LOW);
      digitalWrite(segmentPins[6], LOW);
      break;
    case '2':
      digitalWrite(segmentPins[0], LOW);
      digitalWrite(segmentPins[1], HIGH);
      digitalWrite(segmentPins[2], HIGH);
      digitalWrite(segmentPins[3], LOW);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], HIGH);
      break;
    case '3':
      digitalWrite(segmentPins[0], LOW);
      digitalWrite(segmentPins[1], LOW);
      digitalWrite(segmentPins[2], HIGH);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], HIGH);
      break;
    case '4':
      digitalWrite(segmentPins[0], HIGH);
      digitalWrite(segmentPins[1], LOW);
      digitalWrite(segmentPins[2], LOW);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], LOW);
      digitalWrite(segmentPins[6], HIGH);
      break;
    case '5':
      digitalWrite(segmentPins[0], HIGH);
      digitalWrite(segmentPins[1], LOW);
      digitalWrite(segmentPins[2], HIGH);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], LOW);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], HIGH);
      break;
    case '6':
      digitalWrite(segmentPins[0], HIGH);
      digitalWrite(segmentPins[1], HIGH);
      digitalWrite(segmentPins[2], HIGH);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], LOW);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], HIGH);
      break;
    case '7':
      digitalWrite(segmentPins[0], LOW);
      digitalWrite(segmentPins[1], LOW);
      digitalWrite(segmentPins[2], LOW);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], LOW);
      break;
    case '8':
      digitalWrite(segmentPins[0], HIGH);
      digitalWrite(segmentPins[1], HIGH);
      digitalWrite(segmentPins[2], HIGH);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], HIGH);
      break;
     case '9':
      digitalWrite(segmentPins[0], HIGH);
      digitalWrite(segmentPins[1], LOW);
      digitalWrite(segmentPins[2], HIGH);
      digitalWrite(segmentPins[3], HIGH);
      digitalWrite(segmentPins[4], HIGH);
      digitalWrite(segmentPins[5], HIGH);
      digitalWrite(segmentPins[6], HIGH);
      break;
    default:
      for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], LOW);
      }
      break;
  }
}
