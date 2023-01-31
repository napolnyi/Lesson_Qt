#include "basereader.h"

BaseReader::BaseReader(QObject *parent) : QObject(parent)
{
    file = new QFile(":/base/base.txt",this);

}

BaseReader::~BaseReader()
{
    if (file) file->close();
}

void BaseReader::readBase()
{

    if (file->open(QIODevice::ReadOnly)) {

        QTextStream stream (file);
        QString str = stream.read(file->size());
        file->close();
    }

}

void BaseReader::saveBase(Task *currentTask)
{
    if (file->open(QIODevice::WriteOnly | QIODevice::Append)){
        QTextStream stream (file);
        QString str;
        stream << currentTask->name + currentTask->date.toString() + str.number(currentTask->progress);
        file->close();

    }

}
