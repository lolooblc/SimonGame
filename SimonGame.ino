#include <LiquidCrystal.h>

#define pinBR A0
#define pinBB A1
#define pinBG A2
#define pinBY A3
#define pinBMENU A4
#define pinLR 6
#define pinLB 7
#define pinLG 8
#define pinLY 9
#define BUZZER 10

int velocity = 500;
int error_spot = -1;
int beeplong = 160;

const int MAX_LEVEL = 25; //velocity/abs(vchange);
int sequence[MAX_LEVEL];
int your_sequence[MAX_LEVEL];
int level = 1;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() 
{
  pinMode(pinBR, INPUT);
  pinMode(pinBB, INPUT);
  pinMode(pinBG, INPUT);
  pinMode(pinBY, INPUT);
  
  pinMode(pinLR, OUTPUT);
  pinMode(pinLB, OUTPUT);
  pinMode(pinLG, OUTPUT);
  pinMode(pinLY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  digitalWrite(pinLR, LOW);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLG, LOW);
  digitalWrite(pinLY, LOW);
  
  //// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //// Print a message to the LCD.
  lcd.print("SIMON GAME");
}

void loop()
{
  if (level == 1){
    generate_sequence();//generate a sequence;
  }
  if (digitalRead(pinBMENU) == HIGH || level != 1){ //If start button is pressed or you're winning
    lcd.noDisplay();
    show_sequence();    //show the sequence
    get_sequence();     //wait for your sequence
  }
}

void show_sequence()
{
  digitalWrite(pinLR, LOW);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLG, LOW);
  digitalWrite(pinLY, LOW);
  
  for (int i = 0; i < level; i++){
    if(error_spot==i){
        beeplong = 640;
    }
    digitalWrite(sequence[i], HIGH);
    if (sequence[i]==pinLR){
      for(int k=0;k<beeplong;k++){
        digitalWrite(BUZZER,HIGH);
        delay(1);//wait for 1ms
        digitalWrite(BUZZER,LOW);
        delay(1);//wait for 1ms
      }
    }
    if (sequence[i]==pinLB){
      for(int k=0;k<beeplong/2;k++){
        digitalWrite(BUZZER,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(BUZZER,LOW);
        delay(2);//wait for 2ms
      }
    }
    if (sequence[i]==pinLG){
      for(int k=0;k<beeplong/3;k++){
        digitalWrite(BUZZER,HIGH);
        delay(3);//wait for 3ms
        digitalWrite(BUZZER,LOW);
        delay(3);//wait for 3ms
      }
    }
    if (sequence[i]==pinLY){
      for(int k=0;k<beeplong/4;k++){
        digitalWrite(BUZZER,HIGH);
        delay(4);//wait for 4ms
        digitalWrite(BUZZER,LOW);
        delay(4);//wait for 4ms
      }
    }
    delay(velocity);
    digitalWrite(sequence[i], LOW);
    delay(200);
    beeplong = 160;
  }
}

void get_sequence()
{
  int flag = 0; //this flag indicates if the sequence is correct
  
  for (int i = 0; i < level; i++){
    flag = 0;
    while(flag == 0){
      if (digitalRead(pinBR) == HIGH){
        digitalWrite(pinLR, HIGH);
        for(int k=0;k<beeplong;k++){
          digitalWrite(BUZZER,HIGH);
          delay(1);//wait for 1ms
          digitalWrite(BUZZER,LOW);
          delay(1);//wait for 1ms
        }
        your_sequence[i] = pinLR;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
            error_spot = i;
            wrong_sequence();
            return;
        }
        digitalWrite(pinLR, LOW);
      }
    
      if (digitalRead(pinBB) == HIGH){
        digitalWrite(pinLB, HIGH);
        for(int k=0;k<beeplong/2;k++){
          digitalWrite(BUZZER,HIGH);
          delay(2);//wait for 1ms
          digitalWrite(BUZZER,LOW);
          delay(2);//wait for 1ms
        }
        your_sequence[i] = pinLB;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
          error_spot = i;
          wrong_sequence();
          return;
        }
        digitalWrite(pinLB, LOW);
      }
    
      if (digitalRead(pinBG) == HIGH){
        digitalWrite(pinLG, HIGH);
        your_sequence[i] = pinLG;
        for(int k=0;k<beeplong/3;k++){
          digitalWrite(BUZZER,HIGH);
          delay(3);//wait for 1ms
          digitalWrite(BUZZER,LOW);
          delay(3);//wait for 1ms
        }
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
          error_spot = i;
          wrong_sequence();
          return;
        }
        digitalWrite(pinLG, LOW);
      }
    
      if (digitalRead(pinBY) == HIGH){
        digitalWrite(pinLY, HIGH);
        your_sequence[i] = pinLY;
        for(int k=0;k<beeplong/4;k++){
          digitalWrite(BUZZER,HIGH);
          delay(4);//wait for 1ms
          digitalWrite(BUZZER,LOW);
          delay(4);//wait for 1ms
        }
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
          error_spot = i;
          wrong_sequence();
          return;
        }
        digitalWrite(pinLY, LOW);
      }
    }
  }
  right_sequence();
}

void generate_sequence()
{
  randomSeed(millis()); //in this way is really random!!!
  
  for (int i = 0; i < MAX_LEVEL; i++){
    sequence[i] = random(6,10);
  }
}

void wrong_sequence()
{
  for (int i = 0; i < 3; i++){
    digitalWrite(pinLR, HIGH);
    digitalWrite(pinLB, HIGH);
    digitalWrite(pinLG, HIGH);
    digitalWrite(pinLY, HIGH);
    for(int k=0;k<15;k++){
      digitalWrite(BUZZER,HIGH);
      delay(5);//wait for 1ms
      digitalWrite(BUZZER,LOW);
      delay(5);//wait for 1ms
    }
    delay(250);
    digitalWrite(pinLR, LOW);
    digitalWrite(pinLB, LOW);
    digitalWrite(pinLG, LOW);
    digitalWrite(pinLY, LOW);
    delay(250);
  }
  //show_sequence();
  level = 1;
  velocity = 500;
  error_spot=-1;
}

void right_sequence()
{
  digitalWrite(pinLR, LOW);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLG, LOW);
  digitalWrite(pinLY, LOW);
  delay(250);
  
  digitalWrite(pinLR, HIGH);
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinLG, HIGH);
  digitalWrite(pinLY, HIGH);
  
  for(int k=1;k<1000;k++){
    digitalWrite(BUZZER,HIGH);
    delay(0.5);//wait for 0.5ms
    digitalWrite(BUZZER,LOW);
    delay(0.5);//wait for 0.5ms
  }
  delay(500);
  
  digitalWrite(pinLR, LOW);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLG, LOW);
  digitalWrite(pinLY, LOW);
  delay(500);
  
  if (level < MAX_LEVEL);{
    level++;
  }
}
