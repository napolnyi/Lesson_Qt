#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_plainTextEdit_textChanged()
{
    text = ui->plainTextEdit->toPlainText();

    while (parseText->parse(text))
    {

        ui->plainTextEdit->setPlainText(text);

    }

}
