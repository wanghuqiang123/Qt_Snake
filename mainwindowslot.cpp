#include "mainwindow.h"
#include <QMessageBox>

int MainWindow::showGameOverMessage()
{
    QMessageBox msg(this);

    msg.setWindowTitle("Dialog");
    msg.setText("Game Over!");
    msg.setIcon(QMessageBox::Critical);
    msg.setStandardButtons(QMessageBox::Ok);
    return msg.exec();
}
void MainWindow::BeginGame()
{

     m_timer.start(50);        //timer begin running
     qsrand(QTime::currentTime().second() * 1000 + QTime::currentTime().msec());
}

void MainWindow::StopGame()
{
    m_timer.stop();
}

void MainWindow::Timer_Timeout()
{
     repaint();      //refresh window,call painevent() every
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(m_timer.isActive())   //check time is run ? if running , this is true
    {
        QPainter painter(this);

        painter.fillRect(0,this->menuBar()->height(),this->width(),this->height(),Qt::black);

        if(snake.Dir != -1)
        {
            snake.moveSnake();      //改变蛇的方向
            snake.DrawSnake(painter);   //draw snake on screen;
            if(snake.EatBody())
            {
                StopGame();
                showGameOverMessage();  //若吃的到自己，则弹出对话框说游戏终止；///重新开始后，其他还未初始化；
            }
        }
        else
        {
            snake.DrawSnake(painter);
        }
    }
}

void MainWindow::Move_Up()
{
    if(snake.Dir != Snake::down)
        snake.Dir = Snake::up;
}
void MainWindow::Move_Down()
{
    if(snake.Dir != Snake::up)
        snake.Dir = Snake::down;
}
void MainWindow::Move_Left()
{
    if(snake.Dir != Snake::right)
        snake.Dir = Snake::left;
}
void MainWindow::Move_Right()
{
    if(snake.Dir != Snake::left)
        snake.Dir = Snake::right;
}
