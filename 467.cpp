#include <iostream>
#include <cmath>

using namespace std;

double p1;
double p2;
double p14om;
int main()
{
	int p;
	int ct = 1;
	p1 = M_PI * 0.5 * 0.5;
	p2 = 1 - p1;
	p14om = p2 / 4;
//	cout<<"p1 = "<<p1<<endl;
//	cout<<"baghimande = "<<p2<<endl;
//	cout<<"baghimande 4om= "<<p14om<<endl;
//	cout<<"baghimande 2om= "<<p14om * 2<<"  ya "<<p2/2<<endl;
//	cout<<"p1 + p140m = "<<p1 + p14om<<endl;
	while( cin>>p)
	{
		cout<<"Case #"<<ct<<": ";
		if(p == 0)
			cout<<0;
		else
		if(p <= p1 * 100)
			cout << 1;
		else
		if(p <= 95)
			cout<<2;
		else
		if(p <= 99)
			cout<<3;
		else
			cout<<4;
		cout<<endl;
		ct++;
	}
}
