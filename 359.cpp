//AC
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

string line;
int *a,*b,*c,*d;
bool finder;
int * ch(char chp)
{
	finder = true;
	if(chp == 'a')
		return a;
	if(chp == 'b')
		return b;
	if(chp == 'c')
		return c;
	if(chp == 'd')
		return d;
	finder = false;	
}
int * k1,*k2;
int main()
{
	int aval = 0;
	int bval = 0;
	int cval = 0;
	int dval = 0;
	a = &aval;
	b = &bval;
	c = &cval;
	d = &dval;
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>line;
		int i = line.find("^:=");
		if(i != -1)
		{
			k1 = ch(line[i - 1]);
			k2 = ch(line[i + 3]);
			if(finder)
			{
				char chp1 = line[i - 1];
				char chp2 = line[i + 3];
				//cout<<chp1<<" 2 = "<<chp2<<endl;
				if(chp1 == 'a')
				{
					if(chp2 == 'b')
						*a = *b;
					else
					if(chp2 == 'c')
						*a = *c;
					else
					if(chp2 == 'd')
						*a = *d;
				}
				else
				if(chp1 == 'b')
				{
					if(chp2 == 'a')
						*b = *a;
					else
					if(chp2 == 'c')
						*b = *c;
					else
					if(chp2 == 'd')
						*b = *d;
				}
				else if(chp1 == 'c')
				{
					if(chp2 == 'b')
						*c = *b;
					else
					if(chp2 == 'a')
						*c = *a;
					else
					if(chp2 == 'd')
						*c = *d;
				}
				else if(chp1 == 'd')
				{
					if(chp2 == 'a')
						*d = *a;
					else
					if(chp2 == 'b')
						*d = *b;
					else
					if(chp2 == 'c')
						*d = *c;
				}
			}
			else
			{
				*k1 = int(line[i + 3] - '0');
			}
		}
		else
		{
			int i = line.find(":=");
			if(i != -1)
			{
				char chp1 = line[i - 1];
				char chp2 = line[i + 2];
				//cout<<chp1<<" 2 = "<<chp2<<endl;
				if(chp1 == 'a')
				{
					if(chp2 == 'b')
						a = b;
					else
					if(chp2 == 'c')
						a = c;
					else
					if(chp2 == 'd')
						a = d;
				}
				else
				if(chp1 == 'b')
				{
					if(chp2 == 'a')
						b = a;
					else
					if(chp2 == 'c')
						b = c;
					else
					if(chp2 == 'd')
						b = d;
				}
				else if(chp1 == 'c')
				{
					if(chp2 == 'b')
						c = b;
					else
					if(chp2 == 'a')
						c = a;
					else
					if(chp2 == 'd')
						c = d;
				}
				else if(chp1 == 'd')
				{
					if(chp2 == 'a')
						d = a;
					else
					if(chp2 == 'b')
						d = b;
					else
					if(chp2 == 'c')
						d = c;
				}
			}// :=
			else
			{
				k1 = &aval;
				k1 = ch(line[8]);
				//cout<<line[8]<<endl;
				cout<<*k1<<endl;
			}//writeln
		}
	}
	cin>>n;
}
