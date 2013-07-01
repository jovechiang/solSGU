#include <iostream>

using namespace std;

int n,k;
int counter;
int k1,k2,gr1,gc1,axis1;
void put(int p,int x,int row,int gr,int gc,int axis)
{
	if(p == k)
	{
		counter++;
		return ;
	}//p == k
	for(int i = row+1;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			k1 = 1<<(j+i);
			k2 = 1<<(j+3-i);
			if( (!(gr&k1))&& (!(gc&k2))&&(!( axis&(1<<j) ) ) )
			{
				gr1 = gr;
				gc1 = gc;
				axis1 = axis;
				gr1 |= k1;
				gc1 |= k2;
				axis1 |= 1<<j;
				put(p+1,j,i,gr1,gc1,axis1);
			}//tahdid nemishod
		}//for e x
	}//for e y
	return ;
}//void put
int main()
{
	cin>>n>>k;
	//k = n;
	if(k == 0)
	{
		cout<<1<<endl;
		return 0;
	}
	if(k>n)
	{
		cout<<0<<endl;;
		return 0;	
	}
	if(n%2 == 0)
	{
		for(int i = 0;i<n - k + 1;i++)
			for(int j = 0;j<n/2;j++)
			{
				put(1,j,i,1<<(j+i),1<<(j+3-i),1<<j);
			}
		counter *= 2;
	}
	else
	{
		for(int i = 0;i<n - k + 1;i++)
			for(int j = 0;j<n/2;j++)
			{
				put(1,j,i,1<<(j+i),1<<(j+3-i),1<<j);
			}
		cout<<counter<<endl;
		counter *= 2;
		for(int i = 0;i<n - k + 1;i++)
			for(int j = n/2;j<=n/2;j++)
			{
				put(1,j,i,1<<(j+i),1<<(j+3-i),1<<j);
			}
	}
	cout<<counter<<endl;
	return 0;
}
