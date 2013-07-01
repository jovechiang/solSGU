#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#define ULL unsigned long long int
#define get(a) scanf("%d",&a)
#define Max 210

#define rast 0
#define payin 1
#define chap 2
#define bala 3
using namespace std;

struct Point
{
	int x,y;
	Point(){}
	Point(int x1,int y1): x(x1) , y(y1)
	{}
	void operator += (Point b)
	{
		x += b.x;
		y += b.y;
	}
	bool operator == (Point p)
	{
		if(x == p.x && y == p.y)
			return true;
		return false;
	}
};
Point P(int x,int y)
{
	Point c(x,y);
	return c;
}
Point dir[5];
int n,m;
bool valid(Point p)
{
	if(p.x >= 1 && p.x <= m && p.y >=1 && p.y <= n)
		return true;
	return false;
}
Point pos(0,0);
int jahat = rast;
char b1[Max][Max];
int b[Max][Max];
bool go[Max][Max];
Point ne[Max][Max][10];
int len[Max][Max];
void change_dir(char c)
{
	if(c == 'R')
	{
		jahat++;
		jahat %= 4;
	}
	else
	{
		jahat--;
		if(jahat < 0)
			jahat = 3;
	}
}
char s[1000];
/*
3 3
123
456
789
MMMRRMMMLMMMLMMMLMLM
*/
char * J(int jahat)
{
	if(jahat == rast)
		return "rast";
	if(jahat == chap)
		return "chap";
	if(jahat == payin)
		return "payin";
	if(jahat == bala)
		return "bala";
}
int main()
{
	dir[rast ] = P( 1, 0);
	dir[chap ] = P(-1, 0);
	dir[bala ] = P( 0,-1);
	dir[payin] = P( 0, 1);
	Point p;
	get(n);
	get(m);
	for(int i = 0;i <= n;i++)
	{
		for(int j = 0;j <= m;j++)
		{
			//halat 1 start
				p.x = j;
				p.y = i;
				p.x ++;
				p.y ++;
				if(valid(p))
				{
					ne[j][i][len[j][i]] = p;
					len[j][i]++;
				}				
			//halat 1 end
			//halat 2 start
				p.x = j;
				p.y = i;
				if(valid(p))
				{
					ne[j][i][len[j][i]] = p;
					len[j][i]++;
				}				
			//halat 2 end
			//halat 3 start
				p.x = j;
				p.y = i;
				p.x ++;
				if(valid(p))
				{
					ne[j][i][len[j][i]] = p;
					len[j][i]++;
				}				
			//halat 3 end
			//halat 4 start
				p.x = j;
				p.y = i;
				p.y ++;
				if(valid(p))
				{
					ne[j][i][len[j][i]] = p;
					len[j][i]++;
				}				
			//halat 4 end
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin>>b1[j][i];
			b[j][i] = b1[j][i] - '0';
		}
	}
	cin>>s;
	int l = strlen(s);
	int x1,y1;
	int x2,y2;
	int sum = 0;
	for(int i = 0;i < l;i++)
	{
		//cout<<endl;
//		cout<<endl;
//		cout<<i<<" :"<<endl;
//		cout<<"jahat = "<<J(jahat)<<endl;
//		cout<<pos.x<<" "<<pos.y<<endl;
//		getch();
		if(s[i] == 'M')
		{
//			cout<<'M'<<endl;
			x1 = pos.x;
			y1 = pos.y;
			pos += dir[jahat];
			x2 = pos.x;
			y2 = pos.y;
			for(int k1 = 0;k1 < len[x1][y1];k1++)
				for(int k2 = 0;k2 < len[x2][y2];k2++)
				{
					if(ne[x1][y1][k1] == ne[x2][y2][k2])
					{
						p = ne[x1][y1][k1];
						if(go[p.x][p.y])
						{
							sum += b[p.x][p.y] / 2;
//							cout<<i<<" : sum += "<<b[p.x][p.y]<<" / 2 = "<<b[p.x][p.y]/2<<endl;;
						}
						else
						{
							sum += b[p.x][p.y];
							go[p.x][p.y] = true;
//							cout<<i<<" : sum += "<<b[p.x][p.y];
						}
//						cout<<endl;
					}
				}
		}//go ahead
		else
		{
			change_dir(s[i]);
		}
	}
//	cout<<l<<endl;
	cout<<sum<<endl;;
	cin>>n;
}
