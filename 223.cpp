#include <iostream>

using namespace std;

int n,k,counter;

int row1[100];
int ct;
void put(int c,int x1,int y1)
{
	if(c == k)
	{
		counter++;
		return;
	}
	if( ( (n - 1 - x1 - 1) / 2 + 1 + (n - 1 - y1) * n / 2 + 1  ) + c < k )
		return;

	int x = x1;
	int y = y1;
	int row[100];
	int shift;
	int i = y;
	for(int j = x + 1;j<n;j++)
	{
		shift = 1<<j;
		if( !(row1[i] & shift) )
		{
			for(int p = 0;p<=n;p++)
				row[p] = row1[p];
			row1[i] |= shift;
			row1[i+1] |= shift;
			row1[i+1] |= shift*2;
			row1[i+1] |= shift/2;
			row1[i-1] |= shift;
			row1[i-1] |= shift*2;
			row1[i-1] |= shift/2;
			row1[i] |= shift/2;
			row1[i] |= shift*2;
			put(c+1,j,i);
			for(int p = 0;p<=n;p++)
				row1[p] = row[p];
		}
	}
	for(int i = y+1;i<n;i++)
		for(int j = 0;j<n;j++)
		{
			shift = 1<<j;
			if( !(row1[i] & shift) )
			{
				for(int p = 0;p<=n;p++)
					row[p] = row1[p];
				row1[i] |= shift;
				row1[i+1] |= shift;
				row1[i+1] |= shift*2;
				row1[i+1] |= shift/2;
				row1[i-1] |= shift;
				row1[i-1] |= shift*2;
				row1[i-1] |= shift/2;
				row1[i] |= shift/2;
				row1[i] |= shift*2;
				put(c+1,j,i);
				for(int p = 0;p<=n;p++)
					row1[p] = row[p];
			}
		}
}
int main()
{
	counter = 0;
	cin>>n>>k;
	if(k == 0)
	{
		cout<<1<<endl;
		return 0;
	}
	if(k > 2 * n)
	{
		cout<<0<<endl;
		return 0;
	}
	int shift;
 	if(n % 2 == 0)
	{
		for(int i = 0;i < n / 2;i++)
			for(int j = 0;j < n;j++)
			{
				shift = 1<<j;
				row1[i+1] |= shift;
				row1[i+1] |= shift*2;
				row1[i+1] |= shift/2;
				row1[i-1] |= shift;
				row1[i-1] |= shift*2;
				row1[i-1] |= shift/2;
				row1[i] |= shift/2;
				row1[i] |= shift*2;
				row1[i] |= shift;
							
				put(1,j,i);
				
				for(int j = 0;j<n;j++)
					row1[j] = 0;
			}
			//counter *= 2;
	}
	else
	{
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
			{
				shift = 1<<j;
				row1[i+1] |= shift;
				row1[i+1] |= shift*2;
				row1[i+1] |= shift/2;
				row1[i-1] |= shift;
				row1[i-1] |= shift*2;
				row1[i-1] |= shift/2;
				row1[i] |= shift/2;
				row1[i] |= shift*2;
				row1[i] |= shift;
							
				put(1,j,i);
				
				for(int j = 0;j<n;j++)
					row1[j] = 0;
			}
	}
	cout<<counter<<endl;
}
