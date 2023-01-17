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
    bscheme.back()->setAcceptHoverEvents(true);
    connect(bscheme.back(), SIGNAL(Draw(int,int)), this, SLOT(Draw(int,int)));
    //connect(bscheme.back(), SIGNAL(deleteItem(BlockScheme*)), this, SLOT(deleteItem(BlockScheme*)));
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
    int geo = bscheme.length() % 3;
    bscheme.append(new BlockScheme(this,geo,x,y));

    scene->addItem(bscheme.back());
    bscheme.back()->setAcceptHoverEvents(true);
    connect(bscheme.back(), SIGNAL(Draw(int,int)), this, SLOT(Draw(int,int)));
    //connect(bscheme.back(), SIGNAL(deleteItem(BlockScheme*)), this, SLOT(deleteItem(BlockScheme*)));

    scene->update();

    qDebug()<<sender();
    update();
}

void MainWindow::deleteItem(BlockScheme* item)
{
    if (!bscheme.isEmpty()){

        int index = bscheme.indexOf(item);
        qDebug()<<"deleteItem"<<index;
        scene->removeItem(item);
        bscheme.remove(index);
        scene->update();
    }
}

