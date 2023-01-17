#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QVector>


#include "blockscheme.h"


class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QGraphicsScene *scene;
    QVector <BlockScheme*> bscheme;

private slots:
    void reDraw();
    void randomColor();
    void Draw(int x, int y);
    void deleteItem(BlockScheme*);
};
#endif // MAINWINDOW_H
