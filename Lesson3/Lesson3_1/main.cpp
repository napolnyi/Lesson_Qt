#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator *tr = new QTranslator;
//    tr->load(":/tr/QtLanguage_ru.qm");
//    a.installTranslator(tr);
    MainWindow w;
    w.show();

    return a.exec();
}
