#include "parsetext.h"
#include <QVector>


ParseText::ParseText()
{
    symbolBefore = new  QVector<QString> {"руб.","евро","промилле","знак авторского права"};
    symbolAfter = new QVector<QString> {"\u20BD","\u20AC","\u2030","\u00A9"};

}

bool ParseText::parse(QString& text)
{



    for (int i=0; i<4; i++)
    {

        int pos = text.indexOf(symbolBefore->at(i));
        if ( pos != -1)
        {
            text = text.replace(pos, 4 , "\u2030");
            return true;

        }
    }

    return false;
}
