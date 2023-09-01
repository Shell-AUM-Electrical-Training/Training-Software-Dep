#include <Arduino.h>
#include <DC_Motor/dc_motor.h>
#include <Servo.h>
#include <Keypad/keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


const int Password_Length = 6;
String Data;
byte Entry_Length=0;
String Password = "123456";
char key,key2;
int First_Activation=1;
int servoPIN =6;
String s;
int CW_BUTTON=13,CCW_BUTTON=12;


//setups
LiquidCrystal_I2C lcd(0x20,16,2);
Servo servo;

//Functions
void clearData()
{
  Entry_Length=0;
  Data="";
  First_Activation=1;
}
int restart()
{
  key2=getKeyPressed();
  while(!key2)
  {
    key2=getKeyPressed();
    if(key2=='#')
    {
      return 1;
    }
  }
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  //
  // Keypad setup
  keyPadSetup();


  // Setup LCD
  lcd.init();
  lcd.backlight();


  //lcd start
  lcd.setCursor(0, 0);
  lcd.print("Welcome\n");
  lcd.setCursor(0, 1);
  lcd.print("Enter Password:");


  //Dc motor setup
  motorSetup();
  pinMode(CW_BUTTON,INPUT);
  pinMode(CCW_BUTTON,INPUT);
  digitalWrite(CW_BUTTON,HIGH);
  digitalWrite(CCW_BUTTON,HIGH);


  //Servo motor setup
  pinMode(servoPIN,OUTPUT);
  pinMode(A3,INPUT);
  servo.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  key=getKeyPressed();
  if(key)
  {
    if(First_Activation) //To clear the lcd
    {
      First_Activation=0;
      lcd.clear();
    }
    Data+=key;
    lcd.setCursor(Entry_Length, 0);
    lcd.print("*");
    Entry_Length++;
    delay(300);
  }
  if(Entry_Length==Password_Length)
  {
    lcd.clear();
    if(Data==Password)
    {
      lcd.setCursor(0,0);
      lcd.print("User");
      lcd.setCursor(0,1);
      lcd.print("Authenticated :)");
      delay(900);
      lcd.clear();
      lcd.setCursor(0,0);

      while(1)
      {
        //DC motor
        if(digitalRead(CCW_BUTTON)==LOW&&digitalRead(CW_BUTTON)==LOW)
        {
          motorStop();
          lcd.setCursor(0, 1);
          lcd.println("DC motor stop");
        }
        else if(digitalRead(CW_BUTTON)==LOW)
        {
          updateMotorSpeed();
          motorTurnRight();
          lcd.setCursor(0, 1);
          lcd.println("Motor right");
        }
        else if (digitalRead(CCW_BUTTON)==LOW)
        {
          updateMotorSpeed();
          motorTurnLeft();
          lcd.setCursor(0, 1);
          lcd.println("Motor left  ");
        }
        else
        {
          motorStop();
          lcd.setCursor(0, 1);
          lcd.println("DC motor stop");
        }


        //Servo
        lcd.setCursor(0, 0);
        s="Servo angle:";
        s+=map(analogRead(A3),0,1023,-180,180);
        lcd.println(s);
        servo.write(map(analogRead(A3),0,1023,0,180));
      }
    }
    else
    {
      while(1) //To make it so that no other key will work
      {
        lcd.setCursor(0,0);
        lcd.print("Error! Press #");
        lcd.setCursor(0,1);
        lcd.print("to try again");
        //Restarting
        if(restart())
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          delay(1000);
          lcd.print("Welcome\n");
          lcd.setCursor(0, 1);
          lcd.print("Enter Password:");
          break;
        }
      }

    }
    clearData();
  }
  

}

// put function definitions here:
