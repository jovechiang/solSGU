//AC
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string s[101];
int l;
int kmm(int a,int b)
{
	if(a > b)
		swap(a,b);
	int c = b;
	while(b % a != 0)
		b += c;
	return b;
}
bool cmp(string s1,string s2)
{
	string add1 = s1;
	string add2 = s2;
	int l1 = s1.length();
	int l2 = s2.length();
	int l = kmm(l1,l2);
	for(int i = 0;i < l / l1;i++)
		s1 += add1;
	for(int i = 0;i < l / l2;i++)
		s2 += add2;
	return s1 < s2;
}
int main()
{
	int n;
	cin>>n;

	for(int i = 0;i<n;i++)
		cin>>s[i];
	
	sort(s,s+n,cmp);
	
//	sort(s,s+n);
	for(int i = 0;i<n;i++)
		cout<<s[i];
	cin>>n;
}
