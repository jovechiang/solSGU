#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int a[20000];
bool fard[20000];
main()
{
	int n;
	int sum = 0;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		sum += a[i];
//		if(a[i] % 2)
		{
//			fard[i] = true;
		}
	}
	int sum1 = 0;
	for(int i = 0;i<n;i++)
	{
		if( (a[i]*100) % sum != 0)
			fard[i] = true;
		a[i] = a[i] * 100 /sum;
		sum1 += a[i];
	}
	bool b = true;
	if(sum1 != 100)
	{
		b = false;
		for(int i = 0;i<n;i++)
		{
			if(fard[i])
			{
				a[i]++;
				sum1++;
			}
			else
				continue;
			if(sum1 == 100)
			{
				b = true;
				break;
			}
		}
	}
	if(b)
		for(int i = 0;i<n;i++)
			cout<<a[i]<<" ";
	else
		cout<<"No solution"<<endl;
	cin>>n;
}
