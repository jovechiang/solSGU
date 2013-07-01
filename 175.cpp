#include <iostream>

using namespace std;
int phi(int n,int m)
{
	if(n == 1)
		return 1;
	int s = n/2;
	if(m > s)
	{
		m = n - m + 1;
		if(n % 2 == 0)
		{
			return (phi(s,m));
		}
		return (phi(s+1,m));	
	}
	m = s - m + 1;
	if(n % 2 == 0)
	{
		return (s + phi(s,m));
	}
		return (s + 1 + phi(s,m));	
	
}//int phi
int main()
{
	int n,q;
	cin>>n>>q;
	cout<<phi(n,q)<<endl;
	cin>>n;
	return 0;
}
