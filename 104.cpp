#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int m[100][100];
int ans[100];
int n,v;
int mx = -5500;
int ans_max[100];
int find_max(int row,int k)
{
	int max = -51;
	int maxi = k;
	for(int i = k + 1;i<=v - n + row;i++)
	{
		if(m[i][row] > max)
		{
			max = m[i][row];
			maxi = i;
		}
	}
	return maxi;
}
bool finder = false;
void make(int row,int k,int sum)
{
	if(finder)
		return;
	if(row == n)
	{
		if(sum > mx)
		{
			finder = true;
			mx = sum;
			for(int j = 0;j<n;j++)
				ans_max[j] = ans[j];
		}
		return ;
	}
	int i = find_max(row,k);
	ans[row] = i;
	sum += m[i][row];
	make(row + 1,i,sum);
}
int main()
{
	cin>>n>>v;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<v;j++)
			scanf("%d",&m[j][i]);
	make(0,-1,0);
	printf("%d\n",mx);
	for(int j = 0;j<n;j++)
		printf("%d ",ans_max[j] + 1);
	getch();
	return 0;
}
