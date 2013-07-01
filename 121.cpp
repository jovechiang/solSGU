#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int Max = 100 + 20;

int n;
/******NEIGHBOR******/
vector <int> N[Max];
int color[Max][Max];
/******NEIGHBOR******/

/******MOALLEFE******/
int moallefe_num;
int hamband[Max];
vector <int> moal[Max];
void bfs(int start)
{
	moallefe_num++;
	queue <int> saf;
	bool mark[Max];
	memset(mark,false,sizeof(mark));
	saf.push(start);
	while(!saf.empty())
	{
		int node = saf.back();
		moal[moallefe_num].push_back(node);
		hamband[node] = moallefe_num;
		saf.pop();
		mark[node] = true;
		for(int i = 0;i < N[node].size();i++)
			if(!mark[N[node][i]])
				saf.push(mark[N[node][i]]);
	}//while !saf == empty
}//void bfs
/******MOALLEFE******/
bool CNF(int i);
int main()
{
	int read;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>read;
		while(read != 0)
		{
			N[i].push_back(read);
			cin>>read;
		}
	}//for
	for(int i = 1;i <= n;i++)
		if( ! hamband[i] )
			bfs(i);
	for(int i = 1;i <= n;i++)
		cout<<i<<" : "<<hamband[i]<<endl;
	for(int i = 1;i <= moallefe_num;i++)
		if(moal[i].size() % 2 == 1)
		{
			if( CNF(i) )
			{
				cout<<"No solution"<<endl;
				cin>>n;
				return 0;
			}
		}//if fard ozvi bood
	cout<<"Have solution"<<endl;
	cin>>n;
}//int main
/*
5
5 2 0
1 3 0
2 4 0
3 5 0
4 1 0
*/
bool CNF(int i)
{
	for(int j = 0;j < moal[i].size();j++)
	{
		cout<<"Daraje["<<moal[i][j]<<"] = "<<N[moal[i][j]].size()<<endl;
		if(N[moal[i][j]].size() != 2)
			return false;
	}
	return true;
}
