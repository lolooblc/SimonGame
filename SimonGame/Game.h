#ifndef GAME_H_
#define GAME_H_

#include "MySensors.h"
#include "MyActuators.h"
#include "LCDscreen.h"

#define pinBR A0
#define pinBB A1
#define pinBG A2
#define pinBY A3
#define pinBMENU A4
#define pinLR 6
#define pinLB 7
#define pinLG 8
#define pinLY 9
#define pinBuzzer 10

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

class Game {
  protected:
    int velocity;
    int error_spot;
    static const int MAX_LEVEL;
    int level;
  public:
    Game();  
    int * generate_sequence();
    void wrong_sequence();
    void right_sequence();
    void show_sequence(int *sequence);
    void get_sequence(int *sequence);
    int choose_nb_of_players();
    int GetLevel();
    void test_boutons();
};





#endif
