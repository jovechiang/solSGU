#include <iostream>
#include <conio.h>

using namespace std;

int n,m;
int c;
char ans[101];
int matrix [10];
void put(int k,int x,int y)
{
	if(k == m*n - 1)
	{
		for(int i = 0;i<k;i++)
			cout<<ans[i];
		cout<<endl;
		return;
	}//solution
	if(y < n-1)
	{
		c = 1<<(x);
		if(!(matrix[y+1] & c))
		{
			ans[k] = 'D';
			matrix[y+1] |= c;
			put(k+1,x,y+1);
			return;
		}
	}
	if(x > 0)
	{
		c = 1<<(x - 1);
		if(!(matrix[y]&c))
		{
			ans[k] = 'L';
			matrix[y] |= c;
			put(k+1,x - 1,y);
			return;
		}
	}
	if(y > 0)
	{
		c = 1<<(x);
		if(!(matrix[y-1]&c))
		{
			ans[k] = 'U';
			matrix[y-1] |= c;
			put(k+1,x,y-1);
			return;
		}
	}
	if(x < m-1)
	{
		c = 1<<(x+1);
		if(!(matrix[y]&c))
		{
			ans[k] = 'R';
			matrix[y] |= c;
			put(k+1,x+1,y);
			return;
		}
	}
	for(int i = 0;i<k;i++)
		cout<<ans[i];
	cout<<endl;
	return;
}
int main()
{
	cin>>n>>m;
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	c = 1<<b;
	matrix[a] |= c;
	put(0,b,a);
	getch();
	return 0;
}
