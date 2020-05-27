#ifndef LCDSCREEN_H_
#define LCDSCREEN_H_

#include "Devices.h"
#include <LiquidCrystal.h>

class LCDscreen : public Devices, public LiquidCrystal {
  //protected:
    //const int pin_rs, pin_en, pin_d4, pin_d5, pin_d6, pin_d7;
    //const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  public:
  LCDscreen(const int mypin_rs, const int mypin_en, const int mypin_d4, const int mypin_d5, const int mypin_d6, const int mypin_d7);
  virtual void WhoAmI();
  void Display(char text[]); 
  void CleanScreen(); 
};


#endif
