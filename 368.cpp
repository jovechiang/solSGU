#include <iostream>
#include <string>
#define Max 200
using namespace std;

int n,m,k;
string reshte;
string zirshakhe;
int num_zirshakhe;
int score[Max];
int moghayese[Max];
int s;
int score_do(int x,int y,int z,int ct)
{
	//cout<<"x y z : "<<x<<" "<<y<<" "<<z<<" score [ct] = "<<score[moghayese[ct]]<<endl;
	if(score[moghayese[ct]] < x)
		return 2;
	if(score[moghayese[ct]] >= x && score[moghayese[ct]] < y)
		return 3;
	if(score[moghayese[ct]] >= y && score[moghayese[ct]] < z)
		return 4;
	if(score[moghayese[ct]] >= z)
		return 5;
	//return 1000;
}
bool finder = false;
int main()
{
	cin>>n>>m;
	for(int i = 0;i < m;i++)
		cin>>score[i];
	for(int i = 0;i < n;i++)
	{
		cin.ignore();
		getline(cin,reshte);
		cin>>k;
		for(int j = 0;j < k;j++)
		{
			cin>>moghayese[j];
			moghayese[j]--;
		}
		
		s = 0;
		int x,y,z;
		for(int ct = 0;ct < k;ct++)
		{
			cin>>x>>y>>z;
			//cout<<"adding : "<<score_do(x,y,z,ct)<<endl;
			s += score_do(x,y,z,ct);
		}
		//cout<<"score = "<<s<<endl;
		cin>>num_zirshakhe;
		for(int ct = 0;ct < num_zirshakhe;ct++)
		{
			cin.ignore();
			getline(cin,zirshakhe);
			int st;
			cin>>st;
			if(s >= st)
			{
				finder = true;
				cout<<reshte<<" "<<zirshakhe<<endl;
			}
		}
	}//for e kolli
	if(!finder)
		cout<<"Army"<<endl;;
	cin>>n;
}
