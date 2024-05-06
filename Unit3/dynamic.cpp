#include <iostream>
using namespace std;

int main()
{
    int *p1 = new int;
    *p1 = 10;
    int *p2;
    p2 = p1; // p2 stores the address of p1
    cout << "p1 = " << p1 << endl; // p1 stores the address of v1
    cout << "*p1 = " << *p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "*p2 = " << *p2 << endl;
    *p2 = 20; // changes the value of the memory location pointed by p1
    cout << "p1 = " << p1 << endl; // p1 stores the address of v1
    cout << "*p1 = " << *p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "*p2 = " << *p2 << endl;
    p1 = new int;
    *p1 = 30; // changes the value of the memory location pointed by p1
    cout << "p1 = " << p1 << endl; // p1 stores the address of v1
    cout << "*p1 = " << *p1 << endl;
    cout << "p2 = " << p2 << endl;  // p2 still stores the address of the old memory location 內存位置
    cout << "*p2 = " << *p2 << endl;
    delete p1;

    typeder double* DoublePtr;
    DoublePtr d; // d is a pointer to a double
    d = new double[10]; // d is a pointer to an array of doubles

    return 0;
}