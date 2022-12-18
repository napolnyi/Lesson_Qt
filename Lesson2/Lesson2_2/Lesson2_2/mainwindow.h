#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QStandardItemModel>
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
    void on_addButton_clicked();

    void on_delButton_clicked();

    void on_checkBox_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
    QStringList* list = new QStringList {"C++", "Python", "Java" ,"C#" ,"PHP" ,"JavaScript"};
    void viewMode();
    void setRole(QModelIndex index, QString str);


};
#endif // MAINWINDOW_H
