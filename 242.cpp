//AC
#include <iostream>
#include <cstring>

using namespace std;

const int Max = 200 + 20;

/**********UNIVERS**STU*********/
bool graph[Max * 2][Max];
int m,n;
bool seen[Max];
int Matchboy[Max * 2];
int Matchuni[Max];
bool bpm(int u)
{
	for(int v = 0;v < n;v++)
		if(graph[u][v] && ! seen[v])
		{
			seen[v] = true;
			if( Matchuni[v] == -1 || bpm(Matchuni[v]) )
			{
				Matchboy[u] = v;
				Matchuni[v] = u;
				return true;
			}
		}//if boy number V Can go to UNIve... Number U
	return false;
}//bool bpm
int main()
{
	memset(Matchboy,-1,sizeof(Matchboy));
	memset(Matchuni,-1,sizeof(Matchuni));
	int a,l;
	cin>>n>>m;
	for(int i = 0;i < n;i++)
	{
		cin>>l;
		for(int j = 0;j < l;j++)
		{
			cin>>a;
			graph[a - 1][i] = 1;
			graph[m + a - 1][i] = 1;
		}//read UNIVERS
	}//for read
	int ct = 0;
	for(int i = 0;i < 2 * m;i++)
	{
		memset(seen,0,sizeof(seen));
		if(bpm(i))
			ct++;
	}
	if(ct == 2 * m)
	{
		cout<<"YES"<<endl;
		for(int i = 0;i < m;i++)
			cout<<"2 "<<min(Matchboy[i] + 1,Matchboy[m + i] + 1)<<" "<<max(Matchboy[i] + 1,Matchboy[m + i] + 1)<<endl;
	}
	else
		cout<<"NO"<<endl;
	int _;cin>>_;
}//int main()
