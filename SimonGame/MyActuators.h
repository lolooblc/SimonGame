#ifndef MYACTUATORS_H_
#define MYACTUATORS_H_

#include "Devices.h"

class Actuators : public Devices {
  protected:
    int pin;
    static int nbActuators;
  public:
    Actuators(int pin);
    virtual void WhoAmI();
    virtual void Write(int HoL); //in argument : HIGH or LOW, means 1 or 0
};


//----------class for LEDs------------------

class DigitalActuatorLED : public Actuators{
  public:
    DigitalActuatorLED(int pin);
    virtual void WhoAmI();
    virtual void Write(int HoL);
};

//----------class for buzzers------------------

class DigitalActuatorBuzzer : public Actuators{
  protected :
    double delay_value;
    //durée pendant laquelle le buzzer vibrera (en nb d'itérations)
    int beeplong;
   public:
    DigitalActuatorBuzzer(int pin, double delay_value);
    virtual void WhoAmI();
    virtual void Write(int HoL); //useful only for tests
    void ring();
};



#endif
