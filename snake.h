#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>
#define SIZE 10

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

    };
    QVector<Coor> body;
    int Dir;

    Snake();
    Snake(int len);

    void moveSnake();
private:
    int length;

};

#endif // SNAKE_H
