#ifndef FILEVIEWWIDGET_H
#define FILEVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QFileSystemModel>
#include <QLineEdit>
#include <QLabel>



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
    QLabel *namePath;

private slots:
    void renamePath();

};

#endif // FILEVIEWWIDGET_H
