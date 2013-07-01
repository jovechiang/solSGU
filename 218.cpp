#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int Max = 500 + 20;

int graph[Max][Max];
bool seen[Max];
int user[Max];
int comp[Max];

int uans[Max];

int n;

int l,m,h;

bool bpm(int c)
{
	for(int u = 0;u < n;u++)
		if( graph[c][u] <= m && !seen[u] )
		{
			seen[u] = true;
			if( comp[u] == -1 || bpm( comp[u] ) )
			{
				user[c] = u;
				comp[u] = c;
				return true;
			}
		}
	return false;
}

bool complete_matching()
{
	memset(user,-1,sizeof(user));
	memset(comp,-1,sizeof(comp));
	int ct = 0;
	for(int c = 0;c < n;c++)
	{
		memset(seen,false,sizeof(seen));
		if(bpm(c))
			ct++;
	}
	if(ct == n)
		return true;
	return false;
}//bool have matching

int main()
{
	int a;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d",&a),graph[i][j] = a,l = min(l,a),h = max(h,a);
	h++;
	while(h - l >= 1)
	{
		m = (h + l) / 2;
		if(complete_matching())
		{
			for(int i = 0;i < n;i++)
				uans[i] = user[i];
			h = m;
		}
		else
			l = m + 1;
	}//while ke baraye BINARY search estefade mishe

	int max_w = -2000 * 1000;
	for(int j = 0;j < n;j++)
		if(graph[j][uans[j]] > max_w)
			max_w = graph[j][uans[j]];
	
	printf("%d\n",max_w);
	
	for(int j = 0;j < n;j++)
		printf("%d %d\n",j + 1,uans[j] + 1);

}//int main
