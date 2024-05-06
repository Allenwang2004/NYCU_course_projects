#include "operator.h"

const Complex Complex::operator+(const Complex &rhs) //不是friend的話要加Complex::
{
    Complex temp;
    temp.re = re + rhs.re;
    temp.im = im + rhs.im;
    return temp;
}

const Complex operator-(const Complex &lhs, const Complex &rhs)
{
    Complex temp;
    temp.re = lhs.re - rhs.re;
    temp.im = lhs.im - rhs.im;
    return temp;
}

const Complex Complex::operator*(const Complex &rhs) 
{
    Complex temp;
    temp.re = re * rhs.re - im * rhs.im;
    temp.im = re * rhs.im + im * rhs.re;
    return temp;
}

const Complex operator!(const Complex &c)
{
    Complex temp;
    temp.re = c.re;
    temp.im = -c.im;
    return temp;
}

bool operator==(const Complex &lhs, const Complex &rhs)
{
    return (lhs.re == rhs.re && lhs.im == rhs.im);
}

bool Complex::operator!=(const Complex &rhs)
{
    return (re != rhs.re || im != rhs.im);
}

ostream &operator<<(ostream &out, const Complex &rhs)
{
    if (rhs.im < 0)
        out << rhs.re << "-" << -rhs.im << "i";
    else
        out << rhs.re << "+" << rhs.im << "i";
    return out;
}

istream &operator>>(istream &in, Complex &rhs)
{
    in >> rhs.re >> rhs.im;
    return in;
}

Complex::Complex(double r, double i) : re(r), im(i) {}