#include <iostream>
#include <cstring>
#include <algorithm>
#define MaxR 506
#define ARR 1002
using namespace std;
class Big
{
	public:
		int num[MaxR + 100];
		int len;
		void get()
		{
			char s[510];
			cin>>s;
			int l = strlen(s);
			len = l;
			int c = l - 1;
			for(int i = 0;i < l;i++)
			{
				num[i] = s[c] - '0';
				c--;
			}
		}
		void print()
		{
			for(int i = len - 1;i>=0;i--)
				cout<<num[i];
		}
		Big operator = (Big a)
		{
			len = a.len;
			for(int i = 0;i<len;i++)
				num[i] = a.num[i];
		}
		Big operator = (int a)
		{
			len = 0;
			while(a >= 1)
			{
				num[len] = a%10;
				len++;
				a/=10;
			}
		}
		Big operator + (const Big a)const
		{
			Big r;
			int l;
			r.len = len;
			for(int i = 0;i <= len;i++)
				r.num[i] = num[i];
			for(int i = len;i <= MaxR - 1;i++)
				r.num[i] = 0;
			if(len > a.len)
				l = len;
			else
				l = a.len;
			for(int i = 0;i < l;i++)
				r.num[i] += a.num[i];
			for(int i = 0;i < MaxR - 5;i++)
				r.num[i + 1] += r.num[i]/10,r.num[i] %= 10;
			for(int i = MaxR - 6;i>=len;i--)
			{
				if(r.num[i] != 0)
				{
					//cout<<"len = "<<i+1<<endl;
					r.len = i + 1;
					return r;
				}
			}
		}
		Big operator += (Big a)
		{
			Big n;
        	n.len=max(a.len,len);int d=0;
        	for(int i=0;i<n.len;i++)
        	{
				d+=a.num[i]+num[i];
				n.num[i]=d%10;
    	    	d/=10;
        	}
        	if(d)
    			n.num[++n.len]=d;
    		return n;

		}
		bool operator < (const Big a) const
		{
			if(len != a.len)
				return len < a.len;
			
			for(int i = len - 1;i>=0;i--)
			{
				if(num[i] > a.num[i])
					return false;
				if(num[i] < a.num[i])
					return true;
			}
			return false;
		}
};
Big a[ARR];
int n;
Big c,d;
main()
{
	cin>>n;
	for(int i = 0;i<n;i++)
		a[i].get();
	sort(a,a+n);
	for(int i = 0;i<=n - 3;i++)
	{
		if( a[i+2] < (a[i] + a[i+1]) )
		{
			a[i].print();
			cout<<" ";
			a[i+1].print();
			cout<<" ";
			a[i+2].print();
			cout<<endl;
			cin>>n;
			return 0;
		}
	}
	cout<<"0 0 0"<<endl;
	cin>>n;
}
