#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int n;
//Eular function 
int phi(int x){
    int ans=x;
    for(int i=2;i<(int)sqrt(x*1.0)+1;i++)
        if((x%i==0)){
            ans=ans/i*(i-1);
            while((x%i==0)) x/=i;
        }
    if(x>1) ans=ans/x*(x-1);
    return ans;
}
 
int main(){
    scanf("%d",&n);
    printf("%d\n",phi(n));
    return 0;
}
