#include <iostream>
#include <stdio.h>
#define Max 2000
using namespace std;

int n;
unsigned long long a[Max] = {0,1,5,11};
main()
{
	cin>>n;
	int s;
	int ms = 3;
	int md = 2;
	for(int i = 4;i<=n;i++)
	{
		s = 0;
		if(i % 2 == 1)
			ms++;
		else
			md++;
		s = md * ms;
	 	a[i] = a[i - 1] + s;
		
	}
//	cout<<md<<" "<<ms<<endl;
	cout<<a[n]<<endl;
	cin>>n;
}
