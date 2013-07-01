//AC
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char start[5010],end[5010];
void out()
{
	cout<<-1<<endl;
	cin>>start;
}
void shift(int s,int e,char c)
{
	for(int i = s;i<e;i++)
		start[i + 1] = start[i];
	start[s] = c;
}
int main()
{
/*	cin>>start;
	shift(0,1,'+');
	cout<<start;
	cin>>start;
	return 0;*/
	scanf("%s%s",start,end);
	int nps = 0,nms = 0,npe = 0,nme = 0;
	int ls,le;
	ls = strlen(start);
	le = strlen(end);
	if(ls != le)
	{
		out();
		return 0;
	}
	int l = ls;
	for(int i = 0;i<l;i++)
	{
		if(start[i] == '+')
			nps++;
		if(start[i] == '-')
			nms++;
		if(end[i] == '+')
			npe++;
		if(end[i] == '-')
			nme++;
	}
	if(nps != npe || nms != nme)
	{
		out();
		return 0;
	}
	int move = 0;
	char c;
	for(int i = 0;i<l;i++)
	{
		if(start[i] != end[i])
		{
			c = end[i];
			for(int j = i + 1;j<l;j++)
			{
				if( start[j] == c)
				{
					shift(i,j,c);
					move += j - i;
					break;
				}//agar peyda shod
			}//mosavi peyda kon
		}//if mosavi naboodand
	}//for e 1 to length
	cout<<move<<endl;
	cin>>start;
}
