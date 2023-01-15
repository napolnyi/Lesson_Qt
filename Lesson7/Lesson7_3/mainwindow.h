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
    BlockScheme *bscheme, *bscheme2;

private slots:
    void reDraw();
    void randomColor();
    void Draw();

};
#endif // MAINWINDOW_H
