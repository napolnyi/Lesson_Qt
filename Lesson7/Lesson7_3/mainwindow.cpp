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
        if (item != nullptr) {
            x = event->x();
            y = event->y();
            qDebug()<<"mousePressEvent x"<<x;
        }

        moving = true;

    }
    if (event->button() == Qt::RightButton){
        QGraphicsItem *item = itemAt(event->x(), event->y());
        if (item != nullptr) {
            scene->removeItem(item);
            bscheme.pop_back();
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    if(moving){
        qDebug()<<"x"<<x;
        qDebug()<<"event->x()"<<event->x();
        qDebug()<<"x = x - event->x();"<< x - event->x();
        x = x - event->x();
        y = y - event->y();
        qDebug()<<x;
        //item->moveBy(x,y);

            //item->setPos(x,y);
           //update();
        }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    moving = false;
    Q_UNUSED(event);
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

        scene->update();
    }
}

