#ifndef FOOD_H
#define FOOD_H

#include <QPainter>
#include <QTime>

class Food
{
public:
    Food();

    void DrawFood(QPainter&);
    int GetX();
    int GetY();
    void resetPos();
private:

    struct Pos
    {
        int x;
        int y;
    }pos;



};

#endif // FOOD_H
