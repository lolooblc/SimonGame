#include <Arduino.h> 
#include "Devices.h"

Devices::Devices(){
	nbDevices++;
}

void Devices::WhoAmI(){
	Serial.print("Je suis un composant de nature inconnue");
}

int Devices::nbDevices = 0;
