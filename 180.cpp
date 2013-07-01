//AC
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>
#define Max 100000
#define ULL unsigned long long int

using namespace std;

int arr[Max],cpy[Max],k = 0;
ULL Inverse = 0;

void Merge(int p,int q,int r)
{
	k = 0;
	int i = p;
	int j = q + 1;
	while(i <= q && j <= r)
		if(arr[j] < arr[i])
			Inverse += (q - i + 1),cpy[k++] = arr[j++];
		else
			cpy[k++] = arr[i++];

	while ( i <= q ) cpy[k++] = arr[i++];
	while ( j <= r ) cpy[k++] = arr[j++];

	for(int i = 0,j = p;i < k;i++,j++)
		arr[j] = cpy[i];
}//void Merge

void MergeSort(int start,int end)
{
	if(start >= end)
		return;
	MergeSort(start,(start + end) / 2);
	MergeSort((start + end) / 2 + 1,end);
	Merge(start,(start + end) / 2,end);
}//void MergeSort
int n;
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&arr[i]);
	
	MergeSort(1,n);
	
	cout<<Inverse<<endl;

	cin>>n;
}
