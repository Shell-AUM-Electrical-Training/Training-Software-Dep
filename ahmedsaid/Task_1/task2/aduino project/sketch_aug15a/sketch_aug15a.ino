#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char keypadArray[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5,4,3,2};
byte colPins[COLS] = {6,7,8};

Keypad kpd = Keypad(makeKeymap(keypadArray), rowPins, colPins, ROWS, COLS); 


int a=A0;
int b=A1;
int c=11;
int d=12;
int e=13;
int f=A2;
int g=A3;


void one()
{

  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
 
  return;
}
void two()
{
 
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  
  return;
}
void three()
{

  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  
  return;
}
void four()
{
  
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
 
  return;
}
void five()
{

  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
 
  return;
}
void six()
{
 
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
 
  return;
}
void seven()
{
  
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);

  return;
}
void eight()
{

  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);

  return;
}
void nine()
{
  
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  
  return;
}
void zero()
{
 
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);

  return;
}
void setup()
{
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

}

void loop()
{

 char key='\0';
  label: key=kpd.getKey();
  Serial.println(key);

 if(key=='1') 
 {  
  one();
  goto label;
 }
 else if(key=='2')
 {
  two();
  goto label;
 }
   if(key=='3') 
 {  
  three();
  goto label;
 }
 else if(key=='4')
 {
  four();
  goto label;
 }
  else if(key=='5')
 {
  five();
  goto label;
 }
   if(key=='6') 
 {  
  six();
  goto label;
 }
 else if(key=='7')
 {
  seven();
  goto label;
 }
  else if(key=='8')
 {
  eight();
  goto label;
 }
   else if(key=='9')
 {
  nine();
  goto label;
 }
   else if(key=='0')
 {
  zero();
  goto label;
 }
  else
  {
    Serial.println(" ");
  }
}