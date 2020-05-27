#include <Arduino.h> 
#include "MySensors.h"


Sensors::Sensors(int pin) {
  pinMode(pin,INPUT);
  nbSensors ++;
}

void Sensors::WhoAmI() {
  Serial.print("Je suis un capteur de nature inconnue");
}

int Sensors::GetState() {
//  return digitalRead(pin); 
}

int Sensors::nbSensors = 0;

//----------------pushbutton--------------------

//constructor
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int mypin):Sensors(mypin) {
  pin=mypin;  
}


void ExternalDigitalSensorButton::WhoAmI(){
  Serial.print("Je suis un bouton poussoir");
}

int ExternalDigitalSensorButton::GetState(){
  return digitalRead(pin);
}
