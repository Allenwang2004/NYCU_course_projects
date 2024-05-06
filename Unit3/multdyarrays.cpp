#include <iostream>
using namespace std;

int main()
{
    typedef int* IntArrayPtr; // IntArrayPtr is a pointer to an int
    IntArrayPtr *m = new IntArrayPtr[10]; // m is a pointer to an array of pointers
    for(int i=0; i<10; i++)
    {
        m[i] = new int[20]; // m[i] is a pointer to an array of 20 integers
    }

    for(int i=0; i<10;i++)
    {
        delete [] m[i]; // delete the array pointed by m[i]
    }
    delete [] m; // delete the array pointed by m
}