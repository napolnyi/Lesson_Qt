#include "mainwindow.h"
#include "mainwindowtriangle.h"
#include "mainwindowplaintext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    MainWindowTriangle w_triangle;
    MainWindowPlainText w_plainText;
    w_plainText.show();
    w_triangle.show();
    w.show();
    return a.exec();
}
