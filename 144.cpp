#include <iostream>
#include <cstdio>
using namespace std;
main()
{
	double soorat;
	double makhraj;
	double s,e,t;
	cin>>s>>e>>t;
	s *= 60;
	e *= 60;
	makhraj = (e - s)*(e - s);
	soorat = makhraj - ( ((e - s) - t)*((e - s) - t) );
	printf("%.7f\n",soorat/makhraj);
//	cin>>s;
}
