#include <LiquidCrystal.h>
#include "Game.h" //NE PAS OUBLIER DE LE REMETTRE !!!!!!!!



void setup() 
{
  Serial.begin(9600);
}

void loop()
{
    Game SimonGame;
    int *sequence;
    sequence=SimonGame.generate_sequence(); //generate a sequence;

//  if (SimonGame.GetLevel() == 1){
//   
//  }

    if (digitalRead(pinBMENU) == HIGH || SimonGame.GetLevel() != 1){ //If start button is pressed or you're winning//
//    lcd.noDisplay();

    //SimonGame.show_sequence(sequence);
    //SimonGame.get_sequence(sequence);     //wait for your sequence
    SimonGame.test_boutons();
    
  }
}
