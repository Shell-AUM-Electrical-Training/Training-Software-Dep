#include <Arduino.h>
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(A5, A4, 13, 12, 8, 7);

const int motorPin1 = 10;
const int motorPin2 = 9;

const int servoPin = 11;

const int servospeed = A2;
const int motorspeed = A3;

const int clockwiseButtonPin = A0;
const int counterclockwiseButtonPin = A1;

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};
byte rowPins[ROWS] = {3, 2, 1, 0};
byte colPins[COLS] = {6, 5, 4};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo servo;
const char PASSWORD[] = "1234";
char enteredPassword[5];
int passwordIndex = 0;
bool authenticated = false;

void setup()
{

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(clockwiseButtonPin, INPUT_PULLUP);
  pinMode(counterclockwiseButtonPin, INPUT_PULLUP);

  servo.attach(servoPin);

  lcd.begin(16, 2);
  lcd.print("Enter password:");

  Serial.begin(9600);
}

void loop()
{
  if (!authenticated)
  {
    char key = keypad.getKey();

    if (key != NO_KEY)
    {
      if (key == '#')
      {
        enteredPassword[passwordIndex] = '\0';
        if (strcmp(enteredPassword, PASSWORD) == 0)
        {
          lcd.clear();
          lcd.print("Access granted!");
          authenticated = true;
        }
        else
        {
          lcd.clear();
          lcd.print("Access denied!");
          delay(2000);
          lcd.clear();
          lcd.print("Enter password:");
        }
        passwordIndex = 0;
      }
      else if (passwordIndex < 4)
      {
        lcd.setCursor(passwordIndex + 6, 1);
        lcd.print('*');
        enteredPassword[passwordIndex] = key;
        passwordIndex++;
      }
    }
  }
  else
  {

    int clockwiseButtonState = digitalRead(clockwiseButtonPin);
    int counterclockwiseButtonState = digitalRead(counterclockwiseButtonPin);
    int servoPotValue = analogRead(servospeed);
    int motorPotValue = analogRead(motorspeed);

    int servopwm = map(servoPotValue, 0, 1023, 0, 180);
    int motorpwm = map(motorPotValue, 0, 1023, 0, 255);

    servo.write(servopwm);

    if (clockwiseButtonState == LOW)
    {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      analogWrite(motorPin2, motorpwm);
      lcd.clear();
      lcd.print("Motor: CW");
    }
    else if (counterclockwiseButtonState == LOW)
    {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      analogWrite(motorPin1, motorpwm);
      lcd.clear();
      lcd.print("Motor: CCW");
    }
    else
    {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      lcd.clear();
      lcd.print("Motor: Stop");
    }

    lcd.setCursor(0, 1);
    lcd.print("Servo:");
    lcd.print(servopwm);
    lcd.print(" MotorSpeed:");
    lcd.print(motorpwm);

    delay(100);
  }
}