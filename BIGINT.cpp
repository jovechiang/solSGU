#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
struct Big
{
	public:
		int num[1000];
		int len;
		Big operator = (Big a)
		{
			memset(num,0,sizeof(num));
			len = a.len;
			for(int i = 0;i<len;i++)
				num[i] = a.num[i];
		}
		void operator = (int a)
		{
			memset(num,0,sizeof(num));
			if(a == 0)
			{
				num[0] = 0;
				len = 1;
				return ;
			}
			len = 0;
			while(a >= 1)
			{
				num[len] = a%10;
				len++;
				a/=10;
			}
		}
		void print()
		{
			for(int i = len - 1;i>=0;i--)
				cout<<num[i];
			cout<<endl;
		}
		Big operator *= (int a)
		{
			int l = len;
			for(int i = 0;i < l;i++)
				num[i] *= a;
				
			for(int i = 0;i < 999;i++)
				num[i + 1] += num[i]/10,num[i] %= 10;
		}
		void get()
		{
			char s[1000];
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
		void operator += (Big a)
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
    		len = n.len;
    		for(int i = 0;i<len;i++)
    		{
				num[i] = n.num[i];
			}
		}
		void operator += (int b)
		{
			Big a;
			a = b;

			Big n;
			n.len = len;
			for(int i = 0;i<len;i++)
			{
				n.num[i] = num[i];
			}
			n += a;

			len = n.len;
			for(int i = 0;i<len;i++)
			{
				num[i] = n.num[i];
			}
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
Big a,b;
int n;
main()
{
	b = 120;
	a = 10;
	b += 1001;
//	b += a;
//	a.print();
	b.print();
	cin>>n;
}
