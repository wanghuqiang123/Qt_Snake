#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QMenuBar>
#include <QImage>
#include <QAction>
#include <QList>
#include <QShortcut>

#include "snake.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Snake  snake;
    QTimer m_timer;
    QList<QShortcut *>shortcuts;

    MainWindow(QWidget *parent = 0);

    int showGameOverMessage();
    bool construct();
    bool initMenuBar();
    bool initOptionMenu(QMenuBar*);
    bool initGame();
    bool initGame_key();
    bool makeAction(QAction*& action,QWidget* parent, QString text);
    bool makeShortCut(QShortcut*& Short_cut,QWidget* parent, int key);
    //rewrite event ;
    void paintEvent(QPaintEvent *event);
public:
    static MainWindow* NewInstance();
    ~MainWindow();
private slots:
    void BeginGame();
    void StopGame();
    void Timer_Timeout();

    void Move_Up();
    void Move_Down();
    void Move_Left();
    void Move_Right();
};

#endif // MAINWINDOW_H
