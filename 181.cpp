//AC
#include <iostream>
using namespace std;
#define pow2(a) a*a
#define Max 10100

long long a,alpha,beta,gamma,k,m;
int x[Max];
int ans[Max];
int main()
{
	int c = 0;
	cin>>a>>alpha>>beta>>gamma>>m>>k;
	x[0] = a;
	ans[x[0]] = c;
	c++;
	for(int i = 1;i<=k;i++)
	{
		x[i] = (alpha* pow2 (x[i - 1]) + beta * x[i - 1] + gamma)%m;
		if(ans[x[i]] != 0)
		{
			k -= ans[x[i]];
			k %= (i - ans[x[i]] + 1 - 1);
			cout<<x[k + ans[x[i]]]<<endl;
			cin>>a;
			return 0;
		}
		else
		{
			ans[x[i]] = c;
			c++;
		}
	}
	cout<<x[k]<<endl;;
	cin>>a;
}
