#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class PolySeq{
    public:
        int* c;
        int n; //number of coefficients
        PolySeq(int);
        PolySeq();
        ~PolySeq();
        PolySeq& operator+(const PolySeq &);
        PolySeq& Derivative();
        int Integral(int ,int);
};

namespace Poly_Int{
    int getValue(PolySeq&, int);
}

namespace Poly_Float{
    float getValue(PolySeq&, float);
}
