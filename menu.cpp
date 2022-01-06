
#include "menu.h"
#include <iostream>
using namespace std;

menu::menu() {
    //Empty builder, prints the board for the first time
    hex.printHex();
    player='B';
    counter=0;
}

void menu::Play() {
    string s;
    //A function that manages the game
    while (true){
        cout<<player;
        cout<<':';
        cin>>s;
        cout<<'\n';
        if (s!="QUIT"){
                int i=s[0]-'@';
                int j=s[1]-'0';
                if(s[2]){
                    j=j*10+s[2]-'0';
                }
                if(i<0 || i>11 || j<0 ||j>11) {
                    //Checks if it's a cell in the game
                    cerr<<"Invalid move; the game awaits a valid move.\n";
                    continue;
                }
                //Checks if this move is against the law Game (Checks if this cell has been painted)
                if(hex.getData(j-1,i-1)!='O'){
                    cerr<<"Invalid move; the game awaits a valid move.\n";
                    continue;
                }
                hex.setData(j-1,i-1,player);
                hex.printHex();
                //After each move a check is made to see if he has won
                if(this->checkWin()){
                    cout<<player;
                    cout<<" wins the game."<<endl;
                    break;
                }
                //Changing the player
                if(player=='B'){
                    player='R';
                } else{
                    player='B';
                }
            continue;
    }
        //A player decided to retire, end of game
        cout<<player;
        cout<<": QUIT\n";
        hex.printHex();
        if(player=='B'){
            player='R';
        } else{
            player='B';
        }
        cout<<player;
        cout<<" wins the game."<<endl;
        break;
    }
}


bool menu::checkWin() {
    //The function checks if there is a win in the game
    if (player == 'R') {
        for (int j = 0; j < 11; j++) {
            if (hex.getData(0, j) == player) {
                hex.changeVisitTrue(0,j);
                if (checkWinRed(0, j) == 0) {
                    for (int s=0;s<11;s++){
                        for (int f=0;f<11;f++){
                            hex.changeVisitFalse(s,f);
                        }
                    }
                    return false;
                } else return true;
            } else continue;
        }
    } else
        for (int i = 0; i < 11; i++) {
            if (hex.getData(i, 0) == player) {
                hex.changeVisitTrue(i,0);
                if (checkWinBlue(0, 0) == 0) {
                    for (int s=0;s<11;s++){
                        for (int f=0;f<11;f++){
                            hex.changeVisitFalse(s,f);
                        }
                    }
                    return false;
                } else return true;
            } else continue;
        }
    return false;
}

int menu::checkWinRed(int i, int j) {
    //The function checks if Red is a win in the game
    if(i==10 && hex.getData(i,j)==player){
        counter=1;
    }
    if((j-1)>0 && (j-1)<11 && hex.getData(i,j-1)==player && !hex.isVisit(i, j - 1)){
            hex.changeVisitTrue(i,j-1);
            checkWinRed(i,j-1);
    }
    if((j+1)>0 && (j+1)<11 && hex.getData(i,j+1)==player && !hex.isVisit(i,j+1)){
            hex.changeVisitTrue(i,j+1);
            checkWinRed(i,j+1);
    }

    if((i-1)>0 && (i-1)<11 && hex.getData(i-1,j)==player && !hex.isVisit(i-1,j)){
            hex.changeVisitTrue(i-1,j);
            checkWinRed(i-1,j);
    }

    if((j+1)>0 && (j+1)<11 && (i-1)>0 && (i-1)<11 && hex.getData(i-1,j+1)==player && !hex.isVisit(i-1,j+1)){
            hex.changeVisitTrue(i-1,j+1);
            checkWinRed(i-1,j+1);
    }

    if((j-1)>0 && (j-1)<11 && (i+2)>0 && (i+2)<11 && hex.getData(i+2,j-1)==player && !hex.isVisit(i+2,j-1)){
            hex.changeVisitTrue(i+2,j-1);
            checkWinRed(i+2,j-1);
    }

    if( (i+2)>0 && (i+2)<11 && hex.getData(i+2,j)==player && !hex.isVisit(i+2,j)){
            hex.changeVisitTrue(i+2,j);
            checkWinRed(i+2,j);
    }

    else{
        return counter;
    }
    return counter;
}

int menu::checkWinBlue(int i, int j) {
    //The function checks if Blue is a win in the game
    if(j==10 && hex.getData(i,j)==player){
        counter=1;
    }
    if((j-1)>0 && (j-1)<11 && hex.getData(i,j-1)==player && !hex.isVisit(i,j-1) ){
        hex.changeVisitTrue(i,j-1);
        checkWinBlue(i,j-1);
    }
    if((j+1)>0 && (j+1)<11 && hex.getData(i,j+1)==player && !hex.isVisit(i,j+1)){
        hex.changeVisitTrue(i,j+1);
        checkWinBlue(i,j+1);
    }

    if((i-1)>0 && (i-1)<11 && hex.getData(i-1,j)==player && !hex.isVisit(i-1,j)){
        hex.changeVisitTrue(i-1,j);
        checkWinBlue(i-1,j);
    }

    if((j+1)>0 && (j+1)<11 && (i-1)>0 && (i-1)<11 && hex.getData(i-1,j+1)==player && !hex.isVisit(i-1,j+1)){
        hex.changeVisitTrue(i-1,j+1);
        checkWinBlue(i-1,j+1);
    }

    if((j-1)>0 && (j-1)<11 && (i+2)>0 && (i+2)<11 && hex.getData(i+2,j-1)==player && !hex.isVisit(i+2,j-1)){
        hex.changeVisitTrue(i+2,j-1);
        checkWinBlue(i+2,j-1);
    }

    if( (i+2)>0 && (i+2)<11 && hex.getData(i+2,j)==player && !hex.isVisit(i+2,j)){
        hex.changeVisitTrue(i+2,j);
        checkWinBlue(i+2,j);
    }

    else{
        return counter;
    }
    return counter;
}

