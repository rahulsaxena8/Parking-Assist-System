#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int trig1=6,echo1=7;
int trig2=8,echo2=9;
int piezoPin=10;

void setup() {
  lcd.begin(16, 2);
  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(echo2,INPUT);
  pinMode(piezoPin,OUTPUT);
}

void loop() {
 
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  int x= pulseIn(echo1,HIGH);
  int d1= (0.034*x)/2;
  
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  int y= pulseIn(echo2,HIGH);
  int d2= (0.034*y)/2;
  
  lcd.setCursor(0,0);
  lcd.print("RIGHT GAP=");
  
  if(d1<=15 || d2<=15)
  {
    tone(piezoPin,1500,500);
  }
  
  if(d1>15)
  {
    lcd.print(d1+1);
    lcd.print("cm");
  }
  else{
    lcd.print("ALERT!!");
  }
  
  lcd.setCursor(0,1);
  lcd.print("LEFT GAP=");
  
  if(d2>15)
  {
    lcd.print(d2+1);
    lcd.print("cm");
  }
  else{
    lcd.print("ALERT!");
  }
  
  delay(1000);
  lcd.clear();
}
