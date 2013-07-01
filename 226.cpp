//AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define Max 220
#define get(a) scanf("%d",&a)
#define put(a) printf("%d\n",a)
using namespace std;

struct obj
{
	int dist;
	int color;
	int num;
	void put_value(int nm,int ds,int cl)
	{
		num = nm;
		dist = ds;
		color = cl;
	}
};
bool m[Max][Max][4];
bool mark[Max][4];
obj add;
int n,e;
int bfs()
{
	queue <obj> saf;
	add.put_value(1,0,-1);
	saf.push(add);
	obj node;
	while(!saf.empty())
	{		
		node = saf.front();
		saf.pop();
		if(node.num == n)
		{
			return node.dist;
		}
		for(int i = 1;i<=n;i++)
		{
			for(int c = 1;c<=3;c++)
			{
				if(mark[i][c])
					continue;
				if(m[node.num][i][c])
				{
					if(c == node.color)
						continue;
					add.put_value(i,node.dist + 1,c);
					saf.push(add);
					mark[i][c] = true;
				}
			}
		}//for e 1 to n
	}//while saf khali nist
	
	return -1;
}//int bfs
main()
{
	int a,b,c;
	get(n);get(e);
	for(int i = 1;i<=e;i++)
	{
		get(a);get(b);get(c);
		m[a][b][c] = 1;
	}
	cout<<bfs();
	get(n);
}
