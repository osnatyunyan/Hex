
#ifndef HW2_HEXAGON_H
#define HW2_HEXAGON_H
class Hexagon{
public:
    Hexagon();
    void setData(char c);
    char getData() const;
    bool isVisit() const;
    void changeVisitTrue();
    void changeVisitFalse();

private:
    char data;
    bool visit;
};

#endif //HW2_HEXAGON_H
