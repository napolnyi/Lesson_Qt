#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scene = new QGraphicsScene(this);
    setScene(scene);
    setSceneRect(0,0,900,900);
    bscheme.append(new BlockScheme(this, 0, 100, 100));
    scene->addItem(bscheme.back());
}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton){
        int geometry = bscheme.length() % 3;
        bscheme.append(new BlockScheme(this, geometry, event->x(), event->y()));
        scene->addItem(bscheme.back());
        item = itemAt(event->x(), event->y());
    }
    if (event->button() == Qt::RightButton){
        QGraphicsItem *item = itemAt(event->x(), event->y());
        if (item != nullptr) {
            scene->removeItem(item);
            int index = bscheme.indexOf(dynamic_cast<BlockScheme*>(item));
            bscheme.remove(index);
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (item != nullptr) {

        item->setPos(mapFromScene(event->x(), event->y()));
    }
    else Q_UNUSED(event);

}






