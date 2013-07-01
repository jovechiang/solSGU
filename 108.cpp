#include <iostream>
#include <stdio.h>
#define max_ 1000000
#define num_bit 32
#include <conio.h>
using namespace std;
//1250010
//int sn[312503];
bool sn[64];
int selfnum[max_];
int nums[10001];
int num_of_digits(int k)
{
	int s = 0;
	while(k>=1)
	{
		s += k%10;
		k /= 10;
	}
	return s;
}
int numod(int a)
{
	return  nums[a % 10000]+nums[a/10000];
}
void shift(int a)
{
	for(int i = 0;i<a;i++)
	{
		for(int j = 0;j<=99;j++)
			sn[j] = sn[j+1];
		sn[100] = 0;
	}
}
void print(int a,int b)
{
	cout<<endl;
	cout<<endl;
	for(int i = a;i<=b;i++)
		cout<<sn[i]<<" ";
	cout<<endl;
	cout<<endl;
}
main()
{
	for(int i = 0;i<=10000;i++)
	{
		nums[i] = num_of_digits(i);
	}
	int n;
	cin>>n;
	int num = 1,j,r;
	int counter = 0;
	for(int i = 1;i<=n;i++)
	{
		if(sn[num])
		{
			sn[numod(i) + 1] = 1;
			shift(1);
			continue;
		}
		else
		{
			selfnum[counter] = i;
			cout<<i<<" counter = "<<counter<<endl;
			counter++;
			sn[numod(i) + 1] = 1;
			shift(1);
		}
	}
	cout<<counter<<endl;
	for(int i = 0;i<counter;i++)
		cout<<selfnum[i]<<" ";
	int k;
	int a;
	cin>>k;
	for(int i = 1;i<=k;i++)
	{
		cin>>a;
		if(a == 1)
			cout<<1<<" ";
		else
			cout<<selfnum[a - 1]<<" ";
	}
//getch();
}
