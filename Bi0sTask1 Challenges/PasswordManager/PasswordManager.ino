#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(7,6,5,4,3,2);
char password[] = "CAB#1729";
String passwordarr[2]= {"Gmail:YOLO343","Facebook:BYE145"};
char enterkey ;
int position = 0 ;
int counter = 0 ;
const byte ROWS = 4;
const byte COLS = 4;
char keyMap[ROWS][COLS]= {{'1' , '2' , '3' , 'A'},
              {'4' , '5' , '6' , 'B'},
              {'7' , '8' , '9' , 'C'},
              {'*' , '0' , '#' , 'D'}};
byte rowpins[ROWS] ={8,9,10,11};
byte colpins[COLS] ={A0,A1,A2,A3};
Keypad mykeypad = Keypad(makeKeymap(keyMap),rowpins,colpins,ROWS,COLS);

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Wlcm 2 Pwd Mngr");
  delay(500);
  lcd.clear();
}

void loop()
{
  enterkey = mykeypad.getKey();
  lcd.setCursor(0,0);
  lcd.print("Enter password");
  lcd.setCursor(0,1);
  lcd.print(enterkey);
  if ((enterkey=='C')||(enterkey=='A')||(enterkey=='B')||(enterkey=='1')||(enterkey=='7')||(enterkey=='2')||(enterkey=='9')||(enterkey=='#'))
    counter++;
  if (enterkey == password[position])
  {
    position++;     
  }
  if (((enterkey=='*')||(enterkey=='3')||(enterkey=='4')||(enterkey=='5')||(enterkey=='6')||(enterkey=='8')||(enterkey=='D')||(enterkey=='0'))||(counter!=position))   
  {
    position= 0;
    counter=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Invalid Pwd");
    delay(500);
    lcd.clear();
  }
  if (position==8)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Correct password");
    delay(500);
    lcd.clear();
    for (int k =1;k>=0;k--)
    { 
      lcd.setCursor(0,k);
      lcd.print(passwordarr[k]);
      if (k==0)
        while(1){};
    }
  }
}
  

  
    
