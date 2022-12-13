#include "parsetext.h"

ParseText::ParseText()
{

}

QString ParseText::parse(QString text)
{
    qint32 pos = 0;
    QChar q = QChar::unicodeVersion(23);
    q = '20BD';
    QString parceText;
    while (true)
    {
        pos = text.indexOf("руб.",pos);
        if (pos == -1) break;
        parceText = text.replace(pos,4,q);

    }

    return parceText;

}
