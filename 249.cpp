#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n,m;

int bit[21];
void fill_bit(int a);

int helpb[21];
int helpp[21];
int helpr[21];
int helpc[21];
void fill_help(int * help,int a);

void print_ans();
void print(int * a,int k);
bool adj(int * bit,int * help);

int max_num;
bool use[1000 * 1000 * 10];
int ans[21][21];
bool is_fill[21][21];
bool finder = false;
void put(int x,int y)
{
	if(finder)
		return;
//	cout<<"checking x = "<<x<<" y = "<<y<<endl<<endl;;
//	print_ans();
//	cout<<endl;
	if(y == n + 1)
	{
		//cout<<"Tamoome YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEES"<<endl;
		finder = true;
		return;
	}//if finished
	
	bool okr = false,okc = false,okb = false,okp = false;
	/************hamsaye chap****************/
	int chap;
	if(x == 1)
		chap = ans[m][y],okc = true;
	else
		chap = ans[x - 1][y];
	fill_help(helpc,chap);
	/************hamsaye chap****************/
	/************hamsaye rast****************/
	int rast;
	if(x == m)
		rast = ans[1][y];
	else
		rast = ans[x + 1][y],okr = true;
	fill_help(helpr,rast);
	/************hamsaye rast****************/
	/************hamsaye bala****************/
	int bala;
	if(y == 1)
		bala = ans[x][n],okb = true;
	else
		bala = ans[x][y - 1];
	fill_help(helpb,bala);
	/************hamsaye bala****************/
	/************hamsaye Payin****************/
	int payin;
	if(y == n)
		payin = ans[x][1];
	else
		payin = ans[x][y + 1],okp = true;
	fill_help(helpp,payin);
	/************hamsaye Payin****************/
	
	for(int i = 0;i < max_num;i++)
	{
		if(use[i])
			continue;
		
		fill_bit(i);
		
		if(!okb)
			okb = adj(bit,helpb);
		if(!okp)
			okp = adj(bit,helpp);
		if(!okr)
			okr = adj(bit,helpr);
		if(!okc)
			okc = adj(bit,helpc);
	
		if(!okr || !okc || !okb || !okp)
			continue;
/*		int komak[21];
		if(!okr)
		{
			cout<<"Rastesh moshkel dare : "<<endl;
			print(helpr,m + n);
			fill_help(komak,i);
			print(komak,m + n);
			continue;
		}
		if(!okc)
		{
			cout<<"chapesh moshkel dare : "<<endl;
			print(helpc,m + n);
			fill_help(komak,i);
			print(komak,m + n);
			continue;
		}
		if(!okb)
		{
			cout<<"Balash moshkel dare : "<<endl;
			print(helpb,m + n);
			fill_help(komak,i);
			print(komak,m + n);
			continue;
		}
		if(!okp)
		{
			cout<<"payinesh moshkel dare : "<<endl;
			print(helpp,m + n);
			fill_help(komak,i);
			print(komak,m + n);
			continue;
		}*/
		
		use[i] = true;
		ans[x][y] = i;
		int x1 = x;
		int y1 = y;
		x1 ++;
		if(x1 > m)
			x1 = 1,y1++;
//		cout<<"can put "<<i<<" in "<<x<<" "<<y<<endl;
//		cout<<"x1 becomes : "<<x1<<" y1 = "<<y1<<endl;
		put(x1,y1);
		if(finder)
			return;
		use[i] = false;
	}//for choose
}//void put
int main()
{
	cin>>n>>m;
	max_num = int(pow(2.0,double(m + n)));
	m = int(pow(2.0,m));
	n = int(pow(2.0,n));
	cout<<"Range from : "<<0<<" to "<<max_num<<endl;
	is_fill[1][1] = true;
	ans[1][1] = 0;
	use[0] = true;
	put(2,1);


	if(finder)
		cout<<"Finished"<<endl;
	else
		cout<<"NOT Finished"<<endl;
	print_ans();
	int _;cin>>_;
}
void print_ans()
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			cout<<ans[j][i];
		cout<<endl;
	}
}

void fill_bit(int a)
{
	memset(bit,0,sizeof(bit));
	int ct = 0;
	while(a >= 1)
		bit[ct++] = a % 2,a /= 2;
}
void fill_help(int *help,int a)
{
	memset(help,0,sizeof(help));
	int ct = 0;
	while(a >= 1)
		help[ct++] = a % 2,a /= 2;
}
void print(int * a,int k)
{
	for(int i = 0;i < k;i++)
		cout<<a[k - i - 1];
	cout<<endl;
}
bool adj(int * bit,int * help)
{
	int ct = 0;
	for(int i = 0;i < 20;i++)
		if(bit[i] != help[i])
			ct++;
	return ct == 1;
}
