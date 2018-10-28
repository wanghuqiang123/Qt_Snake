#include "mainwindow.h"
#include <QPainter>

void MainWindow::BeginGame()
{
     m_timer.start(150);        //timer begin running
}

void MainWindow::StopGame()
{
    m_timer.stop();
}

void MainWindow::Timer_Timeout()
{
     update();      //refresh window,call painevent() every
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(m_timer.isActive())   //check time is run ? if running , this is true
    {
        QPainter painter(this);

        painter.fillRect(0,0,this->width(),this->height(),Qt::black);

        if(snake.Dir != -1)
        {
            step += 5;
            painter.fillRect(snake.body[0].x + step,snake.body[0].y,10,10,Qt::red);
        }
        else
        {
            painter.fillRect(snake.body[0].x,snake.body[0].y,10,10,Qt::red);
        }
    }
}
void MainWindow::Move_Up()
{

}
void MainWindow::Move_Down()
{

}
void MainWindow::Move_Left()
{
    snake.Dir = Snake::left;
}
void MainWindow::Move_Right()
{

}
