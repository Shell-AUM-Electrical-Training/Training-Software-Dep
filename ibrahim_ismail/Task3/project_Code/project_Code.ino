/*..Libraries..*/
#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

/*..Macros..*/
#define CW_Button A2
#define CCW_Button A3
#define IN1 10
#define IN2 9
#define DC_POT A1
#define Servo_Pin 11
#define Servo_POT A0

/*..function declarations... */
void LcdDisplay();
void Password();
void WrongPass();
void TruePass();
void DC_Motor_Control();
void Servo_Motor_Control();

/*..Variable Declaration..*/
Servo servo;
int Access = 0;
int attempts=4;

//*Declarations For KeyPad
const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte rowPins[ROWS] = {3, 2, 1, 0};

byte colPins[COLS] = {4, 5, 6};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//* FOR LCD
LiquidCrystal lcd(A5, A4, 7, 8, 12, 13);

//======================================================================================================================

/*............SetUp Function.................*/

void setup()
{
  LcdDisplay();
  pinMode(CW_Button, INPUT_PULLUP);
  pinMode(CCW_Button, INPUT_PULLUP);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(DC_POT, INPUT);
  pinMode(Servo_POT, INPUT);
  pinMode(Servo_Pin, OUTPUT);
  servo.attach(Servo_Pin);
}

//=======================================================================================================================

/*............Main Function.................*/
void loop()
{
  Password();
  while (Access == 1)
  {
    DC_Motor_Control();

    Servo_Motor_Control();
  }
}

//=========================================================================================================================

/*...........Functions Defination.........*/

//*  lcd Function

void LcdDisplay()
{
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("Welcome");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Pass:");
  lcd.setCursor(0, 1);
  lcd.print("(#) for Enter ");
  delay(1000);
  lcd.clear();
}

//*  Password Function

void Password()
{
  char key = customKeypad.getKey();
  static char pass[5];
  static int passIndex = 0;

  if (key)
  {

    lcd.print("*");
    pass[passIndex] = key;
    passIndex++;

    if (key == '#')
    {
      pass[passIndex] = '\0'; // Add null terminator to the password array
      passIndex = 0;

      if (strcmp(pass, "1234#") == 0)
      {
        TruePass();
      }
      if (!strcmp(pass, "1234#") == 0)
      {

        WrongPass();
      }
    }
  }
}

//*  Truepass Function

void TruePass()
{
  
  lcd.clear();
  lcd.print("Access Accepted");
  delay(500);
  lcd.clear();
  Access = 1;
  return;
}

//*  WrongPass Function

void WrongPass()
{  

  --attempts;
  if (attempts==0)
  { lcd.clear();
    lcd.print("ExceededAttempts");
    lcd.setCursor(0,1);
    lcd.print("Try again in 10s");
    delay(10000);
    lcd.clear();
     attempts=4;
     return;
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Denied");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("remained tries=");
  lcd.print(attempts);
  delay(500);
  lcd.clear();

  Access = 0;
  return;
}

//*  DCMotor Function

void DC_Motor_Control()
{
  int motorSpeed = map(analogRead(A1), 0, 1023, 0, 255);
  motorSpeed = constrain(motorSpeed, 0, 255);
  int b1 = digitalRead(CW_Button);
  int b2 = digitalRead(CCW_Button);
  if (b1 == LOW)
  {
    digitalWrite(IN1, motorSpeed);
    digitalWrite(IN2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("");
    lcd.print("DC Motor  (CW) ");
  }
  else if (b2 == LOW)
  {
    digitalWrite(IN2, motorSpeed);
    digitalWrite(IN1, LOW);
    lcd.setCursor(0, 0);
    lcd.print("");
    lcd.print("DC Motor (CCW) ");
  }
  else
  {
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, LOW);
    lcd.setCursor(0, 0);
    lcd.print("");
    lcd.print("DC Motor is off");
  }
}

//* Servo Function

void Servo_Motor_Control()
{

  int ServoAngle = map(analogRead(A0), 0, 1023, 0, 180);
  ServoAngle = constrain(ServoAngle, 0, 180);
  servo.write(ServoAngle);
  lcd.setCursor(0, 1);
  lcd.print("");
  lcd.print("Servo  Angle=");
  lcd.print(ServoAngle);
}
