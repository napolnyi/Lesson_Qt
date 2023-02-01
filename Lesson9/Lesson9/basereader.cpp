#include "basereader.h"
#include <QDebug>

BaseReader::BaseReader(QObject *parent) : QObject(parent)
{
    file = new QFile(":/Base/base.txt",this);
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
    bool f = file->open(QIODevice::Append);
    qDebug()<<f;
    if (f){
        qDebug()<<"!!!!!!";
        QTextStream stream (file);
        stream << name + "|" +  date +  "|" + progress << "\n";
        file->close();

    }

}
