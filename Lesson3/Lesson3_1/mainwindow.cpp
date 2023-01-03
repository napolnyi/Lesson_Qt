#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

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
                if (ui->onlyReadCheckBox->isChecked())ui->plainTextEdit->setReadOnly(true);
                else ui->plainTextEdit->setReadOnly(false);
                file.close();
            }
        }

    }
}

void MainWindow::on_saveButton_clicked()
{
    saveAsFile();
}

void MainWindow::on_helpButton_clicked()
{
    QFile file(":/hlp/help.txt");
    if (file.open(QFile::ReadOnly | QFile::ExistingOnly)){
        QTextStream stream(&file);
        ui->plainTextEdit->setPlainText(stream.readAll());
        file.close();
    }
}



void MainWindow::on_translationCheckBox_clicked()
{
    if (ui->translationCheckBox->isChecked())
    {

        translator.load(":/tr/QtLanguage_ru.qm");
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);

    }
    else {

        translator.load(":/tr/QtLanguage_en.qm");
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
    }

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {

    case Qt::Key_Control:
        lst.push_front(Qt::Key_Control);
        break;

    case Qt::Key_S:
        lst.push_back(Qt::Key_S);
        break;

    case Qt::Key_N:
        lst.push_back(Qt::Key_N);
        break;

    case Qt::Key_Q:
        lst.push_back(Qt::Key_Q);
        break;
    }

    if (lst.first() == Qt::Key_Control){

        for (int i = 1; i<lst.length(); i++) {
            if (lst.at(i) == Qt::Key_S) {
                lst.clear();
                saveAsFile();
            }
            else if (lst.at(i) == Qt::Key_N){
                lst.clear();
                ui->plainTextEdit->clear();
            }
            else if (lst.at(i) == Qt::Key_Q){
                qApp->quit();
            }
        }
    }
}


void MainWindow::saveAsFile()
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


void MainWindow::on_styleCheckBox_clicked()
{

    if(ui->styleCheckBox->isChecked()){

        this->setStyleSheet("QMainWindow{background-color:gray}"
                            "QPushButton {background-color:gray; color:blue}"
                            "QPlainTextEdit {background-color:black; color:white}"
                            "QCheckBox {color:blue}"
                            );
    }
    else {
        this->setStyleSheet("QMainWindow{background-color:white} ");
    }
}
