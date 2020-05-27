#include <Arduino.h> 
#include "Game.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Creation and initialisation of all the sensors
//LCDscreen MyLCD(rs, en, d4, d5, d6, d7);
DigitalActuatorLED red_LED(pinLR);
DigitalActuatorLED blue_LED(pinLB);
DigitalActuatorLED green_LED(pinLG);
DigitalActuatorLED yellow_LED(pinLY);
ExternalDigitalSensorButton red_button(pinBR);
ExternalDigitalSensorButton blue_button(pinBB);
ExternalDigitalSensorButton green_button(pinBG);
ExternalDigitalSensorButton yellow_button(pinBY);
ExternalDigitalSensorButton menu_button(pinBMENU);

//all nedeed noises
DigitalActuatorBuzzer buzzer_sonOK(pinBuzzer, 0.5);
DigitalActuatorBuzzer buzzer_sonNOK(pinBuzzer, 5);
DigitalActuatorBuzzer buzzer_sonR(pinBuzzer, 1.0);
DigitalActuatorBuzzer buzzer_sonB(pinBuzzer, 2.0);
DigitalActuatorBuzzer buzzer_sonG(pinBuzzer, 3.0);
DigitalActuatorBuzzer buzzer_sonY(pinBuzzer, 4.0);


Game::Game(){
  velocity = 500;
  error_spot = -1;
  //Initialisation of the LEDs
  red_LED.Write(0);
  blue_LED.Write(0);
  green_LED.Write(0);
  yellow_LED.Write(0);
  lcd.begin(16, 2);
  lcd.print("SIMON GAME");
}
  
const int Game::MAX_LEVEL=25;
int Game::level=1;


int * Game::generate_sequence(){
  randomSeed(millis());
  static int sequence[MAX_LEVEL];
  for (int i = 0; i < MAX_LEVEL; i++){
    sequence[i] = random(pinLR,pinLY+1);
  }
  return sequence;
}



void Game::wrong_sequence(){
  lcd.begin(16,2);
  lcd.print("GAME OVER");
  for (int i = 0; i < 3; i++){
    red_LED.Write(1);
    blue_LED.Write(1);
    green_LED.Write(1);
    yellow_LED.Write(1);
    buzzer_sonNOK.ring();
    delay(250);
    red_LED.Write(0);
    blue_LED.Write(0);
    green_LED.Write(0);
    yellow_LED.Write(0);
    delay(250);
  }
  lcd.clear();
  level = 1;
  velocity = 500;
  error_spot=-1;
}


void Game::right_sequence(){
  lcd.begin(16,2);
  lcd.print("WELL DONE!");
  red_LED.Write(0);
  blue_LED.Write(0);
  green_LED.Write(0);
  yellow_LED.Write(0);
  delay(250);
  red_LED.Write(1);
  blue_LED.Write(1);
  green_LED.Write(1);
  yellow_LED.Write(1);
  buzzer_sonOK.ring();
  delay(500);
  red_LED.Write(0);
  blue_LED.Write(0);
  green_LED.Write(0);
  yellow_LED.Write(0);
  delay(500);
  lcd.clear();
  if (level < MAX_LEVEL);{
    level++;
  }
}


void Game::show_sequence(int *sequence){
  lcd.noDisplay();
  red_LED.Write(0);
  blue_LED.Write(0);
  green_LED.Write(0);
  yellow_LED.Write(0);
  for (int i = 0; i < level; i++){

    digitalWrite(sequence[i], HIGH);
    if (sequence[i]==pinLR){
      buzzer_sonR.ring();
    }
    if (sequence[i]==pinLB){
      buzzer_sonB.ring();
    }
    if (sequence[i]==pinLG){
      buzzer_sonG.ring();
    }
    if (sequence[i]==pinLY){
      buzzer_sonY.ring();
    }
    delay(velocity);
    digitalWrite(sequence[i], LOW);
    delay(200);
  }
}



void Game::get_sequence(int *sequence){
  int your_sequence[MAX_LEVEL];
  int flag = 0; //this flag indicates if the sequence is correct
  
  for (int i = 0; i < level; i++){
    flag = 0;
    while(flag == 0){
      if (red_button.GetState() == 1){
        red_LED.Write(1);
        buzzer_sonR.ring();
        your_sequence[i] = pinLR;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
            error_spot = i;
            wrong_sequence();
            return;
        }
        red_LED.Write(0);
      }
      if (blue_button.GetState() == 1){
        blue_LED.Write(1);
        buzzer_sonB.ring();
        your_sequence[i] = pinLB;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
            error_spot = i;
            wrong_sequence();
            return;
        }
        blue_LED.Write(0);
      }
      if (green_button.GetState() == 1){
        green_LED.Write(1);
        buzzer_sonG.ring();
        your_sequence[i] = pinLG;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
            error_spot = i;
            wrong_sequence();
            return;
        }
        green_LED.Write(0);
      }
      if (yellow_button.GetState() == 1){
        yellow_LED.Write(1);
        buzzer_sonY.ring();
        your_sequence[i] = pinLY;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
            error_spot = i;
            wrong_sequence();
            return;
        }
        yellow_LED.Write(0);
      }
    }
  }
  right_sequence();
}


int Game::choose_nb_of_players(){
  int nb_players = 1;
 

  return nb_players;
}

int Game::GetLevel(){
  return level;
}

void Game::test_boutons(){
   if (digitalRead(pinBR) == 1){ //red_button.GetState()
        red_LED.Write(1);
        delay(1000);
        red_LED.Write(0);
        level=12;
      }
   if (blue_button.GetState() == 1){
        blue_LED.Write(1);
        delay(3000);
        blue_LED.Write(0);
        level++;
      }
   if (green_button.GetState() == 1){
        green_LED.Write(1);
        delay(200);
        green_LED.Write(0);
        level++;
      }
   if (yellow_button.GetState() == 1){
        yellow_LED.Write(1);
        delay(600);
        yellow_LED.Write(0);
        level++;
      }
}
