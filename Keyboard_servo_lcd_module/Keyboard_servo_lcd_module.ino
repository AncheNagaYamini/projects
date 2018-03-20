
#include <LiquidCrystal.h>
#include <PS2Keyboard.h>
#include <Servo.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i=0;
const int DataPin = 2;//For Arduino Uno
const int IRQpin =  3;//For Arduino Uno
char inData[100]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character
PS2Keyboard keyboard;
Servo myservo1;
Servo myservo2;
Servo myservo3; 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  keyboard.begin(DataPin, IRQpin, PS2Keymap_US);
  
  Serial.begin(9600);
  lcd.print("Welcome");
  delay(2000);
  lcd.clear();
  lcd.print("Please scan your Medicine card");
  delay(3000);
  lcd.clear();
  lcd.print("Enter medicine name");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop() 
{

  if (keyboard.available())
  {
    
    if(index < 32) // One less than the size of the array
    {
      inChar = keyboard.read(); // Read a character
      inData[index] = inChar; // Store it
      index++; // Increment where to write next
      inData[index] = '\0'; // Null terminate the string
    }
    String str((char*)inData);
    Serial.print(inChar);// testing the char typed by printing
    if (index<=20)
      {
         lcd.print(inChar);
       } else if (index>20)
        {
          lcd.scrollDisplayLeft();
          lcd.print(inChar);
         }
       
       if (inChar == PS2_ENTER) 
       {
        myservo1.attach(8);
        myservo2.attach(9);
        myservo3.attach(10);
        switch(str){
          case "citrizen": 
            myservo1.write(101);
            delay(9000);
            myservo1.detach();
            break;
          case "rabekind": 
            myservo2.write(101);
            delay(9000);
            myservo2.detach();
            break;
          case "vomikind": 
            myservo3.write(101);
            delay(9000);
            myservo3.detach();
            break;
          default:
            lcd.clear();
            lcd.print("Medicine not Found!!");
       }
        
      for( int i = 0; i < sizeof(inData);  ++i ) //clear old char array
        inData[i] = (char)0;
        index=0;
      }
  }
 }


