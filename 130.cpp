#include <iostream>
//#include <conio.h>
using namespace std;
unsigned long long int num[31];
int main()
{
	memset(num,0,sizeof(num));
	int k;
	cin>>k;
	num[0] = 1;
	num[1] = 1;
	for(int i = 2;i<=k;i++)
	{
		for(int j = 0;j<i;j++)
		{
			num[i] += num[j] * num[i-1 - j];
		}
	}
	cout<<num[k]<<" ";
	cout<<k+1<<endl;
//	getch();
	return 0;
}
