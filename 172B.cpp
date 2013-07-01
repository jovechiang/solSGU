#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int ans[5000];
int exam[5000];
bool mat[201][201];
int  color[201];
bool ifdo[201];
int n;
bool finder;
void do_color(int node,int c)
{
	if(finder)
		return;
	ifdo[node] = true;
	color[node] = c;
	for(int i = 1;i<=n;i++)
	{
		if(i == node)
			continue;
		if(mat[i][node])
		{
			if(ifdo[i])
			{
				if(color[i] == c&&finder == false)
				{
					finder = true;
					cout<<"no"<<endl;
					return;
				}
				continue;
			}
			else
			{
				do_color(i,1 - c);
			}
		}//
	}//for e 1 ta n
}//void do_color
int main()
{
	int m,a,b;
	cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		mat[a][b] = true;
		mat[b][a] = true;
	}
	for(int i = 1;i<=n;i++)
	{
		if(ifdo[i] == false)
		{
			do_color(i,0);
		}
	}
	int counter = 0;
	for(int i = 1;i<=n;i++)
	{
		if(color[i] == 0)
		{
			ans[counter] = i;
			counter++;
		}
	}
	if(!finder)
	{
		printf("yes\n%d\n",counter);
		for(int i = 0;i<counter;i++)
			printf("%d ",ans[i]);
	}
	int _;cin>>_;
	return 0;
}
