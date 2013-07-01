#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int Maxn = 1000 + 10;

int a[Maxn][Maxn];
int k[Maxn][Maxn];
int n,m;
int mn;

int main()
{
	cin>>n>>m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			scanf("%d", &a`[i][j]);

/*	for(int i = -1 to n + 1 do
		for j := -1 to m + 1 do
			b[i,j] := 32001;
	
	for j := m downto 1 do
		for i := n downto 0 do
		begin
			if b[i,j] > a[i,j] then b[i,j] := a[i,j];
			if b[i,j] > b[i+1,j] then b[i,j] := b[i+1,j];
			if b[i,j] > b[i-1,j+1] then b[i,j] := b[i-1,j+1];
		end; */

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
			printf("%d ",k[i][j]);
		printf("\n");
	}
	cin>>n;
}
