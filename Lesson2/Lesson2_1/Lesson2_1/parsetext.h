#ifndef PARSETEXT_H
#define PARSETEXT_H

#include <QString>
#include <QVector>

class ParseText
{
public:
    ParseText();
    bool parse(QString& text);


private:
    QVector<QString> *symbolBefore;
    QVector<QString> *symbolAfter;

};

#endif // PARSETEXT_H
