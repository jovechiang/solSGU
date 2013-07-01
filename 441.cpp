#include <iostream>
#define Max 200
#define mabna 1000000000
#define mabna_num 9
#define S "%.9d"
using namespace std;

struct Big
{
	public:
		int num[Max];
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
				num[len] = a%mabna;
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
			cout<<num[len - 1];
			for(int i = len - 2;i>=0;i--)
				printf(S,num[i]);
			cout<<endl;
		}
		void get()
		{
			memset(num,0,Max);
			char s[Max * mabna_num + 1];
			cin>>s;
			int l = strlen(s);
			int k = 1;
			int p;
			len = 0;
			bool ln;
			int i = 0;
			for(int c = l - 1;c >= 0;)
			{
				k = 1;
				p = i;
				i++;
				ln = true;
				for(int j = 0;j < mabna_num && c >= 0;j++,c--)
				{
					if(ln)
					{
						len++;
						ln = false;
					}
					num[p] += (s[c] - '0')*k;
					k *= 10;
				}
			}
		}
		void operator += (Big a)
		{
			Big n;
        	n.len=max(a.len,len);
			int d=0;
        	for(int i=0;i<n.len;i++)
        	{
				d+=a.num[i]+num[i];
				n.num[i]=d%mabna;
    	    	d/=mabna;
        	}
        	if(d)
        	{
				n.len++;
    			n.num[n.len - 1] = d;
			}
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
		void operator *=(int k)
		{
			for(int i = len;i<Max;i++)
				num[i] = 0;
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
		}
};
int ans;
int n,k;
int main()
{
	ans = 1;
	cin>>n>>k;
	if(n < k)
	{
		cout<<0<<endl;
		cin>>n;
		return 0;
	}
	else
	{
		int p,m;
		p = n;
		for(int i = 0;i < k;i++)
		{
			ans *= p % 2007;
			p--;
		}
		ans.print();
		cin>>n;
	}
}
