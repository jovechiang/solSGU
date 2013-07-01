#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int count(int k)
{
	int ct = 0;

	while(k >= 1)
	{
		if(k & 1)
			ct++;
		k /= 2;
	}

	return ct;
}

int tedad(int k)
{
	int ct = 0;
	for(int i = k + 1;i <= 2 * k;i++)
		if(count(i) == 3)
		{
			//cerr << " ONE = " << i << endl;
			ct++;
		}

	//cerr << endl << endl;

	return ct;
}

#define LL long long

map <LL, int> mp;

int mark[3000];

LL MAX = 1;

int main()
{
	for(int i = 0;i < 32;i++)
		MAX *= 2;
	MAX--;

	for(LL i = 2, ez = 2;i < MAX;i += ez, ez++)
	{
		//cerr << i << endl;
		mp[i] = 1;
	}

	LL n, m;

	cin >> n;

	for(int i = 0;i < n;i++)
	{
		cin >> m;

		if(mp[m] == 1)
		{
			cout << "YES" << endl;

			continue;
		}
		else
			cout << "NO" << endl;

		/*m--;

		m *= 2;

		int s = int(sqrt(m));

		bool yes = false;
		for(int j = max(0, s - 10);j < s + 10;j++)
			if(j * (j + 1) == m)
				yes = true;

		if(yes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;*/
	}

	/*int mx = -1;
	for(int i = 0;i < 10000;i++)
	{
		int f = tedad(i);
		mx = max(mx, f);
		mark[f]++;
	}

	cerr << "CHAP" << endl;
	for(int i = 0;i < mx;i++)
		if(mark[i] == 1)
			cout << i << endl;

	cerr << "END" << endl;*/
}
