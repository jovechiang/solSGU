#include <iostream>
#include <conio.h>
using namespace std;
int dr(int k)
{
	int c = 0;
	while(k>=1)
	{
		c += k%10;
		k /= 10;
	}
	if(c>=10)
		return dr(c);
	return c;
}
int num[10000];
int ans[10000];
int main()
{
	int k,n,a;
	cin>>k;
	for(int i = 0;i<k;i++)
	{
		cin>>n;
		for(int i = 0;i<1000;i++)
		{
			ans[i] = 1;
			num[i] = 0;
		}
		for(int j = 0;j<n;j++)
		{
			cin>>a;
			num[j] = dr(a);
		}
//		for(int p = 0;p<n;p++)
//		{
			ans[0] = dr(num[0]);
//			cout<<ans[0]<<endl<<endl;
			for(int s = 1;s<n;s++)
			{
//				cout<<num[s]<<" ";
				ans[s] *= ans[s - 1]*dr(num[s]);
//			cout<<ans[s]<<endl<<endl;
				ans[s] = dr(ans[s]);
//			cout<<ans[s]<<endl<<endl;
//				cout<<"  ans  =  "<<ans[p]<<"   ";
			}
//			ans[p] = dr(ans[p]);
//			cout<<endl;
//		}
		a = 0;
		for(int p = 0;p<n;p++)
		{
//			cout<<ans[i]<<" ";
			a += ans[p];
		}
		a = dr(a);
		cout<<a<<endl;
	}
	getch();
	return 0;
}
