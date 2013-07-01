#include <iostream>
#include <cstring>
#include <algorithm>
#include <conio.h>
#define Maxn 200
#define Max 100000

using namespace std;

bool num[10];
bool c2;
bool up,down;
bool one;
int num_ragham(int k)
{
	if(k == 0)
		return 1;
	int ct = 0;
	while(k >= 1)
		ct++,k /= 10;
	return ct;
}
int yekan(int k)
{
	return k % 10;
}
int dahgan(int k)
{
	return k / 10;
}
void out()
{
	int _;
	cin>>_;
}
void out(int k)
{
	if(k == Max)
		cout<<-1;
	else
		cout<<k<<endl;
}
int P[Maxn];
int p(int i)
{
	int b = i;
	if(i >= 100)
	{
		b = 0;
	}
	else
	if(i <= -1)
	{
		b = 99;
	}
	return P[b];
}
int can_go(int channel)
{
	if(num_ragham(channel) == 2)
	{
		if( ! c2)
			return Max;
		if( num[ yekan(channel) ] && num[ dahgan(channel) ] )
			return 3;
		return Max;
	}
	if(num[channel])
		return 1;
	return Max;
}
int main()
{
	int a,b,c;
	
	cin>>num[1]>>num[2]>>num[3]>>up;
	cin>>num[4]>>num[5]>>num[6]>>down;
	cin>>num[7]>>num[8]>>num[9];
	cin>>c2>>num[0];
	cin>>a>>b;
	for(int i = 0;i <= 99;i++)
		P[i] = Max;
	P[a] = 0;
	if(up)
	{		
		for(int i = a + 1;i != a;i++)
		{
			if(i == 100)
				i = 0;
			else
			if(i == -1)
				i = 99;
			P[i] = min(p(i - 1) + 1,P[i]);
			if(i == a)
				break;
		}
	}
	if(down)
	{		
		for(int i = a - 1;i != a;i--)
		{
			if(i == 100)
				i = 0;
			else
			if(i == -1)
				i = 99;
			P[i] = min(p(i + 1) + 1,P[i]);
			if(i == a)
				break;
		}
	}
	for(int j = 0;j < 100;j++)
	for(int i = a + 1;i != a;i++)
	{
		if(i == 100)
			i = 0;
		else
		if(i == -1)
			i = 99;			
		c = can_go(i);
		P[i] = min(P[i],c);
		if(up)
			P[i] = min(P[i],p(i - 1) + 1);
		if(down)
			P[i] = min(P[i],p(i + 1) + 1);
		if(i == a)
			break;
	}
	out(P[b]);
//	cin>>P[0];
	return 0;
}
