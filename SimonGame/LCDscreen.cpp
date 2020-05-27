#include <Arduino.h> 
#include <LiquidCrystal.h>
#include "LCDscreen.h"


LCDscreen::LCDscreen(const int mypin_rs, const int mypin_en, const int mypin_d4, const int mypin_d5, const int mypin_d6, const int mypin_d7):LiquidCrystal (mypin_rs, mypin_en, mypin_d4, mypin_d5, mypin_d6, mypin_d7){
    begin(16, 2);
}

void LCDscreen::WhoAmI(){
  Serial.print("Je suis un ecran LCD");
}



void LCDscreen::Display(char text[]){
  print(text);
}


void LCDscreen::CleanScreen(){
  clear();
}
