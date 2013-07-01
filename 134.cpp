#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int Max = 16 * 1000 + 100;

int mx[Max];
int min_all;
vector <int> comp[Max];
vector <int> N[Max];
int n;
bool mark[Max];

int D(int node)
{
	return N[node].size();
}

int BFS(int start)
{
	cout<<"STSRTING BFS"<<endl;
	queue <int> saf;
	saf.push(start);
	int ct = 0;
	while(!saf.empty())
	{
		int node = saf.front();
		saf.pop();
		mark[node] = true;
		for(int i = 0;i < D(node);i++)
			if(!mark[N[node][i]])
				saf.push(N[node][i]), ct++;
	}
	cout<<"BFS COMPLETED"<<endl;
	return ct + 1;
}

int main()
{
	cin>>n;
	for(int i = 0;i < n - 1;i++)
	{
		int a,b;
		cin >> a >> b;
		N[a - 1].push_back(b - 1);
		N[b - 1].push_back(a - 1);
	}
	
	int delta = 0;
	for(int i = 1;i < n;i++)
		if(D(delta) < D(i))
			delta = i;

	cout << "Delta = " << delta + 1 << endl;

	mark[delta] = true;
	for(int i = 0;i < D(delta);i++)
	{
		cout << "BFSING on " << N[delta][i] + 1 << endl;
		comp[delta].push_back( BFS(N[delta][i]) );
		cout << comp[delta].back() << endl;
		mx[delta] = max(mx[delta], comp[delta].back());
	}	
	min_all = min(min_all, mx[delta]);
	cout << min_all << endl;
}
