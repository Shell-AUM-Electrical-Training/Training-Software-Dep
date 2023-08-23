#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal.h>



LiquidCrystal lcd(10,11,12,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Hello World\n");
  delay(200);


}