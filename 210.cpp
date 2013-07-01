#include <iostream>
#include <vector>

#define Maxn 410

using namespace std;

struct son
{
	int l;
	bool girl[Maxn];
	int doost;
	bool operator < (const son s)const
	{
		return (doost < s.doost);
	}
};//son
int n;
son s[Maxn];
bool use[Maxn];
int mar[Maxn];
int mx;
int ANS[Maxn];
int max_doost = 0;
void make(int k)
{
	if(mx == max_doost)
		return;
	if(k > n)
	{
		int sum = 0;
		for(int i = 1;i <= n;i++)
			if(mar[i])
				sum += s[i].doost;
		if(sum > mx)
		{
			mx = sum;
			for(int i = 1;i <= n;i++)
				ANS[i] = mar[i];
		}
		return;
	}//finished
	mar[k] = 0;
	make(k + 1);
	for(int i = 1;i <= 400;i++)
		if(s[k].girl[i] && ! use[i])
			mar[k] = i,use[i] = true,make(k + 1),use[i] = false;
}//void make
int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>s[i].doost,max_doost += s[i].doost;
	for(int i = 1;i <= n;i++)
	{
		cin>>s[i].l;
		int p;
		for(int j = 0;j < s[i].l;j++)
			cin>>p,s[i].girl[p] = true;
	}
	//sort(s,s + n);
	make(1);
	for(int i = 1;i <= n;i++)
		cout<<ANS[i]<<" ";
	cout<<endl;
	cin>>n;
}
