#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define Max 10000

double l1;
int n;
double dist1;
unsigned long long int t,v,l,con,dist;
double con1;

int main()
{
	cin>>l1>>n;
	l = int(l1 * Max + 0.5f);

	for(int i = 0;i<n;i++)
	{
		cin>>t>>v;
		con = t*v*Max;
		con = con % l;
		dist += con;
		dist %= l;
	}

	dist = dist%l;
	dist = min(dist,l - dist);
	dist1 = (1.0*dist)/Max;
	printf("%.4f",dist1);
	cout<<endl;
}
