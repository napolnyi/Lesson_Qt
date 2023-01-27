#include "mainwindow.h"
#include "fileviewwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    FileViewWidget fvw;
    fvw.show();
    return a.exec();
}
