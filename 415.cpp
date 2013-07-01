#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 2000
using namespace std;

int n,x;
bool tavan[20000];
int coin[300];
bool nes[300];
int ct = 0;
main()
{
	cin>>n>>x;
	for(int i = 0;i<n;i++)
		cin>>coin[i];
	for(int j = 0;j<n;j++)
	{
		memset(tavan,false,sizeof(tavan));
		tavan[0] = 1;
		for(int i = 0;i<n;i++)
		{
			if(i == j)
				continue;
			for(int k = x;k>=coin[i];k--)
			{
				if(tavan[k - coin[i]])
					tavan[k] = true;
			}
		}//for e sekkeha
		if(tavan[x] == 0)
		{
			ct++;
			nes[j] = 1;
		}
	}//for e hazf sekke
	cout<<ct<<endl;
	for(int i = 0;i<n;i++)
		if(nes[i])
			cout<<coin[i]<<" ";
	cin>>n;
}
