
#include "Hex.h"
#include <iostream>
using namespace std;

Hex::Hex() {
    //Creating an empty matrix
    board=new Hexagon *[11];
    for(int i=0;i<11;i++){
        board[i]=new Hexagon[11];
        for (int j=0;j<11;j++){
            board[i][j]=Hexagon();
        }
    }
}

void Hex::setData(int i, int j, char c) {
    //Change the cell in the array (hexagon in the game) to the user's color
  board[i][j].setData(c);
}

Hex::~Hex() {
    //Destructor
    for (int i=0;i<11;i++){
        delete []board[i];
    }
    delete[]board;
}

void Hex::printHex() const {
    //Printing the game board in the shape of a rhombus
    for(int i=0;i<11;i++){
        int t=i;
        while (t!=0){
            cout<<' ';
            t--;
        }
        for(int j=0;j<11;j++){
            cout<<board[i][j].getData();
            if (j!=10){
                cout<<' ';
            }
        }
            cout<<'\n';
    }
}

char Hex::getData(int i, int j) const {
    //The function returns the color of a cell in an array (hexagon in the game)
    return board[i][j].getData();
}

bool Hex::isVisit(int i, int j) {
    return board[i][j].isVisit();
}

void Hex::changeVisitTrue(int i, int j) {
    return board[i][j].changeVisitTrue();
}

void Hex::changeVisitFalse(int i, int j) {
    return board[i][j].changeVisitFalse();
}


