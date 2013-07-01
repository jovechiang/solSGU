#include <iostream>

using namespace std;

string s;
int stack[1000];
int counter = 0;
int main()
{
	cin>>s;
	int n = s.length();
	for(int i = 0;i<n;i++)
	{
		if(s[i] == '<')
		{
			i++;
			if(s[i] == '/')
			{
				i++;
				int f;
				if(s[i] == 'U')
				{
					f = 1;
					i+=2;
				}
				else
				{
					i+=4;
					f = 2;
				}
				int k = counter - 1;
				for(int j = k;j>=0;j--)
				{
					if(stack[j] == f)
					{
						k = j;
						break;
					}
				}
				stack[k] = 0;
				for(int j = k + 1;j<counter;j++)
				{
					stack[j - 1] = stack[j];
				}
				counter--;
			}//stack deleter
			else
			{
				if(s[i] == 'U')
				{
					i+=2;
					stack[counter] = 1;
					counter++;
				}//up adder
				else
				{
					i+=4;
					stack[counter] = 2;
					counter++;
				}//down adder
			}//stack adder
		}//if be tag resid
		else
		{
			if(counter != 0)
			{
				int c = counter - 1;
				if(stack[c] == 1)
				{
					cout<<char(toupper(s[i]));
				}
				else
				{
					cout<<char(tolower(s[i]));
				}
			}//stacki voojood dasht
			else
			{
				cout<<s[i];
			}
		}//agar tag nabood
	}//for 1 to length
	return 0;
}
