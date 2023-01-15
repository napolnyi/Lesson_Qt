#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scene = new QGraphicsScene(this);
    setScene(scene);
    bscheme = new BlockScheme(this);
    scene->addItem(bscheme);

    connect(bscheme, SIGNAL(reDraw()), this, SLOT(reDraw()));
    connect(bscheme, SIGNAL(Draw()), this, SLOT(Draw()));


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
    bscheme->setBrush(QBrush(QColor(rand()%256,rand()%256,rand()%256)));

}

void MainWindow::Draw()
{
    bscheme2 = new BlockScheme(this);
    scene->addItem(bscheme2);
    scene->update();
}

