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


void MainWindow::on_OpenButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Загрузка файла",QDir::currentPath(),"(*.txt)");
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

void MainWindow::on_FindButton_clicked()
{
    QString html = ui->plainTextEdit->toPlainText();
    int weatherPos = html.indexOf("\"now\":{\"temp\":\"")+15;
    int weatherPosEnd = html.indexOf("\"",weatherPos);
    if (weatherPos != -1 && weatherPosEnd != -1)
    {
        ui->weatherLineEdit->setText(html.mid(weatherPos,weatherPosEnd-weatherPos));
    }

    int ratePos = html.indexOf("\"EUR\",\"rate\":")+13;
    int ratePosEnd = html.indexOf(",",ratePos);
    if(ratePos !=-1 && ratePosEnd !=-1)
    {
       ui->EuroLineEdit->setText(html.mid(ratePos,ratePosEnd-ratePos));
    }


}
