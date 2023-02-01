#ifndef BASEREADER_H
#define BASEREADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>


class BaseReader : public QObject
{
    Q_OBJECT

private:
    QFile *file;

public:
    explicit BaseReader(QObject *parent = nullptr);
    virtual ~BaseReader();

    void readBase();
    Q_INVOKABLE void saveBase(QString name, QString date, QString progress);



signals:

};

#endif // BASEREADER_H
