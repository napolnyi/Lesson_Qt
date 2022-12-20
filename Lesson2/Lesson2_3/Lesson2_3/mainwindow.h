#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringList>
#include <QString>
#include <QVector>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_paintButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;

    QStringList* listColumn = new QStringList {"No", "Имя Компьютера", "IP адрес", "МАС адрес"};
    QStringList* listRow1 = new QStringList {"1", "Имя 1", "192.168.0.1", "61-98-41-AК-CD-EА"};
    QStringList* listRow2 = new QStringList {"2", "Имя 2", "192.168.0.2", "00:11:72:33:49:52"};
    QStringList* listRow3 = new QStringList {"3", "Имя 3", "192.168.0.3", "61-98-58-AК-CD-EА"};
    QVector<QStringList*> list {listColumn,listRow1,listRow2,listRow3};

};
#endif // MAINWINDOW_H
