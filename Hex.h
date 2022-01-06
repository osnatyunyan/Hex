
#ifndef HW2_HEX_H
#define HW2_HEX_H
#include "Hexagon.h"

class Hex{
    //A matrix that describes the game board
public:
    Hex();
    void setData(int i, int j, char c);
    char getData(int i,int j) const;
    bool isVisit(int i, int j);
    void changeVisitTrue(int i, int j);
    void changeVisitFalse(int i, int j);
     ~Hex();
    void printHex() const;

private:
    Hexagon** board;
};

#endif
