#include <iostream>
#include <cstdio>
//#include <conio.h>
using namespace std;
class BigInt
{
	public:
		void print();
		int len(){return length;}
		void zarb(int k);
		BigInt(){num[0] = 1;length = 1;}
		int num[10000];
	private:
		int length;
};
void BigInt::print()
{
	for(int i = length - 1;i>=0;i--)
	{
		printf("%d",num[i]);
	}
	cout<<endl;
}//void bigint::print
void BigInt::zarb(int k)
{
	for(int i = 0;i<length;i++)
		num[i] *= k;
	for(int i = 0;i<length+10;i++)
	{
		num[i+1] += num[i]/10;
		num[i] %= 10;
	}
	int i = length+10;
	while(num[i] == 0)
	{
//		cout<<i<<endl;
		i--;
	}
	length = i+1;
}

BigInt c;
int a,b,k;
main()
{
	scanf("%d%d%d",&a,&b,&k);
	for(int i = 0;i<k;i++)
	{
		c.zarb(a+b);
	}
	c.print();
//	getch();
}
