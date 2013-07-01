//AC
#include <iostream>
#include <cstdio>
#include <cstring>
#define Max 720

using namespace std;

int h,w;
char s[Max][Max];
bool pal(int xs,int ys,int pl)
{
	//check satr
	for(int y = ys;y <= ys + pl - 1;y++)
		for(int x = xs;x <= xs + pl/2 - 1;x++)
		{
			if(s[y][x] != s[y][2 * xs + pl - x - 1])
			{
				return false;
			}
		}
	//check satr
	//check sootoon
	for(int x = xs;x <= xs + pl - 1;x++)
		for(int y = ys;y <= ys + pl/2 - 1;y++)
		{
			if(s[y][x] != s[2 * ys + pl - y - 1][x])
			{
				return false;
			}
		}
	//check sootoon
	return true;
}
int xstr,ystr,palmax;
int xstr2,ystr2,palmax2;
bool do_[Max];
int main()
{
	scanf("%d%d",&h,&w);
	for(int i = 1;i <= h;i++)
		scanf("%s",&s[i]);
	int start = 1,end,pl,p;
	end = min(h,w);
	end /= 2;
	end ++;
	bool find;
	while(1)
	{
		find = false;		
		p = (start + end)/2;
		pl = p * 2;
		if(do_[pl])
			break;
		do_[pl] = true;
		for(int i = 1;i <= h - pl + 1;i++)
			for(int j = 0;j < w - pl + 1;j++)
			{
				if( pal(j,i,pl) )
				{
					xstr = j + 1;
					ystr = i;
					palmax = pl - 1;
					find = true;
					goto baad;
				}
			}
		baad:
		if(find)
			start = p;			
		else
			end = p;
	}
	int max = palmax;
	palmax = 0;
	start = 1;
	end = min(h,w) + 1;
	end /= 2;
	end ++;
	memset(do_,false,sizeof(do_));
	while(1)
	{
		find = false;		
		p = (start + end)/2;
		pl = p * 2 - 1;
		if(do_[pl])
			break;
		do_[pl] = true;
		if(pl < max)
		{
			find = true;
			goto baad2;
		}
		for(int i = 1;i <= h - pl + 1;i++)
			for(int j = 0;j < w - pl + 1;j++)
			{
				if( pal(j,i,pl) )
				{
					xstr2 = j + 1;
					ystr2 = i;
					palmax = pl - 1;
					find = true;
					goto baad2;
				}
			}
		baad2:
		if(find)
			start = p;			
		else
			end = p;
	}
	if(max == 0&& palmax == 0)
		cout<<"1 1 1 1"<<endl;
	else
	if(palmax <= max)
		cout<<ystr<<" "<<xstr<<" "<<ystr + max<<" "<<xstr + max<<endl;
	else
		cout<<ystr2<<" "<<xstr2<<" "<<ystr2 + palmax<<" "<<xstr2 + palmax<<endl;
	cin>>h;
	return 0;
}
