#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

const int Max = 50000 + 10;

struct Team
{
	string name;
	int p1,p2;
	int score;
/*	bool operator <(Team t)const
	{
		if(score == t.score)
			return name < t.name;
		return score < score;
	}*/
};
map <string,Team> t[Max];
int n;
int main()
{
	string read;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>read;
		t["s"].name = read;
		t["s"].p1 = i + 1; 
	}
	int _;cin>>_;
}

