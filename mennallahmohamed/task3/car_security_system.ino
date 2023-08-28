//start simulation with both buttons closed 
#include<Keypad.h>
#include<LiquidCrystal.h>
#include<Servo.h>
Servo servo;
LiquidCrystal lcd(A5, A4, 13, 12, 8, 7);  //Parameters: (rs, enable, d4, d5, d6, d7) ;
#define ccw A1
#define cw  A0
#define dc_speed A2
#define servoangle A3
#define IN1 10
#define IN2 9
#define servopin 11

const byte rows=4;
const byte col=3;
char keys[rows][col]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'},
  };
  byte rowpins[rows]={0,1,2,3};
  byte colpins[col]={4,5,6};
  Keypad keypad=Keypad(makeKeymap(keys),rowpins,colpins,rows,col);
String password="1234";
String pass;
char key;
int i=0;
int CCW,CW;
int flag;
int angle;
int SPEED;

void setup() {
  servo.attach(servopin);
  lcd.begin(16,2);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);

}

void loop() {
  readkeypad();
  if(key){
      lcd.setCursor(i,0);
       lcd.print('*');
       i++;
       
     if(i==4){
        if(pass==password){
      lcd.setCursor(0,1);
      lcd.print("Access granted");
      delay(500);
      lcd.clear();
      servo_angle();
        }
     
   else{
      lcd.setCursor(0,1);
      lcd.print("Access denied");
      pass="";
      delay(500);
      lcd.clear();
      i=0;
        }
     } }}

 void readkeypad(){
 key = keypad.getKey();
 String x=String(key);
    pass+=x;
    }
    
    void dc_motor(){
      while(1){
  SPEED=analogRead(dc_speed);
  SPEED=map(SPEED,0,1023,0,255);
  if (digitalRead(cw)){
    analogWrite(IN1,SPEED);
    delay(500);
    lcd.setCursor(0,0);
    lcd.print("speed=");
    lcd.setCursor(6,0);
    lcd.print(SPEED);
    lcd.setCursor(0,1);
    lcd.print("right_direction");
      }
    
   else if(digitalRead(ccw)){
      analogWrite(IN2,SPEED);
      lcd.setCursor(0,0);
      lcd.print("speed=");
      lcd.setCursor(6,0);
      lcd.print(SPEED);
      lcd.setCursor(0,1);
      lcd.print("left_direction");
      }
    else{
        lcd.clear();
      servo_angle();
      }
     
      }
    }
    
   
    void servo_angle(){
   while(1){
    angle=analogRead(servoangle);
    angle=map(angle,0,1023,0,180);
      servo.write(angle);
        lcd.setCursor(0,0);
        lcd.print("servo");
        lcd.setCursor(0,1);
        lcd.print("angle=");
        lcd.setCursor(6,1);
        lcd.print(angle);
    if(digitalRead(cw) || digitalRead(ccw)){
     lcd.clear();
     dc_motor();
    }
   }}
 
