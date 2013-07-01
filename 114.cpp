//AC
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct city
{
	int p,x;
	bool operator>(city &a)
	{
		if(x>a.x)
			return true;
		return false;
	}
			
};
city b[15010];
bool cmp(const city &a,const city &b)
{
	return (a.x<b.x);
}
int n;
main()
{
  	scanf("%d",&n);
  	int mini = 0;
  	int pop = 0;
  	for(int i = 0;i<n;i++)
  	{
		scanf("%d%d",&b[i].x,&b[i].p);
		pop += b[i].p;
	}
	sort(b,b+n,cmp);
	if(pop %2 == 0)	
		pop/=2;
	else
		pop = pop/2 + 1;
	for(int i = 0;i<n;i++)
	{
		pop -= b[i].p;
		if(pop<=0)
		{
			mini = i;
			break;
		}
	}
	printf("%d.00000\n",b[mini].x);
	cin>>n;
}
