#ifndef THREADFINDER_H
#define THREADFINDER_H

#include <QThread>
#include <QObject>
#include <QFileInfo>

class ThreadFinder : public QThread
{
    Q_OBJECT

public:

    explicit ThreadFinder(QString name,QObject *parent = nullptr);
    void findStop() {toWork = false;}

protected:

    void run() override;
private:

    bool toWork;
    QString name;

signals:

    void isFind(QString);
};

#endif // THREADFINDER_H
