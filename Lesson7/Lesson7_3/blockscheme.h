#ifndef BLOCKSCHEME_H
#define BLOCKSCHEME_H

#include <QObject>
#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>


class BlockScheme : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit BlockScheme(QObject *parent = nullptr);
    void setBrush(QBrush brush) {this->brush = brush; emit reDraw();}

signals:
    void reDraw();
    void Draw();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:
    enum Geometry {RECTANGLE, ELLIPS, STAR};
    Geometry geometry;
    int x, y;
    QBrush brush;
    bool moving;
    QPoint bpoint;
    int countClick;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // BLOCKSCHEME_H
