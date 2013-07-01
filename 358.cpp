#include <iostream>
using namespace std;

int main()
{
	int a[3],b[3],c[3];
	cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>c[2];
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		{
			if(a[j]>a[j+1])
			{
				int k = a[j];
				a[j] = a[j+1];
				a[j+1] = k;
			}
		}
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		{
			if(b[j]>b[j+1])
			{
				int k = b[j];
				b[j] = b[j+1];
				b[j+1] = k;
			}
		}
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		{
			if(c[j]>c[j+1])
			{
				int k = c[j];
				c[j] = c[j+1];
				c[j+1] = k;
			}
		}
	a[0] = b[1];
	a[2] = c[1];
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		{
			if(a[j]>a[j+1])
			{
				int k = a[j];
				a[j] = a[j+1];
				a[j+1] = k;
			}
		}
	cout<<a[1]<<endl;
	return 0;
}
