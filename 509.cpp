#include <iostream>
#include <cstdio>
#define ULL unsigned long long int
#define get(a) scanf("%d",&a)
#define Maxn 100010
#define clockwise 1
#define counterclockwise -1

using namespace std;

int n;
struct Car
{
	int pos,color,dir;
	void read()
	{
		get(pos);
		get(color);
		get(dir);
	}
};
Car car[Maxn];
ULL t,L;
int dor;
int r;
int POS(int k)
{
	if( k < 0)
		k += L;
	return k % L;	
}
int main()
{
	get(n);
	get(L);
	for(int i = 0;i < n;i++)
	{
		car[i].read();
	}
	cin>>t;
	r = t % L;	
	dor = t / L;
	cout<<"r = "<<r<<endl;
	for(int i = 0;i < n;i++)
	{
		cout<<POS(car[i].pos + r * car[i].dir)<<endl;
	}
	cin>>r;
}
