#include "parsetext.h"
#include <QtCore>
#include <QList>
#include <QChar>

ParseText::ParseText()
{

}

bool ParseText::parse(QString& text)
{


    QStringList symbolBefore {"руб.","евро","промилле","знак авторского права"};
    QStringList symbolAfter {"₽","€","‰","©"};


    for (int i = 0; i < symbolBefore.size(); i++)
    {

        int pos = text.indexOf(symbolBefore.at(i));
        if ( pos != -1)
        {
            text = text.replace(pos, symbolBefore.at(i).length() , symbolAfter.at(i));

            return true;

        }
    }

    return false;


}
