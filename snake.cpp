#include "snake.h"

Snake::Snake()
{
    length = 1;
    body.push_back(Coor(0,0));
    Dir = -1;
}

Snake::Snake(int len)
{
    length = len;
    int x = 0,y = 0;

    body.resize(len);   //reisze body vector size;

    for(int i = len-1 ;i>=0;i--)
    {
        body[i].x = x;
        body[i].y = y;
        x += SIZE;
        y += SIZE;
    }

    Dir = -1;
}
