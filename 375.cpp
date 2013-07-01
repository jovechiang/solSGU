#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
//#include <conio.h>
using namespace std;
int a,b;
bool ans[650000];
main()
{
	int counter = 0;
	int n;
	scanf("%d",&n);
	if(n % 2 == 0)
		cout<<"No solution"<<endl;
	else
	{
		while(n > 1)
		{
			while(n%2 == 1)
			{
//				cout<<"1 : "<<n<<endl;
//				getch();
				n = (n - 1)/2;
				ans[counter] = 1;
				counter++;
				if(n == 1)
					goto end;
			}
			counter--;
			n = n*2 + 1;
			while(n%2 == 1)
			{
//				cout<<"2 : "<<n<<endl;
//				getch();
				n = (n + 1)/2;
				ans[counter] = 0;
				counter++;
				if(n == 1)
					goto end;
			}
			counter--;
			n = n*2 - 1;
		}
	end:
	cout<<counter<<endl;
	for(int i = counter - 1;i>=0;i--)
		printf("%d ",ans[i] + 1);
	}	
//	getch();
}
