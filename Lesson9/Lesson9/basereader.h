#ifndef BASEREADER_H
#define BASEREADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class BaseReader : public QObject
{
    Q_OBJECT
public:
    explicit BaseReader(QObject *parent = nullptr);

    void loadBase();

signals:

};

#endif // BASEREADER_H
