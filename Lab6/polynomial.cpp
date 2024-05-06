#include "polynomial.h"

void PolySeq::setDegree(int d)
{
    this->highest_degree = d;
    c = new double[this->highest_degree+1];
    for(int i=0;i<=this->highest_degree;i++){ c[i]=0; }
}

void PolySeq::setCoeff(int exp, double coef)
{
    c[exp] = coef;
}

PolySeq::~PolySeq()
{
    delete [] c;
}

const double PolySeq::getValue(double x)
{
    double result = 0;
    for(int i=0;i<=highest_degree;i++)
    {
        result += c[i] * pow(x, i);
    }
    return result;
}
//3 #The highest degree of P1.
//3 -2 1 0 #The coefficient of P1.(x^3, x^2, x^1, x^0) respectively.
//2 #The highest degree of P2.
//9 -4 1 #The coefficient of P2.(x^2, x^1, x^0) respectively.
//2 3 #x1, x2
//this is the input.txt
istream &operator>>(istream &in, PolySeq &poly)
{
    for(int i=poly.highest_degree;i>=0;i--)
    {
        double coef;
        in >> coef;
        poly.setCoeff(i, coef);
    }
    return in;
}


PolySeq& PolySeq::operator=(const PolySeq &rhs) //如果沒有做這個overloading，會有default的operator=，只會複製指標，不會複製內容 因為c是指標
{
    int newdegree = rhs.highest_degree;
    if(highest_degree != newdegree)
    {
        delete [] c;
        highest_degree = newdegree;
        c = new double[highest_degree+1];
    }
    for(int i=0;i<=highest_degree;i++)
    {
        c[i] = rhs.c[i];
    }
    return *this;
}

const PolySeq operator+(const PolySeq &lhs, const PolySeq &rhs)
{
    PolySeq result;
    int newdegree = (lhs.highest_degree > rhs.highest_degree) ? lhs.highest_degree : rhs.highest_degree;
    result.setDegree(newdegree);
    for(int i=0;i<=newdegree;i++)
    {
        if(i<=lhs.highest_degree) 
            result.c[i] += lhs.c[i];
        if(i<=rhs.highest_degree)
            result.c[i] += rhs.c[i];
    }
    return result;
}

const PolySeq operator*(const PolySeq &lhs, const PolySeq &rhs)
{
    PolySeq result;
    int newdegree = lhs.highest_degree + rhs.highest_degree;
    result.setDegree(newdegree);
    for(int i=0;i<=lhs.highest_degree;i++)
    {
        for(int j=0;j<=rhs.highest_degree;j++)
        {
            result.c[i+j] += lhs.c[i] * rhs.c[j];
        }
    }
    return result;
}

const PolySeq PolySeq::Derivative()
{
    PolySeq result;
    result.setDegree(highest_degree-1);
    for(int i=0;i<highest_degree;i++)
    {
        result.setCoeff(i, c[i+1] * (i+1));
    }
    return result;
}

const double PolySeq::Integral(int up_bound, int low_bound)
{
    double result = 0;
    for(int i=0;i<=highest_degree;i++)
    {
        result += c[i] * (pow(up_bound, i+1) - pow(low_bound, i+1)) / (i+1);
    }
    return result;
}