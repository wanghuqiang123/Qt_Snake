#include "food.h"

Food::Food()
{
     this->pos.x = qrand()%800;
     this->pos.y = qrand()%570+30;
}

void Food::resetPos()
{
    this->pos.x = qrand()%800;
    this->pos.y = qrand()%570+30;
}

void Food::DrawFood(QPainter& painter)
{
    painter.fillRect(this->pos.x,this->pos.y,10,10,Qt::green);
}

int Food::GetX()
{
    return this->pos.x;
}

int Food::GetY()
{
    return this->pos.y;
}
