/*
	jam 2 ta big check shod.
	zarb big dar int check shod.
	WARNING : faghat mabna kar nemikone !!!!
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define Max 2000
#define mabna 10
#define mabna_num 1
#define S "%.1d"
#define ULL unsigned long long int

using namespace std;

struct Big
{
	public:
		vector<int> num;
		int len;
		Big operator = (Big a)
		{
			while(num.size() > 0)
				num.pop_back();
			len = a.len;
			for(int i = 0;i < len;i++)
				num.push_back(a.num[i]);
		}
		void operator = (int a)
		{
			while(num.size() > 0)
				num.pop_back();
			if(a == 0)
			{
				num.push_back(0);
				len = 1;
				return ;
			}
			len = 0;
			while(a >= 1)
			{
				num.push_back(a%mabna);
				len++;
				a/=mabna;
			}
		}
		void print()
		{
			if(num[len - 1] == 0)
			{
				cout<<0<<endl;
				return;
			}
			for(int i = len - 1;i >= 0;i--)
				cout<<num[i];
			cout<<endl;
		}
		void operator += (Big a)
		{
			Big n;
			while(n.num.size() > 0)
				n.num.pop_back();
        	n.len = max(a.len,len);
			int d=0;
        	for(int i=0;i<n.len;i++)
        	{
				d += a.num[i] + num[i];
				n.num.push_back(d%mabna);
    	    	d /= mabna;
        	}
        	if(d)
				n.len++,n.num.push_back(d);
    		len = n.len;
    		while(num.size() > 0)
				num.pop_back();
    		for(int i = 0;i<len;i++)
				num.push_back(n.num[i]);
		}
		void operator += (int b)
		{
			Big a;
			a = b;

			Big n;
			while(n.num.size() > 0)
				n.num.pop_back();
			n.len = len;
			for(int i = 0;i<len;i++)
			{
				n.num.push_back(num[i]);
			}
			n += a;

			len = n.len;
			while(num.size() > 0)
				num.pop_back();
			for(int i = 0;i<len;i++)
			{
				num.push_back(n.num[i]);
			}
		}
		void operator *= (int k)
		{


			for(int i = len;i<Max;i++)
				num.push_back(0);
			for(int i = 0;i<len;i++)
				num[i] *= k;
			for(int i = 0;i<len+10;i++)
			{
				num[i+1] += num[i]/mabna;
				num[i] %= mabna;
			}
			int i = len+20;
			bool zero = false;
			while(num[i] == 0)
			{
				i--;
				if(i == -1)
				{
					zero = true;
					break;
				}
			}
			if(zero)
				len = 1;
			else
				len = i+1;

			while(num.size() > len)
				num.pop_back();
		}
};
Big operator + (Big a,Big b)
{
	Big n;
	n = a;
	n += b;
	return n;
}
Big operator * (int b,Big a)
{
	Big n;
	n = a;
	n *= b;
	return n;
}
Big operator * (Big a,int b)
{
	Big n;
	n = a;
	n *= b;
	return n;
}

const int MAX = 251;

Big p[Max][Max];
int d[Max];

Big P(int j,int i)
{
	Big a;
	if(j == 0 && i == 0)
	{
		a = 1;
		return a;
	}
	if(i == 0)
	{
		a = 0;
		return a;
	}
	if(j == 0)
	{
		a = 1;
		return a;
	}
	return p[j][i];
}//Big P
int n,k;
int main()
{
	cin>>n>>k;
	
	for(int i = 1;i <= n;i++)//satr
		for(int j = 1;j <= k;j++)//rokh
			p[j][i] = 0;

	for(int i = 1;i<=n;i++)
		cin>>d[i];
	sort(d,d+n);

	for(int i = 1;i <= n;i++)//satr
		for(int j = 1;j <= k;j++)//rokh
		{
			P(j,i - 1).print();
			p[j][i] = P(j,i - 1) + P(j - 1,i - 1) * (d[i] - j + 1);
			p[j][i].print();
		}
		
//	p[k][n].print();
	cout<<"SIZE = "<<p[k][n].num.size()<<endl;
	cout<<"LEN = "<<p[k][n].len<<endl;
	cout<<"0 = "<<p[k][n].num[0]<<endl;
	
	cin>>n;
	return 0;
}
/*
4 1
1
2
3
4
*/
