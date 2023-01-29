#include "basereader.h"

BaseReader::BaseReader(QObject *parent) : QObject(parent)
{

}

void BaseReader::loadBase()
{
    QFile file (":/base/base.txt");
    if (file.open(QIODevice::ReadOnly)) {

        QTextStream stream (&file);
    }

}
