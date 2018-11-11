#ifndef SNAKE_H
#define SNAKE_H

#include <QVector>
#include <QPainter>
#include "food.h"

#define STEP 5
#define INITHEGHT 35
#define SNAKERECT 10

class Snake
{
public:
    enum Direction{up,down,left,right};
    struct Coor
    {
        int x;
        int y;
        Coor(int X,int Y)
        {
            x = X;
            y = Y;
        }
        Coor()
        {
            x = 0;
            y = 0;
        }

        Coor(const Coor& rh)
        {
            x = rh.x;
            y = rh.y;
        }

        Coor& operator =(const Coor& rh)
        {
            x = rh.x;
            y = rh.y;

            return *this;
        }
    };


    QVector<Coor> body;
    int Dir;

    Snake();
    Snake(int len);
    //Snake(const Snake& rh);
    Snake& operator = (const Snake& rh);   //35法则
    Snake& operator () (int len);

    void moveSnake();
    bool EatFood();
    bool EatBody();
    void DrawSnake(QPainter& painter);
    void SnakeBodyIncrease();
private:
    int length;
    Food food;

};

#endif // SNAKE_H
