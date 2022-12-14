#include "parsetext.h"


ParseText::ParseText()
{

}

bool ParseText::parse(QString& text)
{

    //QChar q = QChar::unicodeVersion(16);


    int pos = text.indexOf("руб.");
    if ( pos != -1)
    {
        text = text.replace(pos, 4 , \u20BD);
        return true;
    }
    else return false;

}
