#include <iostream>
//#include <conio.h>

using namespace std;

class paper
{
	public:
		int pt,dt;
		int sum;
		void copy(paper a)
		{
			pt = a.pt;
			dt = a.dt;
			sum = a.sum;			
		}
};
paper p[101];
int n;
int t1[101],t2[101];
int main()
{
	cin>>n;
	for(int i = 0;i<n;i++)
		cin>>p[i].pt;
	for(int i = 0;i<n;i++)
		cin>>p[i].dt;
	for(int i = 0;i<n;i++)
		p[i].sum = p[i].pt + p[i].dt;
	paper k;
/*	for(int i = 0;i<n - 1;i++)
		for(int j = 0;j<n - 1;j++)
		{
			if(p[j].sum<p[j+1].sum)
			{
				k.copy(p[j]);
				p[j].copy(p[j+1]);
				p[j+1].copy(k);
			}
		}*/
	for(int i = 0;i<n - 1;i++)
		for(int j = 0;j<n - 1;j++)
		{
			if(p[j].dt<p[j+1].dt)
			{
				k.copy(p[j]);
				p[j].copy(p[j+1]);
				p[j+1].copy(k);
			}
		}
/*	for(int i = 0;i<n - 1;i++)
		for(int j = 0;j<n - 1;j++)
		{
			if(p[j].pt<p[j+1].pt)
			{
				k.copy(p[j]);
				p[j].copy(p[j+1]);
				p[j+1].copy(k);
			}
		}*/
	int max = -1;
	t1[0] = p[0].pt;
	t2[0] = p[0].pt + p[0].dt;
	for(int i = 1;i<n;i++)
	{
		t1[i] = p[i].pt + t1[i-1];
		t2[i] = t1[i] + p[i].dt;
	}
	for(int i = 0;i<n;i++)
	{
		if(t2[i] > max)
		{
			max = t2[i];
		}
	}
	cout<<max<<endl;
//	getch();
	return 0;
}
