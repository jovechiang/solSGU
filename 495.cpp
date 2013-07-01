#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int main()
{
	int m,n;
	cin>>n>>m;
	double f = 1,sum = 0;
	double k = n/n;
	for(int i = 0;i<m;i++)
	{
		sum += k;
		k -= k/n;
	}
	printf("%.9lf",sum);
	getch();
	return 0;
}
