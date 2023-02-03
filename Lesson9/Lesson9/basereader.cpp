#include "basereader.h"
#include <QDebug>

BaseReader::BaseReader(QObject *parent) : QObject(parent)
{
    file = new QFile("./base.txt",this);
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

void BaseReader::saveBase(QString name, QString date, QString progress)
{

    if (file->open(QIODevice::Append)){
        qDebug()<<"!!!!!!";
        QTextStream stream (file);
        stream << name + "|" +  date +  "|" + progress << "\n";
        file->close();
    }
}
