#include "Pairs_operation.h"

Pairs::Pairs()
{
    f = 0;
    s = 0;
}

Pairs::Pairs(int first, int second)
{
    f = first;
    s = second;
}

Pairs::Pairs(int first)
{
    f = first;
    s = 0;
}

istream& operator >>(istream& in, Pairs & second)
{
    char temp;
    in >> temp;
    in >> second.f;
    in >> temp;
    in >> second.s;
    in >> temp;
    return in;
}

ostream& operator <<(ostream& outs, const Pairs & second)
{
    outs << "("<<second.f << "," << second.s<<")";
    return outs;
}

Pairs Pairs::operator + (const Pairs & obj)
{
    Pairs temp;
    temp.f = f + obj.f;
    temp.s = s + obj.s;
    return temp;
}

Pairs Pairs::operator - (const Pairs & obj)
{
    Pairs temp;
    temp.f = f - obj.f;
    temp.s = s - obj.s;
    return temp;
}

Pairs Pairs::operator * (int obj)
{
    Pairs temp;
    temp.f = f * obj;
    temp.s = s * obj;
    return temp;
}


