#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

int lowestcost(long long int b[],long long int n)
{
    if(n-1==0)
        return 0;
    if(n-1==1)
        return b[1];
    return min(lowestcost(b,n-1),lowestcost(b,n-2))+b[n-1];
}

int main()
{
    cout<<"Please enter the filename: ";
    string inputFileName;
    cin >> inputFileName;
    ifstream inputFile(inputFileName);
    long long int n;
    inputFile>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        inputFile>>a[i];
    }
    int ans = lowestcost(a,n);
    cout<<"The lowest cost is "<<ans<<endl;
}