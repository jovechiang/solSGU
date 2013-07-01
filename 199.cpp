//TLE
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

#define get(a) scanf("%d",&a)
#define put(a) printf("%d ",a)

using namespace std;

const int Max = 100 * 1000 + 10;

struct Man
{
	int index;
	int s,b;
	bool operator < (Man m)const
	{
		if(s < m.s)
			return true;
		if(s == m.s)
			return b <= m.b;
		return false;
	}//bool < 
}m[Max];//Man
int n;
int f[Max];
int par[Max];
vector<int> ans;
bool yal_darad(int i,int j)
{
	if(m[i].b < m[j].b && m[i].s < m[j].s)
		return true;
	return false;
}//bool yal_darad()
int main()
{
	get(n);
	for(int i = 0;i < n;i++)
	{
		get(m[i].s);
		get(m[i].b);
		m[i].index = i;
	}

	sort(m,m + n);	
	
/*	cout<<"safafsdfads"<<endl;
	for(int i = 0;i < n;i++)
	{
		cout<<m[i].s<<" "<<m[i].b<<endl;;
	}
	cout<<"safafsdfads"<<endl;*/
	
//	int a,b;
//	while(cin>>a>>b)
//		cout<<yal_darad(a,b)<<endl;
//	return 0;
	

	
	memset(f,-1,sizeof(f));
	memset(par,-1,sizeof(f));
	
	for(int i = 0;i < n;i++)
		for(int j = i - 1;j >= 0;j--)
			if( yal_darad(j,i) )
			{
				//cout<<"s : "<<j<<" "<<i<<endl;
				if(f[j] + 1 < f[i])
					continue;
				f[i] = f[j] + 1;
				par[i] = j;
			}
	int mx = -2,mxi;
	for(int i = 0;i < n;i++)
		if(mx < f[i])
			mx = f[i],mxi = i;
	
//	cout<<mxi<<endl;
		
	ans.push_back(m[mxi].index + 1);
	mxi = par[mxi];
	while(par[mxi] != -1)
	{
		ans.push_back(m[mxi].index + 1);
		mxi = par[mxi];
	}
	ans.push_back(m[mxi].index + 1);
	if(mx == -1)
	{
		cout<<1<<endl;
		cout<<1<<endl;
	}
	else
	{
		put(mx + 2);
		cout<<endl;
		sort(ans.begin(),ans.end());
		for(int i = 0;i < mx + 2;i++)
			put(ans[i]);
		cout<<endl;
	}
	int _;cin>>_;
}//main
