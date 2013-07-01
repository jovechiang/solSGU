#include <iostream>
//#include <conio.h>
using namespace std;
class P
{
	public:
		int k,t;
};
P p[100];
int m,n;
int badge[100];
int stack[100][100];
int tans[100];
int bans[100];
int main()
{
	int min,mini;
	cin>>n>>m;
	for(int i = 0;i<n;i++)
	{
		cin>>p[i].k>>p[i].t;
//		p[i].t++;
	}
	min = 0;
	mini = 0;
	int t = 0;
	int counter = 0;
	int c = 0;
	bool b = false;
	
	
	while(1)
	{
		if(p[counter].k == t)
		{
			if(counter < n)
			{			
				for(int i = 0;i<m;i++)
					if(badge[i] == min)
					{
						if(i<mini)
						{
							mini = i;
						}
					}
					else
					if(badge[i] < min)
					{
						mini = i;
						min = badge[i];
					}
				min++;
				stack[mini][badge[mini]] = counter;
				badge[mini]++;
				counter++;
			}			
		}
		t++;
		for(int i = 0;i<m;i++)
		{
			if(badge[i] == 0)
				continue;
			p[stack[i][0]].t--;
			if(p[stack[i][0]].t == 0)
			{
				tans[stack[i][0]] = t;
				bans[stack[i][0]] = i+1;
				for(int j = 0;j<badge[i];j++)
				{
					stack[i][j] = stack[i][j + 1];
				}
				badge[i] -- ;
				//cout<<i + 1<<" "<<t<<endl;
				c++;
				if(c == n)
				{
					for(int i = 0;i<n;i++)
						cout<<bans[i]<<" "<<tans[i]<<endl;
//					getch();
					return 0;
				}
			}
		}
	}//while BIGGGGG : Sina The Best
//	getch();
	return 0;
}
