#include <Servo.h>
#include <LiquidCrystal.h>

// Pin Definitions
const int button1Pin = 2;
const int button2Pin = 3;
const int potentiometerPinDC = A0;
const int potentiometerPinSE = A1;
const int servoPin = 9;
const int motorEnablePin = 10;
const int motorDirection1Pin = 11;
const int motorDirection2Pin = 12;

// Password for access
const String correctPassword = "1234";
String enteredPassword = "";

// LCD setup
LiquidCrystal lcd(8, 7, 6, 5, 4);

// Servo setup
Servo myservo;

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Enter password:");
  
  // Attach servo
  myservo.attach(servoPin);
  
  // Set motor pins as outputs
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorDirection1Pin, OUTPUT);
  pinMode(motorDirection2Pin, OUTPUT);
  
  // Set button pins as inputs
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  
  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Read password input
  readPassword();

  // Check if the entered password is correct
  if (enteredPassword == correctPassword) {
    lcd.clear();
    lcd.print("Access granted!");
    delay(1000);
    lcd.clear();
    lcd.print("System start");
    
    // Control loop
    while (true) {
      // Read button states
      bool button1State = digitalRead(button1Pin);
      bool button2State = digitalRead(button2Pin);
      
      // Read potentiometer value for motor speed
      int motorSpeed = map(analogRead(potentiometerPinDC), 0, 1023, 0, 255);
      
      // Read potentiometer value for servo angle
      int servoAngle = map(analogRead(potentiometerPinSE), 0, 1023, 0, 180);
      
      // Control motor direction using buttons and H-bridge
      if (button1State == HIGH) {
        digitalWrite(motorDirection1Pin, HIGH);
        digitalWrite(motorDirection2Pin, LOW);
        analogWrite(motorEnablePin, motorSpeed); // Set motor speed
      } else if (button2State == HIGH) {
        digitalWrite(motorDirection1Pin, LOW);
        digitalWrite(motorDirection2Pin, HIGH);
        analogWrite(motorEnablePin, motorSpeed); // Set motor speed
      } else {
        digitalWrite(motorDirection1Pin, LOW);
        digitalWrite(motorDirection2Pin, LOW);
        analogWrite(motorEnablePin, 0); // Stop motor
      }
      
      // Control servo angle
      myservo.write(servoAngle);
      
      // Display motor status and servo angle on LCD
      lcd.setCursor(0, 1);
      lcd.print("Speed:");
      lcd.print(motorSpeed);
      lcd.print(" Angle:");
      lcd.print(servoAngle);
      
      // Delay for stability
      delay(100);
    }
  } else {
    lcd.clear();
    lcd.print("Access denied!");
    delay(1000);
    lcd.clear();
    lcd.print("Enter password:");
  }
}

void readPassword() {
  while (Serial.available() > 0) {
    char input = Serial.read();
    if (input == '\n') {
      if (enteredPassword == correctPassword) {
        enteredPassword = "";
      } else {
        break;
      }
    } else {
      enteredPassword += input;
      Serial.print('*');
    }
    delay(10);
  }
}
