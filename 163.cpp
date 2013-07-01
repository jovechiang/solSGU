#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int a;
int tavan(int a,int b)
{
	int k = 1;
	for(int i = 0;i<b;i++)
		k *= a;
	return k;
}
main()
{
	int n,k;
	int sum = 0;
	cin>>n>>k;
	for(int i = 0;i<n;i++)
	{
		cin>>a;
		if(k%2 ==0)
		{
			sum += tavan(a,k);
		}
		else
		{
			if(a >=0)
				sum += tavan(a,k);
		}
	}
	cout<<sum<<endl;
	cin>>n;
}
