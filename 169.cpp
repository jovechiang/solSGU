#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int k,count;
while(1){
	cin>>k;
	if (k==1)
		cout<<8<<endl;
	else
	{
		count = 1;
		if (k%3 == 1)
			count += 2;
		if (k%6 == 1)
			count++;
		printf("%d\n ", count);
	}
	cout<<endl;
}
}
