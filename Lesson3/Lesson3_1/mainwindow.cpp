#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_openButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Загрузка файла",QDir::currentPath(),"(*.txt);;(*.bin)");
    if (filename.length()){
        int index = filename.indexOf(".txt");
        if (index != -1 && filename.length()-4 == index ){

            QFile file(filename);
            if (file.open(QFile::ReadOnly | QFile::ExistingOnly)){
                QTextStream stream(&file);
                ui->plainTextEdit->setPlainText(stream.readAll());
                file.close();
            }
        }

    }
}

void MainWindow::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,"Сохранение файла",QDir::currentPath(),"(*.txt);;(*.bin)");
    if (filename.length()){
        int index = filename.indexOf(".txt");
        if (index != -1 && filename.length()-4 == index ){

            QFile file(filename);
            if (file.open(QFile::ReadWrite | QFile::NewOnly)){
                QTextStream stream(&file);
                stream << ui->plainTextEdit->toPlainText();
                file.close();
            }
        }

    }
}

void MainWindow::on_helpButton_clicked()
{
    QFile file(":/help.txt");
    if (file.open(QFile::ReadOnly)){
        QByteArray byteArray = file.readAll();
        ui->plainTextEdit->setPlainText(tr(byteArray.data()));
        file.close();
    }
}
