#include <LiquidCrystal.h>
#include <Servo.h>
#define MotorIN1 11  //output pin to L293D
#define MotorIN2 6   //output pin to L293D
#define ServoPin 9   //pin attached to servo
#define MspeedPin A3 //potentiometer pin to control dc motor speed
#define AngleServPin A2 // potentiometer to control servo motor angle
/******************************************************/
Servo servo;
/*****************************************************/
const int rs = A5, en = A4, d4 = 13, d5 = 12, d6 = 10, d7 = 8;  //lcd pins
const char col = 3; // column of the keypad
const char row = 4 ; // rows of keypad
const char Password[6] = {'1','8','5','0','2','1'}; //password for security system
/*****************************************************/
int ServoReading,ServoAngle;   //variables to read servo angle
int DcMotorReading,DcMotorSpeed;  //variables to read speed of motor
char CW_Button = 0 , CCW_Button = 0;  // variables for direction buttons
char key_fetch = 0;   //variable used to read the key in the keypad scanning function
char correct = 0;     //variable used to check if the password is correct  
char cursor = 0;      // variable for cursor to move during writing the password and used in the backspace button part
char Pos = 0;         //varibale used as an index to the password array
int attempts = 5;     // number of available attempts
/***************************************************/
char Columns[3] = {4,5,7}; // keypad column pins .
char Rows[4] = {0,1,2,3}; // keypad row pins.
char key[4][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}}; //key matrix
/********************************************/
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
/***************************************************/
void check_key(void);  //function to read the keys and write on the lcd and uses '#' as a backspace button
void check_password(void);  //a function that checks the variable "correct" which indicates if the password is correct or not
void System_On(void);   // a function that turns the system on if the password is correct
void Servo(void);     //function for servo motor
void DcMotor(void);   // function for Dc motor
/***************************************************/
void setup()
 {
  servo.attach(9);
  lcd.begin(16, 2);
  
  pinMode(MotorIN1,OUTPUT);
  pinMode(MotorIN2,OUTPUT);
  pinMode(A0,INPUT_PULLUP); 
  pinMode(A1,INPUT_PULLUP); 
  pinMode(AngleServPin,INPUT);
  pinMode(MspeedPin,INPUT);    
  
  for (char i = 0 ; i < row ; i++)
  { 
    pinMode(Rows[i],INPUT_PULLUP);  // Rows of the matrix are set as input 
    if (i<3) pinMode(Columns[i],OUTPUT);  //column pins set as output to continuosly scan the rows.
  }

}
/*********************************************************/
void loop() 
{
  lcd.setCursor(0, 0); //initiate the lcd cursor
  lcd.print("Enter Password:");
  check_key(); //reading the keys and writing on lcd
}
/*********************************************************/

/*********************************************************/
void check_key() //this is the same function used in the previous but with some modifications
{ 
  for(char k = 0 ; k < col ; k++)
  {
    digitalWrite(Columns[k],LOW);
    for (char j = 0 ; j < row ; j++)
    {      
        if (digitalRead(Rows[j]) == LOW)
        {
          while(digitalRead(Rows[j]) == LOW)  // this while loop makes sure that the reading occurs after key is released to avoid multiple wrong readings
          {
            key_fetch = key[j][k];
          }
          delay(20);
          if(key_fetch == '#' && cursor != 0) // here I used the '#' key as a back space key and made sure when nothing is typed it's not activated
          {
            cursor --;    //cursor goes back one space
            Pos--;        //pasword index decreases
            correct = cursor; //the password checker goes back to same value as cursor
            lcd.setCursor(cursor,1);  //set cursor to the value of cursor
            lcd.print(" ");          // remove the previously typed '*'
          }
          else if(key_fetch != '#') // now if '#' is not pressed we read the password normally
          {          
            lcd.setCursor(cursor,1); //set the cursor , intially starts at position (0,1)
            lcd.print("*");         //after reading a key type '*' on the lcd
            cursor ++;              //cursor position moves
            if(key_fetch == Password[Pos] && correct < sizeof(Password)) /*if the current pressed key is equal to the key in password indicated by 
            {                                                            /* the 'Pos' variable and the password checker 'correct' is still less than*/
             correct ++;                                                 /* the size of password array then increas both varibales*/
             Pos++;       
            }       
            else      // if a key is wrong decrease the correct keys counter but increase the Pos to move to the next number in password array
            {
              correct--;
              Pos ++;
            } 
          }
    }     
    digitalWrite(Columns[k],HIGH);
    if(Pos == sizeof(Password)) //now if the number of keys entered is equal to the number of password elements , check if the password is correct
    {
      check_password();
    }
  }
}
/*********************************************************/

/*********************************************************/
void check_password(void)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  if(correct == sizeof(Password)) //if the number of correct keys is equal to size of password array then password is correct
  {
    lcd.print("Access granted!");  
    delay(1000);
    lcd.clear();
    System_On();      //since password is correct now we access the motors system    
  }
  else
  {
    attempts--; //if password is incorrect decrease number of attempts available
    lcd.print("Wrong! Try again");
    lcd.setCursor(0,1);
    lcd.print(attempts);
    lcd.print(" attempts left");
    Pos = cursor = correct = 0; //reseting the variables for the new password entry
    delay(1000);
    lcd.clear();
    if(attempts == 0)  //if the number of attempts are exceeded you'll be locked out for 30 seconds
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Try again after  ");
      lcd.setCursor(3,1);
      lcd.print("30 seconds");      
      delay(30000);
      lcd.clear();
      attempts = 5;   //after 30 seconds you will get another 5 attempts
    } 
  }
}
/*********************************************************/

/*********************************************************/
void System_On(void)
{
  while (true)  // infinite loop to stay in the motors system after using the correct password
  {
    Servo();
    DcMotor();
  }
}
/*********************************************************/

/*********************************************************/
void Servo(void)  
{
ServoReading = analogRead(AngleServPin); // read the angle potentiometer
ServoAngle = map(ServoReading , 0 , 1023 , 0 ,180); //map the values for the pwm pin
servo.write(ServoAngle);
lcd.setCursor(0,0);
lcd.print("ServoAngle:");
lcd.print(ServoAngle);
lcd.print("  ");

}
/*********************************************************/

/*********************************************************/
void DcMotor(void)
{
  DcMotorReading = analogRead(MspeedPin); // read the speed potentiometer
  DcMotorSpeed = map(DcMotorReading , 0 , 1023 , 0 ,255);  //map the values for the pwm pins
  CW_Button = digitalRead(A0);
  CCW_Button = digitalRead(A1);     //buttons for directions
  if(!CW_Button){analogWrite(MotorIN1,DcMotorSpeed);digitalWrite(MotorIN2,LOW);lcd.setCursor(0,1);lcd.print("DcDirection:Cw ");}
  else if(!CCW_Button){analogWrite(6,DcMotorSpeed);digitalWrite(11,LOW);lcd.setCursor(0,1);lcd.print("");lcd.print("DcDirection:CCW");}
  else{digitalWrite(MotorIN2,LOW);digitalWrite(MotorIN1,LOW);lcd.setCursor(0,1);lcd.print("Dc Stopped     ");} 
}


