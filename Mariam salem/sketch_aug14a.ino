#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

//keypad
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

const byte ROW_PINS[ROWS] = {3,2,1,0}; 
const byte COL_PINS[COLS] = {4,5,6}; 

Keypad keypad = Keypad(makeKeymap(keys), ROW_PINS, COL_PINS, ROWS, COLS);

 //password
char password[5] = "1234";  
char enteredPassword[5];
int passwordIndex = 0;
bool passwordCorrect = false;

int servoPin = 11;  
int dcMotorPin1 = 10;
int dcMotorPin2 = 9;
int buttonCWPin = A0;  
int buttonCCWPin = A1;  
int DCspeedPin = A3;  
int servoanglePin = A2; 

int counter=3;  //if i want to inc. number of tries before locking user out for password just change the value of counter

Servo servo;
LiquidCrystal lcd(A5,A4,13,12,8,7);
 

void setup() {
  //lcd welcome message
  lcd.begin(16, 2);
  lcd.setCursor(4,0);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("Enter password:");
  delay(1000);
  lcd.clear();
  
  //servo motor
  pinMode(servoanglePin, INPUT);
  pinMode(servoPin,OUTPUT);
  servo.attach(servoPin);
  
  //DC motor
  pinMode(buttonCWPin, INPUT_PULLUP);
  pinMode(buttonCCWPin, INPUT_PULLUP);
  pinMode(DCspeedPin, INPUT);
  pinMode(dcMotorPin1, OUTPUT);
  pinMode(dcMotorPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key != '\0') {
    //user has to press # as enter after typing password
    if (key == '#') {
      checkPassword();
      if (passwordCorrect) {
        while(1){
        //servomotor angle
          int angle=analogRead(servoanglePin);
          int servoAngle = map(angle, 0, 1023, 0, 180);
          servo.write(servoAngle);
          lcd.setCursor(0,0);
          lcd.print("Servo Angle: ");
          lcd.print(servoAngle);
      
     
      
      //DC Motor direction and speed
        if (digitalRead(buttonCWPin) == HIGH && digitalRead(buttonCCWPin) == LOW) {
          digitalWrite(dcMotorPin1,LOW);
          digitalWrite(dcMotorPin2,HIGH);
          int dcspeed=analogRead(DCspeedPin);
          int PWM = map(dcspeed, 0, 1024, 0, 255);
          analogWrite(dcMotorPin1,PWM);
          lcd.setCursor(0,1);
          lcd.print("DC:anticlockwise");
     
      } 
        else if (digitalRead(buttonCCWPin) == HIGH && digitalRead(buttonCWPin) == LOW) {
          digitalWrite(dcMotorPin1,HIGH);
           digitalWrite(dcMotorPin2,LOW);
           int dcspeed=analogRead(DCspeedPin);
           int PWM = map(dcspeed, 0, 1024, 0, 255);
          analogWrite(dcMotorPin2,PWM);
          lcd.setCursor(0,1);
          lcd.print("DC : clockwise");
     
      }
      else{
        lcd.setCursor(0,1);
        lcd.print("DC motor stopped");
        analogWrite(dcMotorPin2,0);
        analogWrite(dcMotorPin1,0);
      }
      }
      } 
      
    } 
    else if (passwordIndex <4) {
      enteredPassword[passwordIndex] = key;
      lcd.print('*');
      passwordIndex++;
    }
  }
}

void checkPassword() {
  if (strcmp(enteredPassword, password) == 0) {
    lcd.clear();
    lcd.print("Password correct");
    passwordCorrect = true;
    delay(500);
    lcd.clear();
    
  } 
  else {
   //if user enters 3 wrong passwords he is locked out for safety reasons
   counter--;
   if(counter>0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("#wrong password#");
    lcd.setCursor(2,1);
    lcd.print(counter);
    if(counter!=1){
    lcd.print(" tries left"); //showing for user number of tries left before locking him out if he doesn't write the correct password
    }
    else{
      lcd.print(" try left");
    }
    delay(2000);
    lcd.clear();
    lcd.print("Enter password:");
    delay(500);
    lcd.clear();
     memset(enteredPassword, 0, sizeof(enteredPassword));
     passwordIndex = 0;
     passwordCorrect = false;
    }
   else{
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Locked out");
    lcd.setCursor(0,1);
    lcd.print("too many tries");
    passwordCorrect = false;
    }
  
  }
}
