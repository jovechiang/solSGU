#include <iostream>
#include <vector>
#include <map>

#define Max 50 * 1000 + 10
#define INF (1 << 31) - 1

using namespace std;

int abs(int a)
{
	if(a >= 0)
		return a;
	return -a;
}
struct Node
{
	int num;
	bool leaf;
	int father;
	vector <int>child;
	int sol;
};
int lm;
int list_size;
int list[Max];
Node v[Max];
int n,m;
void make_all(int node)
{
	if(v[node].leaf)
		return;
	int p;
	for(unsigned i = 0;i < v[node].child.size();i++)
	{
		p = v[node].child[i];
		if( v[p].leaf )
		{
			bool find = true;
			for(int ct = 0;ct < list_size;ct++)
			{
				if(list[ct] < v[p].num)
				{
					int a,b = INF;					
					a = abs(v[p].num - list[ct]);
					if(ct > 0)
						b = abs(list[ct - 1] - v[p].num);
					int k = min(a,b);
					lm = min(lm,k);
					find = false;
					for(int k = list_size - 1;k >= ct;k--)
						list[k + 1] = list[k];
					list_size++;
					list[ct] = v[p].num;
					break;
				}
			}//find ja
			if(find)
			{
				int a = INF,k;
				int b;
				if(list_size > 0)
				{
					a = list[list_size - 1];
					b = v[p].num;
					k = abs(a - b);
				}
				else
					k = INF;
				lm = min(lm,k);
				list[list_size] = v[p].num;
				list_size++;
			}
		}//if barg
		else
			make_all(p);
	}//for bache ha
	v[node].sol = lm;
}//void make_all
int main()
{
	lm = INF;	
	cin>>n>>m;
	for(int i = 2;i <= n;i++)
	{
		cin>>v[i].father;
		v[ v[i].father ].child.push_back(i);
		if(i >= n - m + 1)
			v[i].leaf = true;
	}
	for(int i = n - m + 1;i <= n;i++)
		cin>>v[i].num;
	make_all(1);
	for(int i = 1;i < n - m + 1;i++)
		cout<<v[i].sol<<" ";
	cout<<endl;
	cin>>n;
}//main()
