#include "func.h"

PolySeq::PolySeq(int n)
{
    this->n = n;
    c = new int[n];
}

PolySeq::PolySeq()
{
    n = 0;
    c = NULL;
}

PolySeq::~PolySeq()
{
    delete[] c;
}

PolySeq& PolySeq::operator+(const PolySeq &p)
{
    PolySeq* result = new PolySeq();
    int max = (n > p.n) ? n : p.n;
    result->n = max;
    result->c = new int[max];
    if(n > p.n)
    {
        for(int i = 0; i < n; i++)
        {
            result->c[i] = c[i];
        }
        for(int i = n-1;i > n-1-p.n; i--)
        {
            result->c[i] = result->c[i] + p.c[p.n-1-(n-1-i)];
        }
    }
    else
    {
        for(int i = 0; i < p.n; i++)
        {
            result->c[i] = p.c[i];
        }
        for(int i = p.n-1;i > p.n-1-n; i--)
        {
            result->c[i] = result->c[i] + c[n-1-(p.n-1-i)];
        }
    }
    return *result;
}

PolySeq& PolySeq::Derivative()
{
    PolySeq* result = new PolySeq();
    result->n = n - 1;
    result->c = new int[result->n];
    for(int i = 0; i < result->n; i++)
    {
        result->c[i] = c[i] * (result->n-i);
    }
    return *result;
}

int PolySeq::Integral(int x1, int x2)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        result += c[i] * (pow(x2, n-i) - pow(x1, n-i)) / (n-i);
    }
    return result;
}

int Poly_Int::getValue(PolySeq& p, int x)
{
    int result = 0;
    for(int i = 0; i < p.n; i++)
    {
        result += p.c[i] * pow(x, p.n-1-i);
    }
    return result;
}

float Poly_Float::getValue(PolySeq& p, float x)
{
    float result = 0;
    for(int i = 0; i < p.n; i++)
    {
        result += p.c[i] * pow(x, p.n-1-i);
    }
    return result;
}