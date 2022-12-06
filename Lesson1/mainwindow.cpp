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


void MainWindow::on_calculateButton_clicked()
{

    ui->resultLineEdit_2->setEnabled(true);
    ui->X2_label->setEnabled(true);
    ui->resultLineEdit_2->clear();

    double ratioA = ui->ratioA->text().toDouble();
    double ratioB = ui->ratioB->text().toDouble();
    double ratioC = ui->ratioC->text().toDouble();

    QString x1,x2;

    if (ratioA !=0)
    {
        double discreminate = qPow(ratioB,2)-4*ratioA*ratioC;
        if(discreminate == 0)
        {
            x1 = QString::number((qSqrt(discreminate) - ratioB)/(2*ratioA));
            ui->resultLineEdit_1->setText(x1);
            ui->resultLineEdit_2->setEnabled(false);
            ui->X2_label->setEnabled(false);
        }
        else
        {
            x1 = QString::number((qSqrt(discreminate) - ratioB)/(2*ratioA));
            x2 = QString::number((-qSqrt(discreminate) - ratioB)/(2*ratioA));
            ui->resultLineEdit_1->setText(x1);
            ui->resultLineEdit_2->setText(x2);
        }
    }
    else
    {
        x1 = QString::number(-ratioC/ratioB);
        ui->resultLineEdit_1->setText(x1);
        ui->resultLineEdit_2->setEnabled(false);
        ui->X2_label->setEnabled(false);
    }



}
