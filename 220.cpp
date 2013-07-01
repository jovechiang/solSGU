#include <iostream>

using namespace std;

const int Max = 50 + 10;
const int Black = 1;
const int White = 0;

int n;

bool valid_pos(int x,int y)
{
	if(x > n || x < 1 || y > n || y < 1)
		return false;
	return true;
}//bool valid_pos*/

inline int X(int x,int y)
{
	return ( n - 1 - x + y ) / 2 + 1;
}

inline int Y(int x,int y)
{
	return (x + y) / 2;
}

int X_of_satr(int k,int mode)
{
	if(k <= n / 2)
		return 1;
	if(mode == Black)
	{
		if(n % 2 == 0)
		{
			return (k - n / 2) * 2 + 1;
		}//if n zoj
		if(n % 2 == 1)
		{
			return (k - n / 2) * 2;
		}//if n fard
	}//if siah
	if(mode == White)
	{
		if(n % 2 == 0)
		{
			return (k - n / 2) * 2;
		}//if n zoj
		if(n % 2 == 1)
		{
			if(k <= n / 2 + 1)
				return 1;
			return (k - n / 2 - 1) * 2 + 1;
		}//if n fard
	}//if siah
}//int avval satr finder

int Y_of_satr(int k,int mode)
{
	if(mode == Black)
	{
		if(n % 2 == 0)
		{
			if(k <= n / 2)
				return k * 2;
			return n;
		}//if n zoj
		if(n % 2 == 1)
		{
			if(k <= n / 2)
				return k * 2;
			return n;
		}//if n fard
	}//if siah
	if(mode == White)
	{
		if(n % 2 == 0)
		{
			if(k <= n / 2)
				return k * 2 - 1;
			return n;
		}//if n zoj
		if(n % 2 == 1)
		{
			if(k <= n / 2)
				return k * 2 - 1;
			return n;
		}//if n fard
	}//if siah
}//int avval satr finder

int x,y;
bool sootoon[Max];
bool satr[Max];
unsigned long long int counter = 0;

int mode;
void put(int p,int f)
{
	if(p == f)
	{
		counter++;
		return;
	}//if all placed
	for(int i = Y(x,y) + 1;i <= n;i++)
		for(int jx = X_of_satr(i,mode),jy = Y_of_satr(i,mode);jx <= n;jx++,jy--)
		{
			if(!valid_pos(jx,jy))
				continue;
			
			int soot = X(jx,jy);
			int sat  = i;
			if(sootoon[soot] || satr[sat])
				continue;
			satr[sat] = 1;
			sootoon[soot] = 1;
			int x1 = x;
			int y1 = y;
			x = jx;
			y = jy;
			put(p + 1,f);
			x = x1;
			y = y1;
			sootoon[soot] = 0;
			satr[sat] = 0;
		}//for e too dar too
/*	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
		{
			if( (j + i) % 2 != mode || Y(j,i) <= Y(x,y))
				continue;
			int soot = X(j,i);
			int sat  = Y(j,i);
			if(sootoon[soot] || satr[sat])
				continue;
			satr[sat] = 1;
			sootoon[soot] = 1;
			int x1 = x;
			int y1 = y;
			x = j;
			y = i;
			put(p + 1,f);
			x = x1;
			y = y1;
			sootoon[soot] = 0;
			satr[sat] = 0;
		}//for e too dar too*/
}//void put
/////////////////////////K//
int help_to_speed_zojha[1000];
int main()
{
	int m_k;
//	while(cin>>n>>m_k)
	{
	for(int i = 0;i < Max;i++)
		help_to_speed_zojha[i] = -1;
	cin>>n>>m_k;
	unsigned long long int sum = 0;
	for(int kw = 0;kw <= m_k;kw++)
	{
		int kb = m_k - kw;
		int ctw,ctb;
		//20014112
		if(help_to_speed_zojha[kb] == -1 || n % 2)
//		if(1)
		{
			if(kb == 0)
				ctb = 1;
			else
			if(kb > n)
				ctb = 0;
			else
			{
				/********BLACK************************************/
				mode = Black;
				for(int i = 1;i <= n;i++)
					for(int j = 1;j <= n;j++)
					{
						if( (j + i) % 2 == 0)//white
							continue;
						sootoon[X(j,i)] = 1;
						satr   [Y(j,i)] = 1;
						x = j;
						y = i;
						put(1,kb);
						sootoon[X(j,i)] = 0;
						satr   [Y(j,i)] = 0;
					}
				/********BLACK************************************/
				ctb = counter;
			}
			help_to_speed_zojha[kb] = ctb;
		}
		else
			ctb = help_to_speed_zojha[kb];
		cout<<"BLACK : "<<kb<<" = "<<ctb<<endl;
		counter = 0;
		if(help_to_speed_zojha[kw] == -1 || n % 2)
	//	if(1)
		{
			if(kw == 0)
				ctw = 1;
			else
			if(kw > n)
				ctb = 0;
			else
			{
				/********WHITE************************************/
				mode = White;
				for(int i = 1;i <= n;i++)
					for(int j = 1;j <= n;j++)
					{
						if( (j + i) % 2 == 1)//BLACK
							continue;
						satr   [Y(j,i)] = 1;
						sootoon[X(j,i)] = 1;
						x = j;
						y = i;
						put(1,kw);
						satr   [Y(j,i)] = 0;
						sootoon[X(j,i)] = 0;
					}
				/********WHITE************************************/
				ctw = counter;
			}
			help_to_speed_zojha[kw] = ctw;
		}
		else
			ctw = help_to_speed_zojha[kw];
		cout<<"WHITE : "<<kw<<" = "<<ctw<<endl<<endl<<endl;
		counter = 0;
		
		sum += ctw * ctb;
	}//kw
	cout<<sum<<endl;
}
	cin>>n;
	
	return 0;
}
