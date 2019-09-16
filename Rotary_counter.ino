/* Rotary encoder test code
 * Modified from http://www.circuitsathome.com/mcu/programming/reading-rotary-encoder-on-arduino by Oleg
 * Latest mod by Jessica Faruque 7/17/2013
 */


 // include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int voltage_value = 0; 
int analogPin = A0;
 
#define ENC_A 6 //these need to be digital input pins
#define ENC_B 7
 
void setup()
{
  /* Setup encoder pins as inputs */
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
 
  Serial.begin (9600);
  Serial.println("Start");

    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}
 
void loop()
{
  static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
  static unsigned int counter = 0;
  static unsigned int prevCounter = 0;
  int tmpdata;
  tmpdata = read_encoder();
  if( tmpdata) {
    counter4x += tmpdata;
    counter = counter4x/4;
    if (prevCounter != counter){
      Serial.print("Counter value: ");
      Serial.println(counter);

      lcd.clear();
      lcd.print("Counter:");
      lcd.print(counter);
      delay(100);
      
    }
    prevCounter = counter;
  }
}
 
/* returns change in encoder state (-1,0,1) */
int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
 
 
}
