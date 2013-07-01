#include <iostream>
using namespace std;

#define red 1
#define yellow 2
#define green 3
#define brown 4
#define blue 5
#define pink 6
#define black 7
int num[10];
int moves[100];
main()
{
	string s;
	cin>>num[red]>>num[yellow]>>num[green]>>num[brown]>>num[blue]>>num[pink]>>num[black];
	cin>>s;
	moves[0] = black;
	if(s == "RED")
		moves[0] = red;
	int score = 0;
	int max = black;
	for(int i = black;i>=yellow;i--)
	{
		if(num[i])
		{
			max = i;
			break;
		}
	}
	int counter = 1;
	bool r = false;
	while(num[red] > 0)
	{
		r = 1;
		if(moves[counter - 1] == red)
		{
			score += max;
			moves[counter] = max;
		}
		else
		{
			num[red]--;
			score += red;
			moves[counter] = red;
		}
		counter++;
	}
	if(moves[counter - 1] == red)
		score += max;
	for(int i = black;i>=yellow;i--)
	{
		if(num[i])
		{
			score += i;
		}
	}
	cout<<score<<endl;
	cin>>num[0];
}
