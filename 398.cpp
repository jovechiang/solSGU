#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

class human
{
	public:
		int friendsm[100];
		int f[100];
		int friendsnum;
};
human m[100];
int main()
{
	int n,x;
	cin>>n>>x;
	for(int i = 0;i<n;i++)
	{
		cin>>m[i].friendsnum;
		for(int j = 0;j<m[i].friendsnum;j++)
		{
			cin>>m[i].f[j];
			m[i].f[j]--;
			m[i].friendsm[m[i].f[j]] = 1;
		}
	}
	x--;
	m[x].friendsm[x] = 1;
	for(int i = 0;i<m[x].friendsnum;i++)
	{
		for(int j = 0;j<m[m[x].f[i]].friendsnum;j++)
		{
//			cout<<m [  m[x].f[i]  ]  .f[j]<<endl;
//			getch();
			if(m[x].friendsm[ m [  m[x].f[i]  ]  .f[j] ]   == 0)
				m[x].friendsm[ m[m[x].f[i]].f[j] ] = 2;
		}
	}
	int ans[100];
	int counter = 0;
	for(int i = 0;i<n;i++)
	{
		if(m[x].friendsm[i] == 2)
		{
			ans[counter] = i;
			counter++;
		}
	}
	cout<<counter<<endl;
	for(int i = 0;i<counter -1;i++)
		for(int j = 0;j<counter -1;j++)
		{
			if(ans[j]>ans[j+1])
			{
				int k = ans[j];
				ans[j] = ans[j+1];
				ans[j+1] = k;
			}
		}
	for(int i = 0;i<counter;i++)
	{
		cout<<ans[i] + 1<<endl;
	}
	getch();
	return 0;
}
