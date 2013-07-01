#include <iostream>
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
		cout<<num[i];
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
BigInt a,b;
int a1,a2;
int bozorgtar()
{
	if(a.len()>b.len())
		return 1;
	if(a.len()<b.len())
		return 2;
	if(a.len() == b.len())
	{
		int i = a.len();
		while(a.num[i] == b.num[i])
		{
			i--;
			if(i<0)
				return 1;
		}
		if(a.num[i]>b.num[i])
			return 1;
		return 2;
	}
}
int num[1000],l;
void menha()
{
	if(bozorgtar() == 1)
	{
		for(int i = 0;i<a.len();i++)
		{
			if(a.num[i]>=b.num[i])
			{
				num[i] = a.num[i] - b.num[i];
//				cout<<num[i]<<endl<<endl<<endl;
			}
			else
			{
				a.num[i] += 10;
				a.num[i+1]--;
				num[i] = a.num[i] - b.num[i];
			}
		}
		int i = a.len();
		while(num[i] == 0)
		{
			i--;
		}
		l = i+1;
		return;
	}
	else
	{
		for(int i = 0;i<b.len();i++)
		{
			if(b.num[i]>=a.num[i])
				num[i] = b.num[i] - a.num[i];
			else
			{
				b.num[i] += 10;
				b.num[i+1]--;
				num[i] = b.num[i] - a.num[i];
			}
		}
		int i = b.len();
		while(num[i] == 0)
		{
			i--;
		}
		l = i+1;
	}
}//void menha
int main()
{
	cin>>a1>>a2;
	if(a1 == a2)
	{
		cout<<0;
		return 0;
	}
	for(int i = 0;i<a2;i++)
		a.zarb(a1);
//	a.print();
	for(int i = 0;i<a1;i++)
		b.zarb(a2);
//	b.print();
//	cout<<endl<<bozorgtar()<<endl;
	menha();
	if(bozorgtar() == 2)
		cout<<'-';
	for(int i = l-1;i>=0;i--)
		cout<<num[i];
//	getch();
	return 0;
}
