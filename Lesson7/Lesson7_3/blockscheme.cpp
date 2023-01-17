#include "blockscheme.h"
#include <QDebug>
#include "mainwindow.h"

BlockScheme::BlockScheme(QObject *parent,int geo, int xBefor, int yBefor) : QObject(parent)
{
    geometry = static_cast<Geometry>(geo);
    x = xBefor;
    y = yBefor;
    brush.setColor(QColor(rand()%255, rand()%255, rand()%255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    moving = false;
}

void BlockScheme::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
    if (geometry == Geometry::ELLIPS) painter->drawEllipse(x, y, 200, 100);
    QPointF starPoints [10] = {QPointF(x+75,y), QPointF(x+100,y+45), QPointF(x+150,y+55), QPointF(x+115,y+90),
                               QPointF(x+125,y+140), QPointF(x+75,y+120), QPointF(x+25,y+140), QPointF(x+35,y+90),
                               QPointF(x,y+55), QPointF(x+50,y+45)
                               };
    if (geometry == Geometry::STAR) painter->drawPolygon(starPoints,10);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

QRectF BlockScheme::boundingRect() const
{

    return QRectF(x, y, 200, 200);

}

void BlockScheme::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        moving = true;
        bpoint = event->pos().toPoint();
    }
    if (event->button() == Qt::RightButton && event->HoverMove){
        qDebug()<<"Maus" << sender();
        emit deleteItem(this);
    }
}

void BlockScheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        moving = false;
        //emit reDraw();
        emit Draw(bpoint.x(),bpoint.y());
    }
}

void BlockScheme::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    bpoint = event->pos().toPoint();
    this->setPos(mapToScene(bpoint.x(),bpoint.y()));
}

void BlockScheme::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{

   qDebug()<< "event->pos().x()" << event->pos().x();
   qDebug()<< "isUnderMouse() "<< this->isUnderMouse();
   qDebug()<< "isActive() "<< this->isActive();



    emit deleteItem(this);
}
