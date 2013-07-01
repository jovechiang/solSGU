//AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
class Outpost
{
	public:
		int a,b;
		friend istream& operator >> (istream &out,Outpost &A)
		{
			out>>A.a>>A.b;
		}
		friend ostream& operator << (ostream &out,Outpost &A)
		{
			out<<A.a<<" "<<A.b;
		}
		bool operator < (const Outpost A)const
		{
			return (a<A.a);
		}
};
Outpost o[20000];
bool redundant(int A,int B)
{
	if(o[A].b > o[B].b)
		return true;
	return false;
}
int n;
//bool r[20000];
int main()
{
	cin>>n;
	for(int i = 0;i<n;i++)
		cin>>o[i];
	sort(o,o+n);
	int counter = 0;
	int i,j = 0;
	for(i = 1;i<n;i++)
	{
		if(redundant(j,i))
		{
			counter++;
		}
		else
		{
			j = i;
		}
	}
	cout<<counter<<endl;
	cin>>o[0];
}
