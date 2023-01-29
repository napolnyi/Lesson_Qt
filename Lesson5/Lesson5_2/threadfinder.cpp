#include "threadfinder.h"
#include <QDir>
#include <QDebug>

ThreadFinder::ThreadFinder(QString name, QObject *parent) :QThread(parent)
{

    toWork = true;
    this->name = name;

}

void ThreadFinder::run()
{
    QDir dir(QDir::root());
    dir.setFilter(QDir::Files | QDir::Dirs );
    QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.count(); i++){

            if (list.at(i).fileName() == name){
                emit isFind(list.at(i).absoluteFilePath());
                break;
            }
            else if (i == (list.count()-1)) {
                emit isFind("файл не найден");
            }
        }
}
