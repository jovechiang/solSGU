#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int Max = 100 * 1000 + 10;

int n;
struct adad
{
	int index;
	int val;
	bool operator < (adad a)const
	{
		return val < a.val;
	}
}num[Max];

vector <int> ans;
vector <int> mode;//1 : (*2),2 : (ALL--)

const int fly = 1;
const int science = 2;

int day;
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>num[i].val,num[i].index = i;

	int khar,mn,mx,mxi;

	sort(num,num + n);

	mn = num[0].val,mx = num[n - 1].val,mxi = n - 1;
	if(mn - 1)
	{
		for(int i = 0;i < n;i++)
			num[i].val -= mn - 1;
		mode.push_back(fly);
		ans.push_back(mn - 1);
		day += mn - 1;
	}//if mn != 1
	while(1)
	{
		mn = mx;
		for(int mni = 0;mni < n;mni++)
		{
			if(num[mni].val == mx)
				continue;
			int ct = 0;
			while(num[mni].val <= mx)
			{
				num[mni].val *= 2;
				mode.push_back(science);
				ans.push_back(num[mni].index);
				ct ++;
			}
			num[mni].val /= 2;
			mode.pop_back();
			ans.pop_back();
			day += ct - 1;
			mn = min(mn,num[mni].val);
			
			
			/*****
			sort(num,num + n);
			int kam = num[0].val;
			for(int i = 0;i < n;i++)
				num[i].val -= (kam - 1);
			mode.push_back(fly);
			ans.push_back(kam - 1);
			day += kam - 1;
			mn = num[0].val;
			mx = num[n - 1].val;
			break;
			/*****/
		}

			/*****/
			sort(num,num + n);
			int kam = num[0].val;
			for(int p = 0;p < kam;p++)
				for(int i = 0;i < n;i++)
					num[i].val -= 1;//(kam - 1);
			mode.push_back(fly);
			ans.push_back(kam - 1);
			day += kam - 1;
			mn = num[0].val;
			mx = num[n - 1].val;
			break;
			/*****/



		if(mn == mx)
		{
			mode.push_back(fly);
			ans.push_back(mx);
			day += mx;
			break;
		}

	}//while
	cout<<day<<endl;
	if(day <= 1000)
		for(int i = 0;i < mode.size();i++)
			if(mode[i] == fly)
				for(int j = 0;j < ans[i];j++)
					cout<<"flying mission"<<endl;
			else
				cout<<"science mission to the planet "<<ans[i] + 1<<endl;
	cin>>n;
}//main()
