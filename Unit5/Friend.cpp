#include <iostream>
#include <cctype>
#include <cstdlib>
#include <istream>
using namespace std;

class Fraction
{
    private:
        int num;
        int den;
    public:
        Fraction(int n, int d);
        friend ostream& operator<<(ostream& os, const Fraction& f); //宣告operator<<為Fraction的friend
        friend istream& operator>>(istream& is, Fraction& f);
};
Fraction::Fraction(int n, int d)
{
    num = n;
    den = d;
}
ostream& operator<<(ostream& os, const Fraction& f) //重載函數必須宣告為全域函數
{
    os << f.num << "/" << f.den; //將分數以分子/分母的形式存入os
    return os;
}
istream& operator>>(istream& is, Fraction& f)
{
    char c;
    is >> f.num >> c >> f.den; //將分數以分子/分母的形式讀入f
    return is;
}
int main()
{
    Fraction f(3, 4);
    cout << f << endl; //輸出3/4
    cin >> f;
    cout << f << endl; //輸出使用者輸入的分數
    return 0;
}