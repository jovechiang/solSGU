//AC
#include <iostream>
#define Max 10010

using namespace std;

int n,m,y;
int x[Max];
int p[Max];
bool can[Max];
int r;
int s = 0;
int main()
{
	cin>>n>>m>>y;
	for(int i = 0;i < n;i++)
	{
		cin>>p[i];
		x[i] = (p[i] * m) / y;
		s += x[i];
	}
	r = m - s;
	double mx = -100,d1,d2;
	int mxi;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(!can[j])
			{
				d2 = x[j];
				d1 = (1.0 * p[j])*(1.0 * m)/(1.0 * y);
				if(d1 - d2 >= mx)
				{
					mx = d1 - d2;
					mxi = j;
				}//max
			}//if can
		}//for j ta n
		can[mxi] = true;
		mx = -100;
		x[mxi]++;		
	}//for i ta r
	for(int i = 0;i < n;i++)
		cout<<x[i]<<" ";
	cin>>n;
}
