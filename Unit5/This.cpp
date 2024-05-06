#include <iostream>
using namespace std;

class Test
{
    public:
        Test(int value=0);
        void print( ) const;
    private:
        int x;
};

Test::Test(int value) : x(value)
{
    //Body intentionally blank.
}

void Test::print() const
{
    // directly access the member x
    cout << "        x = " << x << endl;
    // use this pointer to access the member x
    cout << "  this->x = " << this->x << endl;
    // use this pointer to access the member x
    cout << "(*this).x = " << (*this).x << endl;
}

int main()
{
    Test testObject(12);
    testObject.print();
}

