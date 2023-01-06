#include "fileviewwidget.h"

#include <QDir>

FileViewWidget::FileViewWidget(QWidget *parent): QWidget(parent), model(nullptr)
{
    gridLay = new QGridLayout(this);
    this->setLayout(gridLay);
    tree = new QTreeView(this);
    gridLay->addWidget(tree,1,0,10,10);
    setMinimumSize(500,600);

    diskSelBox = new QComboBox(this);
    QFileInfoList list = QDir::drives();
    QFileInfoList::const_iterator listdisk = list.begin();
    int amount = list.count();
    for (int i=0; i<amount ;i++ ) {
        diskSelBox->addItem(listdisk->path());
        listdisk++;
    }
    if (amount > 0){
        rebuildModel (list.at(0).path());
    }
    gridLay->addWidget(diskSelBox,0,0,1,2);
    connect(diskSelBox, SIGNAL(activated(int)),this,SLOT(chdDisk(int)));

}

void FileViewWidget::rebuildModel(QString str)
{
    currentPath = str;
    QStandardItemModel *model = new QStandardItemModel(this);
    QList<QStandardItem*> items;
    QStandardItem *it = new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)),str);
    items.append(it);
    model->appendRow(items);


    QDir dir(str);
    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir:: Files);
    QStringList list = dir.entryList();
    int amount = list.count();
    QList<QStandardItem*> folders;
    for (int i=0; i< amount; i++){
        QStandardItem* f = new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)),list.at(i));
        folders.append(f);
    }
    items.at(0)->appendRows(folders);

    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir:: Files);
    amount = list.count();
    QList<QStandardItem*> files;
    for (int i=0; i< amount; i++){
        QStandardItem* f = new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)),list.at(i));
        folders.append(f);
    }
    items.at(0)->appendRows(files);
    setNewModel(model);



}

void FileViewWidget::setNewModel(QStandardItemModel *newModel)
{
    tree->setModel(newModel);
    model = newModel;
}

void FileViewWidget::chdDisk(int index)
{
    QFileInfoList list = QDir::drives();
    rebuildModel (list.at(index).path());

}
