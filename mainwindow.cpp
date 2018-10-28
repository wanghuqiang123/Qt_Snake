#include "mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
}

MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret = NULL;

    ret = new MainWindow();

    if((ret == NULL) || !ret->construct())
    {
        delete ret;
        ret = NULL;
    }
    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;

    setMinimumSize(800,500);

    ret = ret && initMenuBar();
    ret = ret && initGame();

    return ret;
}

bool MainWindow::initMenuBar()
{
    bool ret = true;

    QMenuBar* MenuBar = menuBar();

    ret = ret && initOptionMenu(MenuBar);

    return ret;
}

bool MainWindow::initGame_key()
{
    bool ret = true;

    QShortcut* short_cut = NULL;

    if(ret)
    {
        ret = ret && makeAction(short_cut,this,Qt::Key_Right);
        if(ret)
        {
            connect(short_cut,SIGNAL(activated()),this,SLOT(Move_Left()));
        }
    }

    return ret;
}

bool MainWindow::initGame()
{
    bool ret = true;

    ret = ret && initGame_key();

    if(ret)
    {
        m_timer.setParent(this);        //set this timer parent class is this mainwindow;
        connect(&m_timer,SIGNAL(timeout()),this,SLOT(Timer_Timeout()));
    }
    return ret;
}

bool MainWindow::initOptionMenu(QMenuBar* MenuBar)
{
    bool ret = true;

    QMenu* menu = new QMenu("Select",MenuBar);
    if(menu == NULL)
    {
        ret = false;
    }

    if(ret)
    {
        QAction* action = NULL;

        ret = ret && makeAction(action,menu,"Star Game");
        if(ret)
        {
            menu->addAction(action);
            connect(action,SIGNAL(triggered(bool)),this,SLOT(BeginGame()));
        }

        ret = ret && makeAction(action,menu,"Stop Game");
        if(ret)
        {
            menu->addAction(action);
            connect(action,SIGNAL(triggered(bool)),this,SLOT(StopGame()));
        }

    }
    if(ret)
    {
        MenuBar->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}



bool MainWindow::makeAction(QAction*& action,QWidget* parent, QString text)
{
    bool ret = true;

    action = new QAction(text, parent);

    if( action == NULL )
    {
        ret = false;
    }

    return ret;
}

bool MainWindow::makeAction(QShortcut*& Short_cut,QWidget* parent, int key)
{
    bool ret = true;

    Short_cut = new QShortcut(parent);

    if(Short_cut != NULL)
    {
        Short_cut->setKey(QKeySequence(key));
    }
    else
    {
        ret = false;
    }

    return ret;
}

MainWindow::~MainWindow()
{

}
