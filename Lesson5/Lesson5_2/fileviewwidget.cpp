#include "fileviewwidget.h"

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

    namePath = new QLabel("Текущий каталог",this);
    gridLay->addWidget(namePath,0,0,1,10);

    model = new QFileSystemModel(this);
    model->setRootPath(QDir::homePath());
    model->setReadOnly(true);

    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::homePath()));

    connect(tree, SIGNAL(clicked(QModelIndex)),this,SLOT(renamePath()));

}

void FileViewWidget::renamePath()
{
    QItemSelectionModel *select = tree->selectionModel();
    QModelIndex index = select->currentIndex();
    currentPath = index.data().toString();
    path->setText(currentPath);
}


