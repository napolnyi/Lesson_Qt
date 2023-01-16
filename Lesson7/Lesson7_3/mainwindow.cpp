#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scene = new QGraphicsScene(this);
    setScene(scene);
    bscheme.append(new BlockScheme(this, 0, 0, 0));
    scene->addItem(bscheme.back());
    connect(bscheme.back(), SIGNAL(Draw(int,int)), this, SLOT(Draw(int,int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::reDraw()
{
    scene->update();
    update();
}

void MainWindow::randomColor()
{
    bscheme.back()->setBrush(QBrush(QColor(rand()%256,rand()%256,rand()%256)));
}

void MainWindow::Draw(int x,int y)
{
    qDebug()<<"Draw";
    qDebug()<<"x_Draw"<<x;
    qDebug()<<"y_Draw"<<y;
    int geo = (bscheme.length()-1) % 3;
    bscheme.append(new BlockScheme(this,geo,x,y));

    scene->addItem(bscheme.back());
    connect(bscheme.back(), SIGNAL(Draw(int,int)), this, SLOT(Draw(int,int)));

    scene->update();

    qDebug()<<sender();
    //update();
}

