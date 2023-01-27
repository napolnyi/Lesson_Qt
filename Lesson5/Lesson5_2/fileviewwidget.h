#ifndef FILEVIEWWIDGET_H
#define FILEVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QFileSystemModel>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "threadfinder.h"



class FileViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileViewWidget(QWidget *parent = nullptr);


private:
    QGridLayout *gridLay;
    QTreeView *tree;
    QFileSystemModel *model;
    QString currentPath;
    QLineEdit *path;
    QLineEdit *findPathLineEdit;
    QLabel *namePath,*findPath;
    QPushButton *findButton;
    ThreadFinder *thread;
    QItemSelectionModel *select;

private slots:
    void renamePath();
    void findDirFile();
    void isFind(QString pathFind);

};

#endif // FILEVIEWWIDGET_H
