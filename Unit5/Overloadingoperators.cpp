#include <iostream>

using namespace std;

class Complex
{
    private:
        int real, imag;
    public:
        Complex();
        Complex operator + (Complex const &obj) 
        {
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }
        Complex operator = (Complex const &obj) //這裡其實不用做這個overloading，因為有default的operator=，且private沒有指標
        {
            real = obj.real;
            imag = obj.imag;
            return *this;
        }
        void print() { cout << real << " + i" << imag << endl; }
};
Complex::Complex()
{
    real = 0;
    imag = 0;
}
int main()
{
    Complex c1, c2, c3;
    c1.print();
    c2.print();
    c3 = c1 + c2; //這裡會呼叫operator+函數 算出C1+C2的結果 再存到C3
    c3.print();
    return 0;
}