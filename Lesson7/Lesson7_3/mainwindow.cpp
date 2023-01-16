#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scene = new QGraphicsScene(this);
    setScene(scene);
    bscheme.append(new BlockScheme(this,0));
    scene->addItem(bscheme.back());

    connect(bscheme.back(), SIGNAL(reDraw()), this, SLOT(reDraw()));
    connect(bscheme.back(), SIGNAL(Draw()), this, SLOT(Draw()));


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

void MainWindow::Draw()
{
    bscheme.append(new BlockScheme(this,0));
    scene->addItem(bscheme.back());
    connect(bscheme.back(), SIGNAL(Draw()), this, SLOT(Draw()));

    scene->update();
    qDebug()<<bscheme.length();
    qDebug()<<sender();
    //update();
}

