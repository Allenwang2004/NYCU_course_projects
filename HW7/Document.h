#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <string>
using namespace std;

#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

class Document
{
    public:
    Document( );
    Document(const Document& a); //copy constructor
    Document& addString(string c); //Document& 是為了可以連續使用addString
    int getLength( );
    friend ostream& operator <<(ostream& outs,const Document& a);
    private:
    string *value; //pointer to a dynamic array of strings
    int number;
    int sum;
};

#endif



