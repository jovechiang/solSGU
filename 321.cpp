#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int Maxn = 200 * 1000 + 10;

int al[Maxn];
int alchild[Maxn];
int dist[Maxn];

int n;

bool mark[Maxn];

struct Edge
{
	int number;
	int to;
	int mode;
};


vector <Edge> E[Maxn];
vector <int> ans;

int dfs1(int v)
{
	mark[v] = true;
	int mx = 0;

	for(int i = 0;i < (int)E[v].size();i++)
	{
		int h = E[v][i].to;

		if(!mark[h])
		{
			dist[h] = dist[v] + 1;
			al[h] = al[v];

			if(E[v][i].mode == 0)
				al[h]++;

			dfs1(h);

			mx = max(mx, alchild[h]);
		}
	}

	mx = max(mx, al[v] - dist[v] / 2);
	alchild[v] = mx;
}

void dfs2(int v, int num)
{
	mark[v] = true;

	for(int i = 0;i < (int)E[v].size();i++)
	{
		int h = E[v][i].to;

		if(!mark[h])
		{
			if(alchild[h] - num > 0)
			{
				if(E[v][i].mode == 0)
				{
					ans.push_back(E[v][i].number);
					dfs2(h, num + 1);
				}
				else
					dfs2(h, num);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);

	for(int i = 0;i < n - 1;i++)
	{
		int a, b;
		scanf("%d %d", &b, &a);
		a--, b--;

		Edge T;
		
		char s[20];
		scanf("%s", s);
		if(s[0] == 'a')
		{
			scanf("%s", s);
			T.mode = 0;
		}
		else
			T.mode = 1;


		T.number = i + 1;
		T.to = b;
		E[a].push_back(T);
	}

	dfs1(0);

	/*for(int i = 0;i < n;i++)
	{
		cerr << i + 1 << " al = " << al[i] << " alchild = " << alchild[i] << endl;
	}*/

	memset(mark, false, sizeof(mark));

	dfs2(0, 0);

	cout << ans.size() << endl;

	for(int i = 0;i < (int)ans.size();i++)
		cout << ans[i] << " ";

	cout << endl;
	return 0;
}
