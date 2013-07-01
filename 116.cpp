#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

bool prime(int k)
{
	if(k == 0||k == 1)
		return false;
	if(k == 2)
		return true;
	int a  = int(sqrt(k)) + 1;
	for(int i = 2;i<=a;i++)
		if(k%i == 0)
			return false;
	return true;
}

int p[10001];
int primes[10001];
int s = 0;
int c = 0;

void create_num(int n,int i,int k,int *javab)
{
	if(s == 1)
		return;
	if(n<0)
	{
	//	cout<<endl;
		return;
		
	}
	if(n == 0)
	{
		cout<<k<<endl;
		for(int i = 0;i<k;i++)
			for(int i = 0;i<k-1;i++)
			{
				if(javab[i]<javab[i+1])
				{
					int b = javab[i];
					javab[i] = javab[i+1];
					javab[i+1] = b;
				}
			}
			
		for(int i = 0;i<k;i++)
			cout<<p[javab[i]]<<" ";
		cout<<endl;
		s = 1;
		return;
	}	
//	cout<<p[i]<<" ";
	n -= p[i];
//	if(i == 0)
//		cout<<p[i]<<" "<<n<<endl;;
	javab[k] = i;
	for(int i = c-1;i>=0;i--)
	{
//		if(p[i]>n)
//			continue;
		create_num(n,i,k+1,javab);
	}
}

int main()
{
	int i;
	int counter = 1;
	for(int i = 2;i<=10000;i++)
	{
		if(prime(i))
		{
			primes[counter] = i;
			if(prime(counter))
			{
				p[c] = i;
				c++;
			}
			counter++;
			
		}
	}
	int n = 1;
//	while(1){
	s = 0;
	cin>>n;
	//n++;
	cout<<endl<<endl<<n<<endl<<endl;
	int j[10000];
	for(int i = c-1;i>=0;i--)
	{
		if(p[i]  == n)
		{
			s = 1;
			cout<<1<<endl<<p[i]<<endl;
//			return 0;
	//		cout<<p[i]<<endl;
//			continue;
		}
//		cout<<"GOOD    "<<p[i]<<endl;
		create_num(n,i,0,j);
	}
	if(s == 0)
	{
		cout<<0<<endl;getch();
	}
	getch();
	return 0;
}
