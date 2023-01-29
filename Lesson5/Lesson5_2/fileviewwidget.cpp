#include "fileviewwidget.h"
#include <QDebug>
#include <QFileSystemModel>



FileViewWidget::FileViewWidget(QWidget *parent): QWidget(parent), model(nullptr)
{

    gridLay = new QGridLayout(this);
    this->setLayout(gridLay);
    tree = new QTreeView(this);
    gridLay->addWidget(tree,2,0,8,10);
    setMinimumSize(500,600);
    gridLay->setRowStretch(1,1);
    gridLay->setRowStretch(2,2);

    path = new QLineEdit(this);
    gridLay->addWidget(path,1,0,1,10);

    findPathLineEdit = new QLineEdit(this);
    gridLay->addWidget(findPathLineEdit,12,0,1,9);

    namePath = new QLabel("Текущий каталог",this);
    gridLay->addWidget(namePath,0,0,1,10);

    findPath = new QLabel("Поиск файла или папки",this);
    gridLay->addWidget(findPath,11,0,1,8);

    findButton = new QPushButton("Поиск",this);
    gridLay->addWidget(findButton,12,9,1,1);

    model = new QFileSystemModel(this);
    model->setRootPath(QDir::rootPath());
    model->setReadOnly(true);

    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::rootPath()));

    connect(tree, SIGNAL(clicked(QModelIndex)),this,SLOT(renamePath()));
    connect(findButton, SIGNAL(clicked()),this,SLOT(findDirFile()));


}

void FileViewWidget::renamePath()
{
    select = tree->selectionModel();
    QModelIndex index = select->currentIndex();
    currentPath = index.data().toString();
    path->setText(currentPath);
}

void FileViewWidget::findDirFile()
{

    thread = new ThreadFinder(findPathLineEdit->text(),this);
    connect(thread, SIGNAL(isFind(QString)),this,SLOT(isFind(QString)));
    thread->start();
}

void FileViewWidget::isFind(QString pathFind)
{

    findPathLineEdit->setText(pathFind);
    if (pathFind != "файл не найден" && pathFind != ""){
        QModelIndex index = model->index(pathFind);
        select->clear();
        select->setCurrentIndex(index,QItemSelectionModel::Select);
        path->setText(pathFind);
    }

}


