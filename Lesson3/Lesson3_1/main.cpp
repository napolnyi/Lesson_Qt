#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator trans;
//    trans.load(":/tr/QtLanguage_ru.qm");
//    a.installTranslator(&trans);
    MainWindow w;
    w.show();
    return a.exec();
}
