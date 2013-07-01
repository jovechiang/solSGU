#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

bool prime(int a)
{
	if(a == 2)
		return true;
	if(a == 1)
		return false;
	if(a%2 == 0)
		return false;
	int k = int(sqrt(a))+1;
	for(int i = 3;i<=k;i+=2)
	{
		if(a%i == 0)
		{
			return false;
		}
	}
	return true;
}
bool p[1000005];
long long int keygen(int a)
{
	if(!p[a]){
	int maxp;
	long long int sum = 0;
	for(int i = 2;i<=a;i++)
	{
		if(p[i])
		{
			if(a%i == 0)
			{
				maxp = i;
				sum += i;
				while(a%i == 0)
				{
					a/=i;
				}
			}
		}
	}
	return maxp - sum+maxp;}
	return a;
}
int main()
{
	int a,b;
	cin>>a>>b;
	int k = max(a,b);
	for(int i = 0;i<=k;i++)
	{
		p[i] = prime(i);
	}
	long long a1 = keygen(a);
	long long b1 = keygen(b);
	if(a1>b1)
		cout<<'a'<<endl;
	else
		cout<<'b'<<endl;
	getch();
	return 0;
}
