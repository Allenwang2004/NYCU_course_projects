#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//計算字數
int main()
{
    string text = "This is a test right";
    stringstream ss(text); //將text轉換成stringstream
    string word;
    int count = 0;
    while (ss >> word) //stringstream會自動以空白字元分割字串
    {
        count++;
    }
    cout<<count;
    cout<<endl;
    cout<<word;
}
