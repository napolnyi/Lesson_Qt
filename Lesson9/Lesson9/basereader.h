#ifndef BASEREADER_H
#define BASEREADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDate>

class BaseReader : public QObject
{
    Q_OBJECT

private:
    QFile *file;

    struct Task
    {
        QString name;
        QDate date;
        int progress;
    };

public:
    explicit BaseReader(QObject *parent = nullptr);
    virtual ~BaseReader();

    void readBase();
    void saveBase(Task *currentTask);



signals:

};

#endif // BASEREADER_H
