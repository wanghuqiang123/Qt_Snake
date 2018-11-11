#include "mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    snake(1);
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

    setMinimumSize(800,600);

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
        ret = ret && makeShortCut(short_cut,this,Qt::Key_Right);
        if(ret)
        {
            connect(short_cut,SIGNAL(activated()),this,SLOT(Move_Right()));
            shortcuts.push_back(short_cut);
        }

        ret = ret && makeShortCut(short_cut,this,Qt::Key_Left);
        if(ret)
        {
            connect(short_cut,SIGNAL(activated()),this,SLOT(Move_Left()));
            shortcuts.push_back(short_cut);
        }

        ret = ret && makeShortCut(short_cut,this,Qt::Key_Up);
        if(ret)
        {
            connect(short_cut,SIGNAL(activated()),this,SLOT(Move_Up()));
            shortcuts.push_back(short_cut);
        }

        ret = ret && makeShortCut(short_cut,this,Qt::Key_Down);
        if(ret)
        {
            connect(short_cut,SIGNAL(activated()),this,SLOT(Move_Down()));
            shortcuts.push_back(short_cut);
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

bool MainWindow::makeShortCut(QShortcut*& Short_cut,QWidget* parent, int key)
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
    for(auto iter = shortcuts.begin();shortcuts.size()>0;)
    {
        iter = shortcuts.erase(iter);
    }
}
