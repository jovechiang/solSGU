#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int field[201][201];
int x[4100],y[4100];
int counter,m,n,k,ox,oy;
bool find_1()
{
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			if( field[j][i] == 1)
			{
				ox = j;
				oy = i;
				field[ox][oy] = 0;
				return true;
			}
	return false;
}
void print_sol();
int F(int x,int y)
{
	if(x < 0 || x >= m || y < 0 || y >= n)
		return 0;
	return field[x][y];
}
int main()
{
	cin>>n>>m;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			cin>>field[j][i];
	k = m * n;
	
	while(k > 0)
	{
		if( find_1() )
		{
			k--;
			x[counter] = ox + 1,y[counter] = oy + 1,counter++;
			if( F(ox + 1,oy) )
				if(field[ox + 1][oy] > 0)
					field[ox + 1][oy]--;
				
			if( F(ox - 1,oy) )
				if( field[ox - 1][oy] > 0 )
					field[ox - 1][oy]--;
				
			if( F(ox,oy + 1) )
				if(field[ox][oy + 1] > 0)
					field[ox][oy + 1]--;
				
			if( F(ox,oy - 1) )
				if(field[ox][oy - 1] > 0)
					field[ox][oy - 1]--;
		}
		else
		{
			cout<<"No solution"<<endl;
			cin>>k;
			return 0;
		}
	}//Big while
	print_sol();
	cin>>n;
}
void print_sol()
{
	for(int i = counter - 1;i >= 0;i--)
		cout<<y[i]<<" "<<x[i]<<endl;
}
