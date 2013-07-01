//AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#define get(a) scanf("%lld",&a)
#define Max 500010
#define ULL unsigned long long int

using namespace std;

int n;
ULL tmp;
ULL sum = 0;
ULL H[Max];
void heapify(int node)
{
	if(node >= n)
		return;
	int R = 2 * node + 2;
	int L = 2 * node + 1;
	if(L > n-1 && R > n-1)
		return;
	R = min(R,n - 1);
	L = min(L,n - 1);
	if(H[node] <= H[R] && H[node] <= H[L])
		return;
	int t;
	if(H[R] <= H[L])
		t = R;
	else 
		t = L;
	swap(H[t],H[node]);
	heapify(t);
}//void heapify
int main()
{
	get(n);	
	for(int i = 0;i < n;i++)
		get(H[i]);
	while(n > 1)
	{
		tmp = H[0];
		H[0] = H[n - 1];
		n--;
		heapify(0);
		H[0] += tmp;
		sum += H[0];
		heapify(0);
	}
	cout<<sum<<endl;
	cin>>sum;
}
