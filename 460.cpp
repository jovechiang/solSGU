#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>s;
		if(s[s.length() - 1] == 'x'||s[s.length() - 1] == 's'||s[s.length() - 1] == 'o'
		||( s[s.length() - 1] == 'h'&&s[s.length() - 2] == 'c') )
		{
			s = s+ "es";
			cout<<s<<endl;
		}
		else
		if(s[s.length() - 1] == 'f')
		{
			s[s.length() - 1] = 'v';
			s += "es";
			cout<<s<<endl;
		}
		else			
		if(s[s.length() - 1] == 'y')
		{
			s[s.length() - 1] = 'i';
			s += "es";
			cout<<s<<endl;
		}
		else
		if(s[s.length() - 2] == 'f'&&s[s.length() - 1] == 'e')
		{
			s[s.length() - 2] = 'v';
			s += "s";
			cout<<s<<endl;
		}
		else
		{
			s+='s';
			cout<<s<<endl;
		}
	}
	return 0;
}
