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
    openFile(false);
}

void MainWindow::on_openReadOnlyButton_clicked()
{
    openFile(true);
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

     if (event->key() == Qt::Key_S && event->modifiers() | Qt::Key_Control) {
         saveAsFile();
         }
     else if (event->key() == Qt::Key_N && event->modifiers() | Qt::Key_Control){
         ui->plainTextEdit->clear();
         }
     else if (event->key() == Qt::Key_Q && event->modifiers() | Qt::Key_Control){
         qApp->quit();
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

void MainWindow::openFile(bool readOnly)
{
    QString filename = QFileDialog::getOpenFileName(this,"Загрузка файла",QDir::currentPath(),"(*.txt);;(*.bin)");
    if (filename.length()){
        int index = filename.indexOf(".txt");
        if (index != -1 && filename.length()-4 == index ){

            QFile file(filename);
            if (file.open(QFile::ReadOnly | QFile::ExistingOnly)){
                QTextStream stream(&file);
                ui->plainTextEdit->setPlainText(stream.readAll());
                if (readOnly) ui->plainTextEdit->setReadOnly(true);
                else ui->plainTextEdit->setReadOnly(false);
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

