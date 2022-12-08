#include "mainwindowtriangle.h"
#include "ui_mainwindowtriangle.h"

MainWindowTriangle::MainWindowTriangle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTriangle)
{
    ui->setupUi(this);
}

MainWindowTriangle::~MainWindowTriangle()
{
    delete ui;
}

void MainWindowTriangle::on_clcSideButton_clicked()
{
    int16_t sideA = ui->sideA_lineEdit->text().toDouble();
    int16_t sideB = ui->sideB_lineEdit->text().toDouble();
    float angle = ui->angleLineEdit_3->text().toDouble();
    int16_t sideC;

    if (ui->RadiansRadioButton->isChecked()) angle = qRadiansToDegrees(angle);

    sideC = qSqrt(qPow(sideA,2) + qPow(sideB,2) - 2 * sideB * sideA * cos(angle));
    ui->sideC_lineEdit->setText(QString::number(sideC));

}
