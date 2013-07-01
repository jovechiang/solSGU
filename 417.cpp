#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
int main()
{
	int x,y,r;
	cin>>x>>y>>r;
	double chegal = log(x*x+y*y);
	double s = M_PI*r*r;
	printf("%.12lf",s*chegal);
	getch();
	return 0;
}
