int x,y ;
int  a,b,c;
#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 8, 10, 11, 12, 13);
void setup()
{
pinMode(5,OUTPUT);
lcd.begin(16, 2);
Serial.begin(9600);

lcd.clear();
      lcd.print("PATIENT ALERT");
      lcd.setCursor(0, 1);
      lcd.print("SYSTEM");
      delay(100);
}
int readX() // returns the value of the touch screen's X-axis
{
int xr=0;
pinMode(14, INPUT);   // A0
pinMode(15, OUTPUT);    // A1
pinMode(16, INPUT);   // A2
pinMode(17, OUTPUT);   // A3
digitalWrite(15, LOW); // set A1 to GND
digitalWrite(17, HIGH);  // set A3 as 5V
delay(15); // short delay is required to give the analog pins time to adjust to their new roles
xr=analogRead(0); // 
return xr;
}
int readY() // returns the value of the touch screen's Y-axis
{
int yr=0;
pinMode(14, OUTPUT);   // A0
pinMode(15, INPUT);    // A1
pinMode(16, OUTPUT);   // A2
pinMode(17, INPUT);   // A3
digitalWrite(14, LOW); // set A0 to GND
digitalWrite(16, HIGH);  // set A2 as 5V
delay(15); // short delay is required to give the analog pins time to adjust to their new roles
yr=analogRead(1); //
 return yr;
}


void loop()
{

x=readX();

y=readY();
Serial.print(y);
delay(1000);
Serial.print(x);
delay(100);


 if ( y>550 && y<900 && x>550 && x <900)
  {
    a=1;
    //lcd.clear();
    //lcd.print("BED NO:1");
    //lcd.setCursor(0, 1);
    //lcd.print("EMERGENCY");
    delay(1000); 
                  
 
  } 
  else if (y>300 && y<550 &&  x <550)
    {
      b=1;
     //lcd.clear();
    //lcd.print("BED NO:1");
    //lcd.setCursor(0, 1);
    //lcd.print("WASHROOM");
    delay(1000);   
    
  } else if(y>550 && y<900 && x>0 && x<550)
    {
      c=1;
    //lcd.clear();
  //lcd.print("BED NO:1");
   //lcd.setCursor(0, 1);
//lcd.print("WATER");
    delay(1000);   
      
    }  

else if (y>0 && y<550 && x>550 && x <900)
    {
      
      if (a==1)
      {
      lcd.clear();
      lcd.print("BED NO:1");
      lcd.setCursor(0, 1);
      lcd.print("EMERGENCY");
      delay(1000);
      digitalWrite(5,HIGH);
      delay(1000);
       digitalWrite(5,LOW);
       delay(5000);
       a=0;
      }   
      
      else if (b==1)
      {
      lcd.clear();
      lcd.print("BED NO:1");
      lcd.setCursor(0, 1);
      lcd.print("WASHROOM");
      delay(1000);
      digitalWrite(5,HIGH);
      delay(1000);
      digitalWrite(5,LOW);
      delay(5000);
       b=0;
      } 
      
      else
      {
      lcd.clear();
      lcd.print("BED NO:1");
      lcd.setCursor(0, 1);
      lcd.print("WATER REQUIRED");
      delay(1000);
       digitalWrite(5,HIGH);
       delay(1000);
       digitalWrite(5,LOW);
       delay(5000);
       c=0;
      } 
      
  }
delay (200);
}
