#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#define ULL unsigned long long int
#define Max 100010

using namespace std;

struct Find
{
	int start;
	int end;
};
struct String
{
	void get();
	Find find_substr(int start,char * s);
	char val[Max];
	int len;
};
void String::get()
{
	scanf("%s",&val);
	len = strlen(val);
}
Find String::find_substr(int start,char * s)
{
	Find f;
	int j = 0;
	int l = strlen(s);
	for(int i = start;i<len;i++)
	{
		if(val[i] == s[j])
		{
			if(j == 0)
			{
				f.start = i;
			}
			j++;
			if(j == l)
			{
				f.end = i;
				return f;
			}
		}//==
	}//for
	f.end = -1;
	return f;
}
ULL num;
ULL halat;
int str1,str2;
int main()
{
	String s;
	char s1[Max];
	s.get();
	scanf("%s",&s1);
	Find f;
	f = s.find_substr(0,s1);
	str1 = f.start;
	while(f.end != -1)
	{
		cout<<"start = "<<f.start<<" end = "<<f.end<<endl;
		cout<<"zarb : "<<str1 - str2 + 1<<" * "<<s.len - f.end<<endl;
		num += (str1 - str2 + 1)*(s.len - f.end) - 1;
		if(f.end - f.start >= 1) 
			f = s.find_substr(f.end,s1);
		else
			f = s.find_substr(f.end + 1,s1);
		str2 = str1;
		str1 = f.start;
	}
	num++;
	cout<<num;
	cin>>num;
	return 0;
}
