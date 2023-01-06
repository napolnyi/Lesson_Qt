#include "mainwindow.h"
#include "fileviewwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    FileViewWidget fvw;
    qDebug()<< "555111";
    fvw.show();
    qDebug()<< "777111";
    return a.exec();
}
