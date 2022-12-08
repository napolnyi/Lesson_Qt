#include "mainwindowplaintext.h"
#include "ui_mainwindowplaintext.h"

MainWindowPlainText::MainWindowPlainText(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowPlainText)
{
    ui->setupUi(this);
}

MainWindowPlainText::~MainWindowPlainText()
{
    delete ui;
}

void MainWindowPlainText::on_addTextButton_clicked()
{
    ui->plainTextEdit_1->appendPlainText(ui->plainTextEdit_2->toPlainText());

}

void MainWindowPlainText::on_rplTextButton_clicked()
{
    ui->plainTextEdit_1->setPlainText(ui->plainTextEdit_2->toPlainText());
}

void MainWindowPlainText::on_HtmlTextButton_clicked()
{
    ui->plainTextEdit_1->appendHtml("<font color = 'red'> Hello</font>");
}
