//AC
#include <iostream>

using namespace std;

int n;
int main()
{
	cin>>n;
	if(n == 1)
	{
		cout<<"1 0"<<endl;
		return 0;
	}//n == 1
	if(n == 2)
	{
		cout<<"2 1"<<endl<<"1 2"<<endl;
		return 0;
	}
	if(n <= 4)
	{
		cout<<n<<" "<<n<<endl;
		for(int i = 1;i < n;i++)	
			cout<<i<<" "<<i + 1<<endl;
		cout<<n<<" "<<1<<endl;
		int _;cin>>_;
		return 0;
	}
	else
	{
		cout<<n<<" "<<2 * (n - 2)<<endl;
		for(int i = 1;i <= 2;i++)
			for(int j = 3;j <= n;j++)
				cout<<i<<" "<<j<<endl;
	}
	int _;cin>>_;
}//main
