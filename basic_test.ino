/* Linear magnetic Hall sensor (KY-024) [S048] : http://rdiot.tistory.com/94 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int pin = A0;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(pin,INPUT);
  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S048:Linear Mag Hall");

  int val = analogRead(pin);

  lcd.setCursor(0,1);
  lcd.print("val=" + (String)val + "  ");

  if(val >= 527 && val <= 528)
  {
    lcd.setCursor(0,2);
    lcd.print("nomally = 527~528");    
  }
  else if (val < 527)
  {
    lcd.setCursor(0,2);
    lcd.print("under 527 : N     ");    
  }
  else if (val > 528)
  { 
    lcd.setCursor(0,2);
    lcd.print("over 527 : S      ");       
  }
  delay(200);
}
