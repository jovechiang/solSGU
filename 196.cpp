#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,a,b;
int num[10001];
int num2[10001];
main()
{
	cin>>n>>m;
	unsigned long long s = 0;
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		s  -= num[a]*num[a];
		num[a]++;
		s  += num[a]*num[a];
		
		s  -= num[b]*num[b];
		num[b]++;
		s  += num[b]*num[b];
	}
	printf("%d",s);
	cin>>n;
}
