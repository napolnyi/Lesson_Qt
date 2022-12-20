#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const int ROWCOUNT = 4;
    const int COLUMNCOUNT = 4;



    model = new QStandardItemModel(ROWCOUNT,COLUMNCOUNT,this);
    for (int i = 0; i < model->rowCount() ; i++ )
    {
        for (int j=0; j < model->columnCount(); j++ )
        {
            QModelIndex index = model->index(i,j);
            QString str = list.at(i)->at(j);
            model->setData(index,str,Qt::DisplayRole);

        }

    }

    ui->tableView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_paintButton_clicked()
{
    QItemSelectionModel* selection = ui->tableView->selectionModel();
    QModelIndexList indexes =selection->selectedIndexes();
    QModelIndex index;
    int row;
    foreach(index, indexes)
       {
           row = index.row();
           for (int j=0; j<model->columnCount();j++)
           {
               model->setData(model->index(row,j),QBrush(Qt::red),Qt::BackgroundRole);
           }


       }

}
