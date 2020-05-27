#include <Arduino.h> 
#include "MyActuators.h"


Actuators::Actuators(int mypin) {
  pin = mypin;
  pinMode(mypin,OUTPUT);
  nbActuators ++;
}

void Actuators::WhoAmI() {
  Serial.print("Je suis un actionneur de nature inconnue");
}

void Actuators::Write(int HoL) {
  digitalWrite(pin,HoL);
}

int Actuators::nbActuators = 0;

//------------------LEDs---------------------

DigitalActuatorLED::DigitalActuatorLED(int pin):Actuators(pin){
  //do nothing else
}

void DigitalActuatorLED::WhoAmI(){
  Serial.print("Je suis une LED");
}

void DigitalActuatorLED::Write(int HoL){
  digitalWrite(pin,HoL);
}


//------------------Buzzer---------------------

DigitalActuatorBuzzer::DigitalActuatorBuzzer(int pin, double delay_wanted):Actuators(pin){
  delay_value = delay_wanted;
  beeplong = 160;
}

void DigitalActuatorBuzzer::WhoAmI(){
    Serial.print("Je suis un buzzer");
}

void DigitalActuatorBuzzer::Write(int HoL){
  digitalWrite(pin,HoL);
}

void DigitalActuatorBuzzer::ring(){
  for(int k=0;k<(int)(beeplong/delay_value);k++){
    digitalWrite(pin,HIGH);
    delay(delay_value);//wait for <delay_value> ms
    digitalWrite(pin,LOW);
    delay(delay_value);
  }
}
