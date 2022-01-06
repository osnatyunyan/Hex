
#ifndef HW2_MENU_H
#define HW2_MENU_H
#include "Hex.h"

class menu{
        //Game Management Class
public:
    menu();
    bool checkWin();
    int checkWinRed(int i, int j);
    int checkWinBlue(int i, int j);
    void Play();

private:
    char player;
    Hex hex;
    int counter;
};

#endif
