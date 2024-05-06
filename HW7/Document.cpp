#include "Document.h"

Document::Document( )
{
    value = new string[0];
    number = 0;
}

Document::Document(const Document &a)
{
    number = a.number;
    value = new string[number];
    for (int i=0;i<number;i++)
    {
        value[i] = a.value[i];
    }
}

Document& Document::addString(string c)
{
    string *temp = new string[number+1];
    for (int i=0;i<number;i++)
    {
        temp[i] = value[i];
    }
    temp[number] = c;
    number++;
    delete [] value; 
    value = temp;
    return *this;
}

int Document::getLength( )
{
    int sum = 0;
    for (int i=0;i<number;i++)
    {
        sum += value[i].length();
    }
    return sum;
}

//Uses iostream:
ostream& operator <<(ostream& outs,const Document& a)
{
    for (int i=0;i<a.number;i++)
    {
        outs << a.value[i] << " ";
    }
    return outs;
}