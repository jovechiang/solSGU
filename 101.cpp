#include <iostream>
using namespace std;
struct D
{
	int right,left;
};
D d[100];
int n;
int ans[100];
char op[100];
int degree[7];
int g[7][7];
bool finder;
bool use[100];
int find(int l,int r,int k)
{
	int k1,k2;
	for(int i = 0;i<n;i++)
	{
		if(use[i])
			continue;
		k1 = d[i].right;
		k2 = d[i].left;
		if(k1 == r&&k2 == l)
		{
			ans[k] = i + 1;
			op[k] = '+';
			k++;
			use[i] = true;
			return i;
		}
		else
			if(k1 == l&&k2 == r)
			{
				ans[k] = i + 1;
				op[k] = '-';
				k++;
				use[i] = true;
				return i;
			}
	}
}
void DFS(int v,int kb,int g1[][7])
{	
	if(finder)
		return;
	if(kb == n)
	{
		finder = true;
		for(int i = 0;i<n;i++)
			cout<<ans[i]<<" "<<op[i]<<endl;;
		return;
	}
	for(int i = 0;i<7;i++)
	{
		if(g1[v][i] > 0)
		{
			int kl1 = find(v,i,kb);
			g1[i][v]--;
			g1[v][i]--;
			DFS(i,kb + 1,g1);
			use[kl1] = false;
			g1[i][v]++;
			g1[v][i]++;
		}
	}
}
int main()
{
	cin>>n;
	int start;
	for(int i = 0;i<n;i++)
	{
		cin>>d[i].left>>d[i].right;
		start = d[i].right;
		g[d[i].left][d[i].right]++;
		g[d[i].right][d[i].left]++;
		degree[d[i].left]++;
		degree[d[i].right]++;
	}
	int oddp = 0;
	for(int i = 0;i<=6;i++)
	{
		if(degree[i]%2)
		{
			start = i;
			oddp++;
		}
	}
	if(oddp > 2)
	{		
		cout<<"No solution"<<endl;
		return 0;
	}
	DFS(start,0,g);
	if(!finder)
	{		
		cout<<"No solution"<<endl;
		return 0;
	}
}
