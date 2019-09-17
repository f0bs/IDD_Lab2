#include <LiquidCrystal.h>
#include "pitches.h"
#define BTN 10

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 4, 8, 4, 8
};

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int buttonState = 0;         
int countTime = 0;
bool clicked = false;
 
void setup()
{
 
  lcd.begin(16, 2);

  pinMode(BTN, INPUT);
  lcd.clear();
  lcd.print("Click button to");
  lcd.setCursor(0,1);
  lcd.print("set nap timer");
}
 
void loop() {
  lcd.setCursor(0, 0);
  static unsigned int counter = 10;
  static unsigned int prevCounter = 0;
  
  buttonState = digitalRead(BTN);
  
    if (buttonState == HIGH) {
      clicked = true;
     
      countTime = counter + ((millis() / 1000) + 1); 
      lcd.clear();
      lcd.print("Nap timer is set");
      delay(1000);
      lcd.print(counter);
      lcd.clear();
    }
  
  if (clicked == true) {
    delay(1000);
    lcd.clear();
    CountDown();
 }
}

void CountDown(){
  lcd.clear();
  lcd.print("Time remaining:");
  lcd.setCursor(0, 1);

  int secRemaining = countTime - (millis() / 1000);

  if (secRemaining > 0){
    lcd.print(secRemaining);
    lcd.print(" sec");
  } else {
    lcd.clear();
    lcd.print("Time to wake up!!!");
    alarm();
  }

}

void alarm() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
