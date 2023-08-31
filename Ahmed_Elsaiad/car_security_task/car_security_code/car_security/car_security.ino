#include <LiquidCrystal.h>
#include "car_sec.h"
#define pass_length 5

const int servoPin = 13;  
int servo_potpin=A1;
unsigned int servoread,final_servoread;
unsigned int tries=2;
unsigned char def_pass[pass_length]="1234";
unsigned char pass[pass_length];
unsigned int count=0;
unsigned int validation=1;
char key;
int cw=1;
int ccw=0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  lcd.begin(16, 2);
  keypad_setup();
  pinMode(servoPin, OUTPUT);
  pinMode(servo_potpin, INPUT);
  pinMode(cw, INPUT_PULLUP);
  pinMode(ccw, INPUT_PULLUP);
    
  
}

void loop() {
  if (validation == 0)
  {
    key = getkey();

    if (key == '#')

    {
      lcd.clear();
      
      lcd.print("system Turnedoff");
      end_motors();
      delay(3000);
      validation = 1;
    }
    else
    {
      start_motors();
      delay(30);
    }
  }

  else Open();
  
 
}

void Open()
{
  
  lcd.setCursor(0, 0);
  lcd.print(" Enter Password");
  
  key = getkey();
  delay(200);
  if (key)
  {
    pass[count] = key; 
    lcd.setCursor(count, 1); 
    lcd.print("*");
    count++;
  }

  if (count == pass_length-1) 
  {
    if (!strcmp(pass, def_pass)) 
    {
      lcd.clear();
      
      lcd.print("  valid password");
      lcd.setCursor(0, 1);
      lcd.print("  welcome :)");
      lcd.clear();
      start_motors();
      validation = 0;
    }
    else if (tries!=0)
    {
      lcd.clear();
      lcd.print("  Wrong Password");
      lcd.setCursor(0, 1);
      lcd.print("remain  ");
      lcd.print(tries);
      lcd.print(" tries  ");
      tries--;
      delay(2000);
      lcd.clear();
      validation = 1;
    }
    else
    {
      wrongpass();
    }
    cleararray();
  }
}

void cleararray()
{
  while (count != 0)
  { 
    pass[count--] = 0; 
  }
  return;
}

void wrongpass()
{
  tries=2;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TryAgainAfter20s");
  for(count=1 ; count<21 ; count++)
  {
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }
}

void start_motors()
{
  servomotor();
  dc_motor();
}

void servomotor()
{
  servoread=analogRead(servo_potpin);
  final_servoread=map(servoread,0,1024,0,180);
  digitalWrite(servoPin, HIGH);
  delay(final_servoread);
  digitalWrite(servoPin, LOW);
  delay(20);

  lcd.setCursor(0, 0);
  lcd.print("servo angle :");
  lcd.print(final_servoread );
  lcd.print("  ");
  delay(30);
}

void dc_motor()
{
  if( (!digitalRead(cw)) && (!digitalRead(ccw)) )
  {
    analogWrite(A2,0);
    analogWrite(A3,0);
    lcd.setCursor(0, 1);
    lcd.print("ERROR!motor stop");
    

  }
  else if (!digitalRead(ccw))
  {
    analogWrite(A2,0);
    analogWrite(A3,150);
    lcd.setCursor(0, 1);
    lcd.print("   motor left   ");
  }
  else if (!digitalRead(cw))
  {
    analogWrite(A2,150);
    analogWrite(A3,0);
    lcd.setCursor(0, 1);
    lcd.print("   motor right   ");
  }
  else
  {
    analogWrite(A2,0);
    analogWrite(A3,0);
    lcd.setCursor(0, 1);
    lcd.print("   motor stopped   ");
  }
}

void end_motors()
{
  servoread=analogRead(servo_potpin);
  final_servoread=map(servoread,0,1024,0,180);
  digitalWrite(servoPin, LOW);
  delay(final_servoread);
  digitalWrite(servoPin, LOW);
  delay(20);
  analogWrite(A2,0);
  analogWrite(A3,0);

}