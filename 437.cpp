#include <iostream>
#include <cstdio>
//#include <conio.h>
using namespace std;
void wait();
int satr[34]={0,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4, 4, 5, 5, 5, 5, 5, 5, 6,6,6,6,6,7,7};
int ld[34] = {0,2,3,1,2,3,4,5,1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,7,3,4,5,6,7,5,6,0,0};
int rd[34] = {0,3,2,5,4,3,2,1,6,5,4,3,2,1,6,5,4,3,2,7,6,5,4,3,2,7,6,5,4,3,6,5};
int counter = 0;
int num[200];
int ans[200];
int m;

int k,sol;

//for daste ha
int daste[20][33];
int daste_count[20];
//for daste ha

//for khoone ha
int dastei[33][10];
int daste_counter[34];
//for khoone ha
int bit;

void fill();

bool finder;
char satrs[33],lds[33],rds[33];
bool b;
void bit_print(char c)
{
	int j;
	for(int i = 0;i<8;i++)
	{
		j = 1<<i;
		if(c & j)
			cout<<1;
		else
			cout<<0;
	}
	cout<<endl;
}
//int ,satrsrs,lds,rds,daste,daste_count);
void make(int n)
{
//	cout<<n<<endl;
//	//getch();
	if(finder)
		return;
//	cout<<n<<endl;
//	getch();
	if(n == 32)
	{
		counter++;
//		printf("counter = %d\n",counter);
//		getch();
		if(counter == sol)
		{
			printf("Found\n");
			finder = true;
			for(int i = 1;i<=31;i++)
				printf("%d ",ans[i]);
		}
		return;
	}
	if(num[n] != 0)
	{
		make(n+1);
		return;
	}
	int s,l,r;
	s = satr[n];
	l = ld[n];
	r = rd[n];
	int bits,bitl,bitr;
	bits = 1<<(s - 1);
	bitl = 1<<(l - 1);
	bitr = 1<<(r - 1);
/*	if(n == 14)
	{
		cout<<endl<<endl;
		cout<<"sina joon n resid be 14"<<endl;
		cout<<"r az rd biroon amade : "<<r<<endl;
		cout<<"bitr biroon oomade az r - 1 : ";bit_print(bitr);
		cout<<endl<<endl;
		getch();
	}	*/
	for(int i = 1;i<=k;i++)
	{
//		cout<<i<<" ja = "<<n<<endl;
//		getch();
		if( !(satrs[i]&bits) )
		{
//			cout<<"satr OK"<<endl;
//			getch();
			if( !(lds[i]&bitl) )
			{
//				cout<<"LD OK"<<endl;
//				getch();
				if( !(rds[i]&bitr) )
				{
//					cout<<"RD OK"<<endl;
//					getch();
					b = false;
					for(int j = 0;j<daste_counter[n];j++)
					{
						bit = dastei[n][j];
						for(int c = 0;c<daste_count[bit];c++)
						{
							if(i == daste[bit][c])
							{								
//								cout<<n<<" motallegh be daste number : "<<bit<<endl;
//								cout<<"daste Number "<<bit<<" : tedad por shode : "
//								<<daste_count[bit]<<" : "<<endl;
//								for(int c = 0;c<daste_count[bit];c++)
								{
//									cout<<c<<" : "<<daste[bit][c]<<endl;
								}
//								//getch();
								b = true;
								goto end;
							}
						}
					}//for e daste counter
					end :
					if(!b)
					{
//						cout<<"                             can Put "<<i<<" In ja : "<<n<<endl;
						
						for(int j = 0;j<daste_counter[n];j++)
						{
							bit = dastei[n][j];
							daste[bit][daste_count[bit]] = i;
							daste_count[bit]++;
//							cout<<"be dasteye "<<bit
//							<<" adad "<<i<<" be onvane "<<daste_count[bit]<<" omin ezafe shod"<<endl;
						}
						
						ans[n] = i;
						
						int s1,l1,r1;
						s1 = satrs[i];
						l1 = lds[i];
						r1 = rds[i];
						
//						cout<<"Rd shomareye "<<r<<" khat khord"<<endl;
//						cout<<"Ld shomareye "<<l<<" khat khord"<<endl;
//						cout<<"satrsr shomareye "<<s<<" khat khord"<<endl;
/*						cout<<"rd ["<<i<<"] = ";bit_print(rds[i]);
						cout<<i<<" : rd | shod ba : ";bit_print(bitr);
						cout<<"ld ["<<i<<"] = ";bit_print(rds[i]);
						cout<<i<<" : ld | shod ba : ";bit_print(bitr);*/
						satrs[i] |= bits;
						lds[i] |= bitl;
						rds[i] |= bitr;
//						cout<<"rd ["<<i<<"] hala shod : ";bit_print(rds[i]);
//						cout<<"lrd ["<<i<<"] hala shod : ";bit_print(lds[i]);
//						getch();
						make(n+1);
						
						for(int j = 0;j<daste_counter[n];j++)
						{
							bit = dastei[n][j];
							daste[bit][daste_count[bit]] = 0;
							daste_count[bit]--;
//							cout<<"az dasteye "<<bit<<
//							" yeki kam shod mande : "<<daste_count[bit]<<endl;
						}




						satrs[i] = s1;
						lds[i] = l1;
						rds[i] = r1;					
					}//if mishe gozasht
				}//if Rd OK
				else
				{
/*					cout<<"Dar ja "<<n<<" Va adade "<<i<<" gozashteshod :"<<endl;
					cout<<"rd : ";
					bit_print(rds[i]);
					cout<<"ld : ";
					bit_print(lds[i]);
					cout<<"satrsr : ";
					bit_print(satrs[i]);
					getch();*/
				}
			}//Ld OK
		}//satrsr OK
	}//for
}//void make
main()
{
	fill();
	cin>>k>>sol;
	int ct = 0;
	for(int i = 1;i<=31;i++)
	{
		scanf("%d",&num[i]);
		if(num[i] != 0)
		{
			ans[i] = num[i];
			ct ++;
			for(int j = 0;j<daste_counter[i];j++)
			{
				daste[dastei[i][j]][daste_count[dastei[i][j]]] = num[i];
				daste_count[dastei[i][j]]++;
				bit = 1<<satr[i] - 1;
				satrs[num[i]] |= bit;
				
				bit = 1<<ld[i] - 1;
				lds[num[i]] |= bit;
				
				bit = 1<<rd[i] - 1;
				rds[num[i]] |= bit;
			}
		}
	}
	if(ct == 31)
	{
		if(sol == 1)
		{
			finder = true;
			printf("Found\n");
			finder = true;
			for(int i = 1;i<=31;i++)
				printf("%d ",ans[i]);
		}
		else
		{
			finder = false;
		}
	}
	else
		make(1);
	if(!finder)
	{
		printf("No way\n");
	}
//	wait();
}
void wait()
{
	int _;
	cin>>_;
}
void fill()
{
	dastei[1][0] = 2;
	daste_counter[1] = 1;
	
	dastei[2][0] = 2;
	daste_counter[2] = 1;
	
	dastei[3][0] = 1;
	daste_counter[3] = 1;
	
	dastei[4][0] = 1;
	dastei[4][1] = 2;
	daste_counter[4] = 2;
	
	dastei[5][0] = 2;
	daste_counter[5] = 1;
	
	dastei[6][0] = 2;
	dastei[6][1] = 3;
	daste_counter[6] = 2;
	
	dastei[7][0] = 3;
	daste_counter[7] = 1;
	
	dastei[8][0] = 1;
	daste_counter[8] = 1;
	
	dastei[9][0] = 1;
	daste_counter[9] = 1;
	
	dastei[10][0] = 1;
	dastei[10][1] = 2;
	dastei[10][2] = 4;
	daste_counter[10] = 3;
	
	dastei[11][0] = 2;
	dastei[11][1] = 3;
	dastei[11][2] = 4;
	daste_counter[11] = 3;
	
	dastei[12][0] = 3;
	daste_counter[12] = 1;
	
	dastei[13][0] = 3;
	daste_counter[13] = 1;
	
	dastei[14][0] = 1;
	dastei[14][1] = 5;
	daste_counter[14] = 2;
	
	dastei[15][0] = 1;
	dastei[15][1] = 4;
	dastei[15][2] = 5;
	daste_counter[15] = 3;
	
	dastei[16][0] = 4;
	daste_counter[16] = 1;
	
	dastei[17][0] = 3;
	dastei[17][1] = 4;
	dastei[17][2] = 7;
	daste_counter[17] = 3;
	
	dastei[18][0] = 3;
	dastei[18][1] = 7;
	daste_counter[18] = 2;
	
	dastei[19][0] = 5;
	daste_counter[19] = 1;
	
	dastei[20][0] = 5;
	daste_counter[20] = 1;
	
	dastei[21][0] = 4;
	dastei[21][1] = 5;
	dastei[21][2] = 6;
	daste_counter[21] = 3;
	
	dastei[22][0] = 4;
	dastei[22][1] = 6;
	dastei[22][2] = 7;
	daste_counter[22] = 3;
	
	dastei[23][0] = 7;
	daste_counter[23] = 1;
	
	dastei[24][0] = 7;
	daste_counter[24] = 1;
	
	dastei[25][0] = 5;
	daste_counter[25] = 1;
	
	dastei[26][0] = 5;
	dastei[26][1] = 6;
	daste_counter[26] = 2;
	
	dastei[27][0] = 6;
	daste_counter[27] = 1;
	
	dastei[28][0] = 6;
	dastei[28][1] = 7;
	daste_counter[28] = 2;
	
	dastei[29][0] = 7;
	daste_counter[29] = 1;
	
	dastei[30][0] = 6;
	daste_counter[30] = 1;
	
	dastei[31][0] = 6;
	daste_counter[31] = 1;
}//void fill
