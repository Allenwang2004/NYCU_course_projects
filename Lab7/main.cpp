#include <iostream>
#include <fstream>
#include <string>
#include "func.h"

using namespace std;
int main()
{
    PolySeq p3;
    int x1, x2;
    float x3;
    int n;
    
    // Read p1
	cin >> n;
    PolySeq p1(n);
	for(int i = 0; i < p1.n; i++)
    {
        cin >> p1.c[i];
    }
    // Read p2
	cin >> n;
    PolySeq p2(n);
	for(int i = 0; i < p2.n; i++)
    {
        cin >> p2.c[i];
    }
    // Read x1 , x2
    cin >> x1 >> x2 >> x3;

    p3 = p1 + p2;
    
    //use namespace Poly_Int
    cout << Poly_Int::getValue(p3,x1) << endl;
    
    p3 = p1.Derivative();
    cout << Poly_Float::getValue(p3,x3) << endl;

    cout << p2.Integral(x1, x2) << endl;
    
    return 0;
}