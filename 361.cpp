#include <iostream>

using namespace std;

char s[3][3] = 
{
	'#','0','0',
	'0','0','#',
	'0','#','0',
};
int main()
{
	int n,m;
	while(1){
	cin>>n>>m;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cout<<s[i%3][j%3];
		}
		cout<<endl;
	}
	cout<<endl;
}
	cin>>n;
	return 0;
}
