#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#define ULL unsigned long long int
#define Max 2020

using namespace std;

struct Find
{
	int start;
	int end;
};
struct String
{
	String();
	~String();
	ULL convert_to_int();
	void operator = (char * s);
	void operator = (char s);
	void operator += (char * s);
	void operator += (char s);
	void get();
	void put();
	bool Palindrome(int,int);
	Find find_substr(int start,int end,char * s);
	Find find_str(int start,int end,char * s);
	char val[Max];
	int length();
	int len;
};
String::String()
{
	len = 0;
}
String::~String()
{
	len = 0;
}
ULL String::convert_to_int()
{
	ULL a;
	ULL k = 1;
	for(int i = len - 1;i >= 0;i--)
	{
		a += k * (val[i] - '0');
		k *= 10;
	}
	return a;
}
void String:: operator = (char * s)
{
	int l = strlen(s);
	for(int i = 0;i<l;i++)
	{
		val[i] = s[i];
	}
	len = l;
	val[len] = 0;
}
void String:: operator = (char s)
{
	len = 1;
	val[0] = s;
	val[len] = 0;
}
void String::operator += (char * s)
{
	int l = strlen(s);
	for(int i = len;i<len+l;i++)
	{
		val[i] = s[i];
	}
	len += l;
	val[len] = 0;
}
void String:: operator += (char s)
{
	val[len] = s;
	len++;
	val[len] = 0;
}
void String::get()
{
	scanf("%s",&val);
	len = strlen(val);
}
void String::put()
{
	for(int i = 0;i<len;i++)
		cout<<val[i];
}
Find String::find_substr(int start,int end,char * s)
{
	Find f;
	int j = 0;
	int l = strlen(s);
	for(int i = start;i<end;i++)
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
Find String::find_str(int start,int end,char * s)
{
	Find f;
	int j = 0;
	int l = strlen(s);
	for(int i = start;i<end;i++)
	{
		if(val[i] == s[j])
		{
			cout<<i<<" "<<val[i]<<" va "<<j<<" "<<s[j]<<endl;
			f.start = i;
			while( i < end && j < l)
			{
				j++;
				i++;
				if(!(val[i] == s[j]))
				{
					f.start = 0;
					break;
				}
				if(j == l)
				{
					f.end = i;
					return f;
				}
			}//while mosavi
			j = 0;
		}//==
	}//for
	f.end = -1;
	return f;
}
bool String::Palindrome(int s,int e)
{
	for(int i = 0;i < e;i++)
		if(val[s + i] != val[s + e - i - 1])
			return false;
	return true;
}

int main()
{
	String a,b;
	a.get();
	b.get();
	
	for(int andaze = a.len;andaze >= 1;andaze--)
		for(int pos = 0;pos < a.len - andaze + 1;pos++)
			if(a.Palindrome(pos,andaze))
			{
//				for(int i = pos;i < pos + andaze;i++)
//					cout<<a.val[i];
//				cout<<endl;
				
				bool finder = false;
				int j = pos;
				int l = pos + andaze;
				for(int i = 0;i<b.len && !finder;i++)
				{
					if(b.val[i] == a.val[j])
					{
						//cout<<i<<" "<<b.val[i]<<" va "<<j<<" "<<a.val[j]<<endl;
						while( i < b.len && j < l)
						{
							//cout<<i<<" "<<j<<endl;
							j++;
							i++;
							if(j == l)
							{
								finder = true;
								break;
							}
							if(!(b.val[i] == a.val[j]))
								break;
						}//while mosavi
						j = pos;
					}//==
				}//for
				if(finder)
				{
//					cout<<"FINAL : ";
					for(int i = pos;i < pos + andaze;i++)
						cout<<a.val[i];
					cout<<endl;
					int _;cin>>_;
					return 0;
				}
			}//find in b
	int _;cin>>_;
}

