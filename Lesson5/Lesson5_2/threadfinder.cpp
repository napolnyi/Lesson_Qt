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

    for (QFileInfoList::iterator iter = list.begin(),end = list.end(); iter < end; iter++){

        if (iter->fileName() == name){

            emit isFind(iter->absoluteFilePath());
            break;
        }
        else if(iter == end) emit isFind("файл не найден");

    }



}
