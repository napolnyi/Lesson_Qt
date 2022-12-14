#ifndef PARSETEXT_H
#define PARSETEXT_H

#include <QString>
#include <QChar>

class ParseText
{
public:
    ParseText();
    bool parse(QString &text);
};

#endif // PARSETEXT_H
