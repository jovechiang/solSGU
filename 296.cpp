#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

char n[10000];
int k;
int mx;
int mxi;
int mn;
int mni;
int takoja = 0;
int length;
int counter;
int num(char s)
{
	return int(s)-'0';
}
void findmax()
{
	mx = -1;
	mxi = -1;
	for(int i = takoja;i<length;i++)
		if(num(n[i]) > mx )
		{
			mx = num(n[i]);
			mxi = i;
		}
}//void max finder
void findmin()
{
	mn = 10;
	mni = -1;
	for(int i = takoja;i<mxi;i++)
		if(num(n[i]) < mn )
		{
			mn = num(n[i]);
			mni = i;
		}
}//void min finder
void shift(int m)
{
	for(int i = m;i<length;i++)
		n[i] = n[i+1];
	n[length - 1] = 0;
	length--;
}
int main()
{
	char c;
	cin>>n;
	cin>>k;
	length = strlen(n);
	if(k == length)
	{
		cout<<0<<endl;
		return 0;
	}
	if(k == 0)
		counter = 1;
	else
	{
		counter = 0;
//		n[length] = '9';
	}
	bool find;
	bool _do = false;
//	cout<<length<<endl;
	while(counter<k)
	{
		findmax();
		find = false;
		while(mxi>takoja - 1)
		{
			findmin();
			if(mni == -1)
			{
				if(!(mxi == length - 1))
				{
					break;
				}
				else
				{
					if(counter<k - 1)
						_do = true;
					mni = length;
				}
			}
			shift(mni);
			counter++;
			mxi--;
			if(counter >= k)
			{
//9				find = true;
				break;
			}
		}
		if(find)
		{
			break;
		}
		else
		{
			if(_do)
			{
				int i = length - 1;
				while(counter<k)
				{
					shift(i);
					i--;
					counter++;
				}
			}
			takoja++;
		}
	}//Big While
	cout<<n<<endl;
//	cout<<length<<endl;
	getch();
	return 0;
}
