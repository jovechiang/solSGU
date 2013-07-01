#include <iostream>
#include <conio.h>
using namespace std;
#define Max 10000001

int a,b,ans[Max],c = 1;
main()
{
	cin>>a>>b;
	while(1)
	{
		a = (a%b) * 10;
		if(ans[a])
		{
			cout<<ans[a] - 1<<" "<<c - ans[a]<<endl;
			break;
		}
		ans[a] = c;
		if(a == 0)
		{
			cout<<c - 1<<" "<<0<<endl;
			break;
		}
		c++;
	}
}
