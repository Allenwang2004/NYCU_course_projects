#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
using namespace std;

class StringVar
{
    public:
    StringVar(int size);
    StringVar( );
    StringVar(const char a[]);
    StringVar(const StringVar& stringObject);
    ~StringVar( );
    int length( ) const;
    void input_line(istream& ins);
    friend ostream& operator <<(ostream& 
    outs, const StringVar& theString);
    private:
    char *value; 
    int maxLength; 
};

StringVar::StringVar(int size) // : maxLength(size) 是初始化列表 用來初始化成員變數
{
    maxLength = size;
    value = new char[maxLength + 1];
    //+1 is for '\0'
    value[0] = '\0';   // initially an empty string
}

StringVar::StringVar( ) : maxLength(100)
{
    value = new char[maxLength + 1];
    //+1 is for '\0'
    value[0] = '\0';   // initially an empty string
}

StringVar::StringVar(const char a[]): maxLength(strlen(a))
{
    value = new char[maxLength + 1];
    //+1 is for '\0'
    strcpy(value, a);
}

StringVar::StringVar(const StringVar& stringObject): maxLength(stringObject.length( ))
{
    value = new char[maxLength + 1];
    //+1 is for '\0'
    strcpy(value, stringObject.value);
}

StringVar::~StringVar( )
{
    delete [] value;
}

int StringVar::length( ) const
{
    return strlen(value);
}

//Uses iostream:
void StringVar::input_line(istream& ins)
{
    ins.getline(value, maxLength + 1);
}
//Uses iostream:
ostream& operator <<(ostream& outs,
const StringVar& theString)
{
    outs << theString.value;
    return outs;
}

void conversation(int maxNameSize);

int main( )
{
    using namespace std;
    conversation(30);
    cout << "End of demonstration.\n";
    return 0;
}

void conversation(int maxNameSize)
{
    using namespace std;
    StringVar your_name(maxNameSize);
    StringVar our_name("Borg");
    cout << "What is your name?\n";
    your_name.input_line(cin);
    cout << "We are " << our_name << endl;
    cout << "We will meet again " << your_name<< endl;
}