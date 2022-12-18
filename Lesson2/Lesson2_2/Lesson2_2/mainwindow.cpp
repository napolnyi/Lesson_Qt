#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    model = new QStandardItemModel (list->size(),1,this);
    for (int i = 0; i < model->rowCount(); ++i)
    {
        QModelIndex index = model->index(i,0);
        QString str = list->at(i);

        setRole(index,str);
    }

    viewMode();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{

    list->push_back("Unknown");
    QString str = list->last();
    QStandardItem* item = new QStandardItem (str);
    model->appendRow(item);
    QModelIndex index = model->index(list->size()-1,0);

    setRole(index,str);
    viewMode();

}

void MainWindow::on_delButton_clicked()
{
    model->takeRow(list->size()-1);
    list->pop_back();

    viewMode();

}

void MainWindow::viewMode()
{
    if (ui->checkBox->isChecked()) ui->listView->setViewMode(QListView::IconMode);
    else ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setModel(model);
}

void MainWindow::setRole(QModelIndex index, QString str)
{
    model->setData(index,str,Qt::DisplayRole);
    model->setData(index, str, Qt::ToolTipRole);
    model->setData(index,QIcon("./Icons/" + str + ".png"),Qt::DecorationRole);
}


void MainWindow::on_checkBox_clicked()
{
    viewMode();
}
