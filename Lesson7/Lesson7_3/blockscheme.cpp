#include "blockscheme.h"
#include <QDebug>
#include <QApplication>
#include "mainwindow.h"

BlockScheme::BlockScheme(QObject *parent,int geo) : QObject(parent)
{
    geometry = static_cast<Geometry>(geo);
    x = 0;
    y = 0;
    brush.setColor(QColor(rand()%255, rand()%255, rand()%255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    moving = false;
    setPos(0,0);
    countClick = 0;
}

void BlockScheme::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
    if (geometry == Geometry::ELLIPS) painter->drawEllipse(x, y, 200, 100);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

QRectF BlockScheme::boundingRect() const
{

    return QRectF(x-800, y-800, 1600, 1600);

}

void BlockScheme::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    countClick++;
    qDebug()<<"mousePressEvent";
    if(event->button() == Qt::LeftButton){
        moving = true;
        bpoint = event->pos().toPoint();
    }

    if (countClick == 1) geometry = Geometry::RECTANGLE;
    else if (countClick == 2) {
        geometry = Geometry::ELLIPS;
        countClick = 0;
    }

}

void BlockScheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"mouseReleaseEvent";

    if(event->button() == Qt::LeftButton){
        moving = false;
        x = bpoint.x();
        y = bpoint.y();
        //emit reDraw();
        emit Draw();
    }
}
