//AC
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

const int Max = 100 + 10;
int n,m;
int graph[Max][Max];
struct node
{
	int in_degree;
	int out_degree;
	node()
	{
		out_degree = 0,in_degree = 0;
	}
}V[Max];
stack <int> Sources;
vector <int> permutation;
int ans[Max];
bool Topological_Sort()
{
	while(!Sources.empty())
	{
		int node = Sources.top();
		permutation.push_back(node);
		Sources.pop();
		for(int i = 1;i <= n;i++)
			if(graph[node][i])
			{
				graph[node][i] = 0;
				V[node].out_degree--;
				V[i].in_degree--;
				if(V[i].in_degree == 0)
					Sources.push(i);
				m--;//num_of Yals
			}//if have yal
	}//while ! have source
	if(m == 0)
		return true;
	else
		return false;
}//bool Topological_Sort()
int main()
{
	int q;
	cin>>n>>q;
	for(int i = 0;i < q;i++)
	{
		int a,b;
		cin>>a>>b;
		if(!graph[b][a])
		{
			m++;
			graph[b][a] = 1;
			V[b].out_degree++;
			V[a].in_degree++;
		}
	}
	for(int i = 1;i <= n;i++)
		if(V[i].in_degree == 0)
			Sources.push(i);
	if(Topological_Sort())
	{
		for(int i = 0;i < n;i++)
			ans[permutation[i]] = n - i;
		for(int i = 1;i <= n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"No solution"<<endl;
	int _;cin>>_;
}
