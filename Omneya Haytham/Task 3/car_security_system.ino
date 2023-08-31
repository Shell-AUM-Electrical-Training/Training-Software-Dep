#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

//.......................................DCMotor...................................
const int motorPin1 = 10;  // Motor control pin 1
const int motorPin2 = 9;  // Motor control pin 2

int forward_button = A0;
int backward_button = A1;

const int potPin = A3;

int potValue;
int motorValue ;


//.......................................SERVO MOTOR...............................
int servopin = 11;

const int anglePin = A2;   // Potentiometer pin for controlling servo angle

Servo servo;

int servoAngle = 0;


//........................................LCD.......................................
String storedPassword = "1234"; // Stored password for authentication
String enteredPassword = "";    // Variable to store the entered password


// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(A5, A4, 13, 12,8, 7);

//.....................................KEYPAD.....................................
const byte ROWS = 4;  // Number of rows on the keypad
const byte COLS = 3;  // Number of columns on the keypad

// Define the keypad layout
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Define the keypad pins
byte rowPins[ROWS] = {0, 1, 2, 3};    // Connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6};    // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int Trials = 2;
bool isAuthenticated = false;

void setup() {

//...............DCMotor............
  pinMode(forward_button, INPUT);
  pinMode(backward_button, INPUT);
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(potPin,INPUT);
  
  digitalWrite(forward_button,HIGH);
  digitalWrite(backward_button,HIGH);

//................Servo Motor......
  pinMode(servopin,OUTPUT);

  pinMode(anglePin,INPUT);
  
  servo.attach(servopin);



//................LCD..............
  lcd.begin(16, 2); // Initialize the LCD
  lcd.setCursor(4, 0);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("Car_Security_System");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter password: ");
  
}

void loop() {
  updateMotorSpeed();
  if (!isAuthenticated) {
    Handle_Authentication();
  } else {
      Handle_DCMotor();
  }
}

  
void Handle_Authentication(){
  char key = keypad.getKey(); // Get the pressed key from the keypad

  if (key) {
    lcd.setCursor(enteredPassword.length(), 1); // Set cursor position on the second line of the LCD
    lcd.print("*");                   // Display asterisk on the LCD
    enteredPassword += key;           // Add the pressed key to the entered password string

    // Check if the entered password length matches the stored password length
    if (enteredPassword.length() == storedPassword.length()) {
      delay(100); // Wait for 500 milliseconds to display the result

      // Check if the entered password matches the stored password
      if (enteredPassword == storedPassword) {
        isAuthenticated = true;
        lcd.clear();                  // Clear the LCD display
        lcd.setCursor(0, 0);
        lcd.print("Sucsessful access");   // Display success message
        delay(1000);                  // Wait for 2 seconds
        lcd.clear();                  // Clear the LCD display
        lcd.setCursor(0, 0);
        
      } 
      if(enteredPassword != storedPassword) {
    
        if (Trials == 0 ){
          lcd.setCursor(0, 0);
          lcd.print("Failed to Access");
          lcd.setCursor(0, 1);
          lcd.print("Out of trials");
          delay(1000);
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("End process");
          }

        if (Trials >0 ){
          lcd.clear();                  // Clear the LCD display
          lcd.setCursor(0, 0);
          lcd.print("Access denied");   // Display error message
          lcd.setCursor(0, 1);
          lcd.print("You have ");
          lcd.setCursor(9, 1);
          lcd.print(Trials);
          lcd.setCursor(10, 1);
          lcd.print(" trials");
          
          delay(1000);                  // Wait for 2 seconds
          lcd.clear();                  // Clear the LCD display
          lcd.setCursor(0, 0);
          lcd.print("Enter password:");  // Prompt for the next password
          Trials -=1;
      }
      }
 
      enteredPassword = ""; // Reset the entered password string
    }
  }
  }

void handleServoControl() {
  servoAngle = map(analogRead(anglePin), 0, 1023, 0, 180);
  servo.write(servoAngle);

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Servo Angle: ");
  lcd.setCursor(6, 1);
  lcd.print("    "); // Clear the previous angle value
  lcd.setCursor(6, 1);
  lcd.print(servoAngle);

  delay(100);
}


void motorTurnRight(){
  analogWrite(motorPin2,motorValue);
  analogWrite(motorPin1,0);
  }

void motorTurnLeft()
{
  analogWrite(motorPin1,motorValue);
  analogWrite(motorPin2,0);
}

void updateMotorSpeed()
{
  potValue = analogRead (potPin);
  motorValue = map(potValue, 0, 1023, 0, 255);
}


void Handle_DCMotor(){
  int forwardbutton = digitalRead(forward_button);
  int backwardbutton = digitalRead(backward_button);


  updateMotorSpeed();
  Serial.println(motorValue);
  
  if(forwardbutton == 0 && backwardbutton == 1){

    updateMotorSpeed();
    motorTurnRight();
    Serial.println(motorValue);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Motor Speed:");
    lcd.setCursor(13, 0);
    lcd.print(motorValue);
    lcd.setCursor(0, 1);
    lcd.print("Motor:Right");
    delay(1000);
    handleServoControl();}
    
  else if(backwardbutton == 0 && forwardbutton == 1){
      
    updateMotorSpeed();
    motorTurnLeft();
    Serial.println(motorValue);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Motor Speed:");
    lcd.setCursor(13, 0);
    lcd.print(motorValue);
    lcd.setCursor(0, 1);
    lcd.print("Motor:Left");
    delay(1000);
    handleServoControl();}
    
}
