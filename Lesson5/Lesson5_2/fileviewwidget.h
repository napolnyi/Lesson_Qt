#ifndef FILEVIEWWIDGET_H
#define FILEVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>


class FileViewWidget : public QWidget
{
    Q_OBJECT

public:
    FileViewWidget(QWidget *parent = nullptr);
    QStandardItemModel *getCurrentModel() {
        return model;
    }
    void rebuildModel(QString str);
    void setNewModel(QStandardItemModel *newmodel);

private:
    QGridLayout *gridLay;
    QTreeView *tree;
    QComboBox *diskSelBox;
    QStandardItemModel *model;
    QString currentPath;

private slots:
    void chdDisk(int index);

};

#endif // FILEVIEWWIDGET_H
