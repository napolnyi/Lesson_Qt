#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QVector>
#include <QMouseEvent>


#include "blockscheme.h"


class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent (QMouseEvent* event) override;
    void mouseMoveEvent (QMouseEvent* event) override;
    void mouseReleaseEvent (QMouseEvent* event) override;


private:
    QGraphicsScene *scene;
    QVector <BlockScheme*> bscheme;
    bool moving;
    QGraphicsItem *item;
    int x = 0;
    int y = 0;

private slots:
    void reDraw();
    void randomColor();
    void Draw(int x, int y);
    void deleteItem(BlockScheme*);
};
#endif // MAINWINDOW_H
