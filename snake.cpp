#include "snake.h"

Snake::Snake()
{
    length = 1;
    body.push_back(Coor(0,INITHEGHT));
    Dir = -1;
}

Snake::Snake(int len)
{
    length = len;
    int x = 0;

    body.resize(len);   //reisze body vector size;

    for(int i = len-1 ;i>=0;i--)
    {
        body[i].x = x;
        body[i].y = INITHEGHT;
        x += SNAKERECT;
    }

    Dir = -1;
}

/*Snake::Snake(const Snake& rh)
{
    this->length = rh.length;
    this->Dir = rh.Dir;
    this->body = rh.body;

}*/

Snake& Snake::operator = (const Snake& rh)
{
    this->length = rh.length;
    this->Dir = rh.Dir;
    this->body = rh.body;
    return *this;
}

Snake& Snake::operator () (int len)
{
    this->length = len;
    int x = 0;

    this->body.resize(len);   //reisze body vector size;

    for(int i = len-1 ;i>=0;i--)
    {
        this->body[i].x = x;
        this->body[i].y = INITHEGHT;
        x += SNAKERECT;
    }

    this->Dir = -1;

    return *this;
}

void Snake::DrawSnake(QPainter &painter)
{
    for(int i = 0;i<body.size();i++)
    {
        painter.fillRect(body[i].x,body[i].y,SNAKERECT,SNAKERECT,Qt::red);    
    }

    food.DrawFood(painter);
}

void Snake::moveSnake()
{
    for(int i = body.size()-1;i>0;i--)
    {
        body[i].x = body[i-1].x;
        body[i].y = body[i-1].y;
    }

    switch (Dir)
    {
    case up:
        body[0].y -= STEP;
        break;
    case left:
        body[0].x -= STEP;
        break;
    case right:
        body[0].x += STEP;
        break;
    case down:
        body[0].y += STEP;
        break;
    default:
        break;
    }

    if(EatFood())
    {
        food.resetPos();  //重置食物点
        SnakeBodyIncrease();
    }
}

bool Snake::EatFood()
{
    bool ret = false;
    int x = food.GetX();
    int y = food.GetY();

    if((body[0].x >= x-8) && (body[0].x <= x+10)&&(body[0].y >= y-8)&&(body[0].y <= y+10))  //判断蛇头与食物是否重合
    {
        ret = true;
    }

    return ret;
}

bool Snake::EatBody()
{
    bool ret = false;
    int n = body.size();
    for(int i = 3;i<n;i++)
    {
        if((body[0].x >= (body[i].x-5)) && (body[0].x <= (body[i].x+5))&&(body[0].y >= (body[i].y-5))&&(body[0].y <=(body[i].y+5)))
            ret = true;
    }
    return ret;
}

void Snake::SnakeBodyIncrease()
{
    int i = body.size()-1;
    body.push_back(Coor(body[i].x,body[i].y));
}







