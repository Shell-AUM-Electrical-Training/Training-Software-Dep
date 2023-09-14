#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

Servo servo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD pins
const byte ROWS = 4;
const byte COLS = 3;

const int motorDirection1Pin = 8; // Motor direction control pin 1
const int motorDirection2Pin = 9; // Motor direction control pin 2
const int motorSpeedPin = 10;     // Motor speed control pin
const int servoPin = 9;           // Servo control pin (changed to a digital PWM pin)
const int button1Pin = 7;         // Button 1 for motor direction control
const int button2Pin = 13;        // Button 2 for motor direction control

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {0, 1, A2, A3}; // Connect these to the ROW pins on the keypad
byte colPins[COLS] = {A4, A5, 6};  // Connect these to the COL pins on the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char password[] = "1234"; // Set your desired password
char enteredPassword[5] = "";
boolean authenticated = false;

void setup() {
  pinMode(motorDirection1Pin, OUTPUT);
  pinMode(motorDirection2Pin, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  servo.attach(servoPin);
  lcd.begin(16, 2); // Initialize the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      checkPassword();
    } else {
      appendPassword(key);
    }
  }

  if (authenticated) {
    // Read buttons and potentiometers for motor and servo control
    int motorSpeed = analogRead(A0); // Read motor speed from potentiometer (change to A0 or the correct pin)
    int servoAngle = map(analogRead(A1), 0, 1023, 0, 180); // Read servo angle from potentiometer (change to A1 or the correct pin)
    int button1State = digitalRead(button1Pin);
    int button2State = digitalRead(button2Pin);

    // Control the DC motor based on button states
    if (button1State == LOW && button2State == HIGH) {
      digitalWrite(motorDirection1Pin, HIGH);
      digitalWrite(motorDirection2Pin, LOW);
    } else if (button1State == HIGH && button2State == LOW) {
      digitalWrite(motorDirection1Pin, LOW);
      digitalWrite(motorDirection2Pin, HIGH);
    } else {
      digitalWrite(motorDirection1Pin, LOW);
      digitalWrite(motorDirection2Pin, LOW);
    }

    // Control motor speed and servo angle
    analogWrite(motorSpeedPin, motorSpeed);
    servo.write(servoAngle);

    // Display motor and servo status on LCD
    lcd.setCursor(0, 1);
    lcd.print("Motor Speed: " + String(motorSpeed));
    lcd.setCursor(0, 2);
    lcd.print("Servo Angle: " + String(servoAngle));
  }
}

void appendPassword(char key) {
  if (strlen(enteredPassword) < 4) {
    strcat(enteredPassword, &key);
    lcd.setCursor(strlen(enteredPassword) - 1, 1);
    lcd.print('*');
  }
}

void checkPassword() {
  if (strcmp(enteredPassword, password) == 0) {
    authenticated = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access granted");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access denied");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter password:");
    memset(enteredPassword, 0, sizeof(enteredPassword));
  }
}
