//AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#define get(a) scanf("%d",&a)
#define Max 101

using namespace std;

bool have_group[Max];
int g[Max][Max];
int len(int i)
{
	return g[i][0];
}
bool same(int i,int j)
{
	if( len(i) != len(j) )
		return false;
	for(int k = 0;k < len(i);k++)
	{
		if(g[i][k] != g[j][k])
			return false;
	}
	return true;
}
bool s[Max][Max];
int n,m;
int r,k;
int out;
bool use[Max];
int main()
{
	get(n);
	get(m);
	for(int i = 1;i <= m;i++)
	{
		get(k);
		for(int j = 0;j < k;j++)
		{
			get(r);
			use[r] = true;
			s[i][r] = true;
			g[r][0] ++;
			g[r][len(r) - 1] = i;
		}//for e student
	}//for e read
	out = n;
	for(int i = 1;i <= n;i++)
	{
		if(! use[i])
			out--;
//		else
//			sort(g[i] + 1,g[i] +  len(i));
	}
	for(int i = 1;i <= n;i++)
	{
		if(have_group[i])
			continue;
		for(int j = i + 1;j <= n;j++)
		{
			if(have_group[i] && have_group[j])
				continue;
			if(use[i] == false || use[j] == false)
				continue;
			if(same(i,j))
			{
				if(have_group[i] == false || have_group[j] == false)
					out--;
				have_group[i] = true;
				have_group[j] = true;
			}
		}
	}
	cout<<out;
}//main
