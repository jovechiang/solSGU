#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <algorithm>

using namespace std;

int counter = 0;
int n,m;
bool tahdid[20][20];
bool can_putr(int x,int y);
bool can_putd(int x,int y);


bool can_puto1(int x,int y);//bala chap corner
bool can_puto2(int x,int y);//bala rast corner
bool can_puto3(int x,int y);//payin chap corner
bool can_puto4(int x,int y);//payin rast corner
void print()
{
	cout<<endl;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
			cout<<tahdid[j][i];
		cout<<endl;
	}
	cout<<endl;
}
void make(int x,int y)
{
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
		if(tahdid[j][i] == false)
		{
			goto bad;
		}
	counter++;
	bad:
	if(x > m)
	{
		x = 1;
		y++;
	}
	if(y > n)
		return;
	for(int i = 1;i<y;i++)
		for(int j = 1;j<=m;j++)
		{
			if(tahdid[j][i] == false)
				return ;
		}
//	cout<<"x = "<<x<<" y = "<<y<<endl;
//	print();
//	getch();
	bool can = false;
	for(int i = y;i<=y;i++)
		for(int j = x;j<=m;j++)
		{
			if(tahdid[j][i] == true)
			{
				continue;
			}
			if( can_putr(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j + 1][i] = true;
				make(x + 2,y);
				tahdid[j][i] = false;
				tahdid[j + 1][i] = false;
			}
			if( can_putd(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j][i + 1] = true;
				make(x + 1,y);
				tahdid[j][i] = false;
				tahdid[j][i + 1] = false;
			}
			if( can_puto1(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j + 1][i] = true;
				tahdid[j][i + 1] = true;
				make(x + 2,y);
				tahdid[j][i] = false;
				tahdid[j + 1][i] = false;
				tahdid[j][i + 1] = false;
			}
			if( can_puto2(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j + 1][i] = true;
				tahdid[j + 1][i + 1] = true;
				make(x + 2,y);
				tahdid[j][i] = false;
				tahdid[j + 1][i] = false;
				tahdid[j + 1][i + 1] = false;
			}
			if( can_puto3(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j][i + 1] = true;
				tahdid[j + 1][i + 1] = true;
				make(x + 1,y);
				tahdid[j][i] = false;
				tahdid[j][i + 1] = false;
				tahdid[j + 1][i + 1] = false;
			}
			if( can_puto4(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j][i + 1] = true;
				tahdid[j - 1][i + 1] = true;
				make(x + 1,y);
				tahdid[j][i] = false;
				tahdid[j][i + 1] = false;
				tahdid[j - 1][i + 1] = false;
			}
		}//for e too dar too
	for(int i = y + 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
		{
			if(tahdid[j][i] == true)
				continue;
			if( can_putr(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j + 1][i] = true;
				make(x + 2,y);
				tahdid[j][i] = false;
				tahdid[j + 1][i] = false;
			}
			if( can_putd(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j][i + 1] = true;
				make(x + 1,y);
				tahdid[j][i] = false;
				tahdid[j][i + 1] = false;
			}
			if( can_puto1(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j + 1][i] = true;
				tahdid[j][i + 1] = true;
				make(x + 2,y);
				tahdid[j][i] = false;
				tahdid[j + 1][i] = false;
				tahdid[j][i + 1] = false;
			}
			if( can_puto2(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j + 1][i] = true;
				tahdid[j + 1][i + 1] = true;
				make(x + 2,y);
				tahdid[j][i] = false;
				tahdid[j + 1][i] = false;
				tahdid[j + 1][i + 1] = false;
			}
			if( can_puto3(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j][i + 1] = true;
				tahdid[j + 1][i + 1] = true;
				make(x + 1,y);
				tahdid[j][i] = false;
				tahdid[j][i + 1] = false;
				tahdid[j + 1][i + 1] = false;
			}
			if( can_puto4(j,i))
			{
				can = true;
				tahdid[j][i] = true;
				tahdid[j][i + 1] = true;
				tahdid[j - 1][i + 1] = true;
				make(x + 1,y);
				tahdid[j][i] = false;
				tahdid[j][i + 1] = false;
				tahdid[j - 1][i + 1] = false;
			}
		}//for e too dar too
}//void make
main()
{
	memset(tahdid,true,sizeof(tahdid));
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			tahdid[j][i] = false;
	make(1,1);
	cout<<counter<<endl;
	cin>>n;
}



bool can_putr(int x,int y)
{
	if(tahdid[x][y] == false&&tahdid[x + 1][y] == false)
		return true;
	return false;
}
bool can_putd(int x,int y)
{
	if(tahdid[x][y] == false&&tahdid[x][y + 1] == false)
		return true;
	return false;
}

bool can_puto1(int x,int y)//bala chap corner
{
	if(can_putr(x,y)&&can_putd(x,y))
		return true;
	return false;
}
bool can_puto2(int x,int y)//bala rast corner
{
	if(can_putr(x,y)&&can_putd(x + 1,y))
		return true;
	return false;
}
bool can_puto3(int x,int y)//payin chap corner
{
	if(can_putr(x,y + 1)&&can_putd(x,y))
		return true;
	return false;
}
bool can_puto4(int x,int y)//payin rast corner
{
	if(can_putr(x - 1,y + 1)&&can_putd(x,y))
		return true;
	return false;
}
