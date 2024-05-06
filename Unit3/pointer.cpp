#include <iostream>
using namespace std;

int main()
{
    int v1 = 10;
    int *p1 = &v1;
    int *p2 = p1;
    cout << "v1 = " << v1 << endl;
    cout << "p1 = " << p1 << endl; // p1 stores the address of v1
    cout << "*p1 = " << *p1 << endl;
    cout << "&v1 = " << &v1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "*p2 = " << *p2 << endl;
    return 0;
}