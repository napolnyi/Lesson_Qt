#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QVector>
#include <QMouseEvent>
#include <QEnterEvent>
#include <QGraphicsSceneHoverEvent>
#include "blockscheme.h"


class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent (QMouseEvent *event) override;
    void mouseMoveEvent (QMouseEvent *event) override;

private:
    QGraphicsScene *scene;
    QVector <BlockScheme*> bscheme;
    QGraphicsItem *item = nullptr;
};
#endif // MAINWINDOW_H
