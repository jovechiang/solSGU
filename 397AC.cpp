#include <iostream>
#include <string.h>
#include <conio.h>
#include <list>
#include <stdio.h>
using namespace std;

list<char> s;
list<char>::iterator i;
char c[1000000];
int main()
{
	gets(c);
	int len = strlen(c);
	
	i = s.begin();
	int counter = 0;
	for(int j = 0;j<len;j++)
	{
		if(c[j] == 'L')
		{
			if(counter > 0)
			{
				i--;
				counter--;
			}
		}
		else
		if(c[j] == 'R')
		{
			if(i != s.end() )
			{
				counter++;
				i++;
			}
		}
		else
		{
			counter++;
			s.insert(i,c[j]);
		}
	}
	
	for(i = s.begin();i != s.end();i++)
	{
		cout<<*i;
	}
	cout<<endl;
	getch();
	return 0;
}
