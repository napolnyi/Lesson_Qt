#ifndef MAINWINDOWTRIANGLE_H
#define MAINWINDOWTRIANGLE_H

#include <QMainWindow>
#include <QtMath>

namespace Ui {
class MainWindowTriangle;
}

class MainWindowTriangle : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowTriangle(QWidget *parent = nullptr);
    ~MainWindowTriangle();

private slots:
    void on_clcSideButton_clicked();

private:
    Ui::MainWindowTriangle *ui;
};

#endif // MAINWINDOWTRIANGLE_H
