#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char symbol[100];
char letter[100];
int symc = 0,lc = 0;
int n;
bool let(char a)
{
	for(int i = 0;i<lc;i++)
		if(a == letter[i])
			return true;
	return false;
}
bool sym(char a)
{
	for(int i = 0;i<symc;i++)
		if(a == symbol[i])
			return true;
	return false;
}
bool word(string s)
{
	int l = s.length();
	for(int i = 0;i<l;i++)
		if(!sym(s[i]) )
			return false;
	
	return true;
}
bool domain(string s)
{
	int l = s.length();
	if(l == 2 || l == 3)
	{
		for(int i = 0;i<l;i++)
			if(!let(s[i]) )
				return false;
		return true;
	}
	return false;
}
bool prefix(string s)
{
	int l = s.length();
	if(s[0] == '.'|| s[l - 1] == '.')
		return false;
	for(int i = 0;i<l;i++)
	{
		if(s[i] == '.'&&s[i + 1] != '.')
			continue;
		if(!sym(s[i]) )
			return false;
	}
	
	return true;
}
bool suffix(string s)
{
	int l = s.length();
	if(s[0] == '.'|| s[l - 1] == '.')
		return false;
	if(s[l - 4] != '.'&&s[l - 3] != '.')
		return false;
	int ll;
	if(s[l - 4] == '.')
		ll = l - 4;
	if(s[l - 3] == '.')
		ll = l - 3;
	string s1;
	for(int i = 0;i<ll;i++)
	{
		s1 += s[i];
	}
	if(prefix(s1))
	{
		string s2;
		for(int i = ll + 1;i<l;i++)
		{
			s2 += s[i];
		}
		if(domain(s2))
			return true;
		else
			return false;
	}
	return false;
}
main()
{
//	for(int i = 32;i <= 255;i++)
//		cout<<i<<" "<<char(i)<<endl;
	for(int i = 65;i <= 90;i++)
		letter[lc] = i,symbol[symc] = i,symc++,lc++;
	for(int i = 97;i <= 122;i++)
		letter[lc] = i,symbol[symc] = i,symc++,lc++;
	symbol[symc] = '0',symc++;
	symbol[symc] = '1',symc++;
	symbol[symc] = '2',symc++;
	symbol[symc] = '3',symc++;
	symbol[symc] = '4',symc++;
	symbol[symc] = '5',symc++;
	symbol[symc] = '6',symc++;
	symbol[symc] = '7',symc++;
	symbol[symc] = '8',symc++;
	symbol[symc] = '9',symc++;
	symbol[symc] = '_',symc++;
	symbol[symc] = '-',symc++;
	
	
	cin>>n;
	cin.ignore();
	string s;
	int num = 0;
	int numi;
	
	
	for(int i = 0;i<n;i++)
	{
		getline(cin,s);
		num = 0;
		numi = 0;
		for(int i = 0;i<s.length();i++)
			if(s[i] == '@')
				num++,numi = i;
		if(num == 1)
		{
			string s1 = "";
			string s2 = "";
			for(int i = 0;i<numi;i++)
				s1 += s[i];
			for(int i = numi + 1;i<s.length();i++)
				s2 += s[i];
//			cout<<s1<<endl<<s2<<endl;
			if(prefix(s1)&&suffix(s2))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	cin>>n;
}
