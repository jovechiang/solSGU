#include <iostream>
#include <cmath>
#include <cstdio>
#define get(a) scanf("%d",&a)
#define put(a) printf("%d",a)

using namespace std;

int n;
int length;
int k[1000010];
int main()
{
    int counter = 0;
    int g1,g2,g3;
	int d = 0,g = 0;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		get(length);
		get(k[0]);
		g = d = 0;
		for(int j = 1;j<length;j++)
		{
			get(k[j]);
		}
		///////////////////////////////////////////////////////////////////////////////////
		for(int c = 0;c<length;c++)
		{
			counter = c;
			if(k[counter+1]>k[counter])
			{
				g1 = counter;
				while(k[counter+1]>k[counter])
				{
					counter++;
					if(counter == length)
					{
						counter--;
						break;
					}
				}
				g2 = counter;
				while(k[counter+1]<k[counter])
				{
					counter++;
					if(counter == length)
					{
						counter--;
						break;
					}
                }
				g3 = counter;
				g1 = min(g2 - g1,g3 - g2);
				if(d<g1)
				{
                	d = g1;
				}
				c = g3 - 1;
			}
		}// for c to length*/
       //////////////////////////////////////////////////////////
		for(int c = 0;c<length;c++)
		{
//			cout<<c<<endl;
			counter = c;
			if(k[counter+1]<k[counter])
			{
				g1 = counter;
				while(k[counter+1]<k[counter])
				{
					counter++;
					if(counter == length)
					{
						break;
					}
				}
				g2 = counter;
				while(k[counter+1]>k[counter])
				{
					counter++;
					if(counter == length)
					{
						break;
					}
                }
				g3 = counter;
				g1 = min(g2 - g1,g3 - g2);
				if(d<g1)
				{
                	g = g1;
				}
				c = g3 - 1;
			}
		}// for c to length*/
       /////////////////////////////////////////////////////////////////////////////
		cout<<d<<" "<<g<<endl;
	}//for 1 to n
	get(g);
}//main
