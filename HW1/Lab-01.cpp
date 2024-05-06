#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int N;
	cin>>N;
	for(long long int i=1;i<=sqrt(N)+1;i++)
	{
		if(N%i==0)
		{
			cout<<i<<" "<<N/i<<endl;
		}
	}
	return 0;
}