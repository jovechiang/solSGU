#include <iostream>
#include <cstdio>
//#include <conio.h>

using namespace std;
int x1[5001];
int y1[5001];
int x2[5001];
int y2[5001];
int xp[5001];
int yp[5001];
int counter;
int main()
{
	double d1,d2;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		yp[i] = y2[i] - y1[i];
		xp[i] = x2[i] - x1[i];
		for(int j = i - 1;j>=0;j--)
		{
			d1 = (yp[i])*(yp[j]);
			d2 = (xp[i])*(xp[j]);
			if( d1  == (-1.0)*d2   )
			{
				if(x1[i] == x1[j])
				{
					if(y1[i] == y1[j])
					{
						counter++;
						continue;
					}
				}
				if(x1[i] == x2[j])
				{
					if(y1[i] == y2[j])
					{
						counter++;
						continue;
					}
				}
				if(x2[i] == x2[j])
				{
					if(y2[i] == y2[j])
					{
						counter++;
						continue;
					}
				}
				if(x2[i] == x1[j])
				{					
					if(y2[i] == y1[j])
					{
						counter++;
						continue;
					}
				}
			}
		}
	}
	printf("%d",counter);
//	getch();
	return 0;
}
