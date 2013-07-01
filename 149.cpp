#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define Max 10001
#define get(a) scanf("%d",&a)
#define put(a) printf("%d\n",a)

using namespace std;

struct obj
{
	int dist;
	int num;
	void put_value(int nm,int ds)
	{
		num = nm;
		dist = ds;
	}
};
struct Vertex
{
	vector <int> n;
	vector <int> dist;
};
obj add;
Vertex V[Max];
int n;
unsigned j;
int distmx1[Max];
int distmx2[Max];
obj bfs_alaki_findmx1(int i)
{
	bool mark[Max];
	memset(mark,false,sizeof(mark));
	mark[i] = true;
	queue <obj> saf;
	add.put_value(i,0);
	saf.push(add);
	obj node;
	obj mx;
	mx.put_value(i,0);
	while(!saf.empty())
	{
		node = saf.front();
		if(node.dist > mx.dist)
		{
			mx = node;
		}
		saf.pop();
		for(j = 0;j < V[node.num].n.size();j++)
		{
			if(!mark[ V[node.num].n[j] ])
			{
				add.put_value(V[node.num].n[j],V[node.num].dist[j] + node.dist);
				saf.push(add);
				mark[V[node.num].n[j]] = true;
			}
		}
	}//while saf khali nist
	return mx;
}//obj bfs
obj bfs_alaki_findmx2(int i)
{
	bool mark[Max];
	memset(mark,false,sizeof(mark));
	mark[i] = true;
	queue <obj> saf;
	add.put_value(i,0);
	saf.push(add);
	obj node;
	obj mx;
	mx.put_value(i,0);
	while(!saf.empty())
	{
		node = saf.front();
		distmx1[node.num] = node.dist;
		if(node.dist > mx.dist)
		{
			mx = node;
		}
		saf.pop();
		for(j = 0;j < V[node.num].n.size();j++)
		{
			if(!mark[ V[node.num].n[j] ])
			{
				add.put_value(V[node.num].n[j],V[node.num].dist[j] + node.dist);
				saf.push(add);
				mark[V[node.num].n[j]] = true;
			}
		}
	}//while saf khali nist
	return mx;
}//obj bfs
obj bfs_alaki_findmx3(int i)
{
	bool mark[Max];
	memset(mark,false,sizeof(mark));
	mark[i] = true;
	queue <obj> saf;
	add.put_value(i,0);
	saf.push(add);
	obj node;
	obj mx;
	mx.put_value(i,0);
	while(!saf.empty())
	{
		node = saf.front();
		distmx2[node.num] = node.dist;
		if(node.dist > mx.dist)
		{
			mx = node;
		}
		saf.pop();
		for(j = 0;j < V[node.num].n.size();j++)
		{
			if(!mark[ V[node.num].n[j] ])
			{
				add.put_value(V[node.num].n[j],V[node.num].dist[j] + node.dist);
				saf.push(add);
				mark[V[node.num].n[j]] = true;
			}
		}
	}//while saf khali nist
	return mx;
}//obj bfs
int mx1,mx2;
int main()
{
	memset(distmx1,0,sizeof(distmx1));
	memset(distmx2,0,sizeof(distmx2));
	int a,b;
	get(n);
	for(int i = 2;i<=n;i++)
	{
		get(a);get(b);
		V[a].n.push_back(i);
		V[a].dist.push_back(b);
		
		V[i].dist.push_back(b);
		V[i].n.push_back(a);
	}
	add = bfs_alaki_findmx1(1);//find mx1
	mx1 = add.num;
	
	add = bfs_alaki_findmx2(mx1);//fill distmx1 & find mx2
	mx2 = add.num;
	
	bfs_alaki_findmx3(mx2);//fill distmx2
	
	int mxd = add.dist;
	int k;
	for(int i = 1;i<=n;i++)
	{
		k = max(distmx1[i],distmx2[i]);
		printf("%d\n",k);
	}
	get(n);
}
