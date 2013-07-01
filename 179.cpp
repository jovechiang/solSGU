//AC
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

const int Max = 10000 + 10;

char par[Max];
bool Valid()
{
	int o = 0;
	for(int i = 0;par[i];i++)
	{
		if(par[i] == '(')
			o++;
		else
			o--;
		if(o < 0)
			return false;
	}//for
	if(o != 0)
		return false;
	return true;
}//bool Valid()
int main()
{
	scanf("%s",&par);
	int l = strlen(par);
	
	bool change = false;
	int index;
	
	for(int i = l - 1;i >= 1;i--)
	{
		if(par[i - 1] == '(' && par[i] == ')')
		{
			char k = par[i - 1];
			par[i - 1] = par[i];
			par[i] = k;
			if(!Valid())
			{	
				k = par[i - 1];
				par[i - 1] = par[i];
				par[i] = k;
			}//if ! valid()
			else
			{
				index = i;
				change = true;
				break;
			}//if VALID()
		}//if ()
	}//for FIND & CHANGE () --> )(
	if(change)
	{
		for(int i = l - 1;i >= index + 1;i--)
		{
			if(par[i - 1] == ')' && par[i] == '(')
			{
				char k = par[i - 1];
				par[i - 1] = par[i];
				par[i] = k;
			}//if )(
		}//for FIND & CHANGE )( --> ()
		cout<<par<<endl;
	}//if CHANGE()
	else
		cout<<"No solution"<<endl;
	int _;cin>>_;
}

