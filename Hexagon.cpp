

#include "Hexagon.h"

Hexagon::Hexagon() {
    data='O';
    visit= false;
}

void Hexagon::setData(char c) {
    data=c;
}

bool Hexagon::isVisit() const {
    if(visit){
        return true;
    }
    else return false;
}

void Hexagon::changeVisitTrue() {
    visit= true;
}

void Hexagon::changeVisitFalse() {
    visit= false;

}

char Hexagon::getData() const {
    return data;
}
