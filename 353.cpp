#include <iostream>
//#include <conio.h>

using namespace std;
int main()
{
	int n,k1,k2,p1,p2,p3,k3;
//	while(1){
	int t = 0;
	cin>>n>>k1>>k2>>p1>>p2>>p3;
	if(n>=p1)
	{
		n -= p1;
		t += k1;
		int i = 1;
		while(i<=k2)
		{
			if(n<1)
				break;
			n -= p2;
			t++;
			i++;			
		}
		if(n>0)
		{
			while(n>0)
			{
				n -= p3;
				t++;
				i++;
			}
		}
	}
	cout<<t<<endl;
//	getch();
	return 0;
}
