#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 1000 + 10;
const int Maxm = 1000 + 10;

int n, m;

char map[Maxn][Maxm];
char map2[Maxn][Maxn];
bool mark[Maxn][Maxm];//0 chap, 1 rast, 2 bala, 3 payin

void Print()
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			cerr << map[i][j] << " ";

		cerr << endl;
	}
}

void Go(int x, int y)
{
	if(x > n || x < 1 || y > m || y < 1 || mark[x][y])
		return;

	int ct = 0;

	if(map[x - 1][y] == 'X')
		ct++;

	if(map[x + 1][y] == 'X')
		ct++;

	if(map[x][y - 1] == 'X')
		ct++;

	if(map[x][y + 1] == 'X')
		ct++;

	if(ct >= 2)
		map[x][y] = 'X';

	if(map[x][y] == 'X')
	{
		mark[x][y] = true;
		Go(x - 1, y);
		Go(x + 1, y);
		Go(x, y - 1);
		Go(x, y + 1);
	}


}

int main()
{
	memset(map, '.', sizeof(map));

	scanf("%d %d ", &n, &m);

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
		{
			scanf("%c ", &map[i][j]);

			map2[i][j] = map[i][j];
		}

	//cerr << "DOING : " << endl;

	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(map2[i][j] == 'X')
				Go(i, j);

	int ct = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(map[i][j] == 'X')
				ct++;

	cout << ct << endl;

}
