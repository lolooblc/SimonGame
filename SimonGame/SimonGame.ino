//#include <LiquidCrystal.h>
#include "Game.h"

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  Serial.begin(9600);
//  lcd.begin(16, 2);
//  lcd.noDisplay();
//  lcd.display();
//  lcd.print("SIMON GAME");
}

void loop()
{
//  lcd.clear();

//  delay(5000);
//  lcd.clear();
  Game SimonGame;
  Serial.println(SimonGame.GetLevel());
   
  static int *sequence;
  sequence=SimonGame.generate_sequence(); //generate a sequence;
  while (digitalRead(pinBMENU) == LOW && SimonGame.GetLevel() == 1){
    
  }
  
  while (digitalRead(pinBMENU) == HIGH || SimonGame.GetLevel() != 1){ //If start button is pressed or you're winning//

    SimonGame.show_sequence(sequence);
    SimonGame.get_sequence(sequence);     //wait for your sequence    
  }
}
