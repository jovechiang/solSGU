//AC
#include <iostream>
using namespace std;
 
const long power5[13]={1,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};
 
int main()
{
    while(1){
    long n(0),q,c(1),k(12);
    bool same;
    cin>>q;
    if (q==0)
    {
        cout<<1; return 0;
    }
    while (q)
    {
        same=true;
        for (;(power5[k]-1)/4>q;k--,same=false);
        if (same) c++;
        else c=1;
        if (c>4) break;
        n+=power5[k]; q-=(power5[k]-1)/4;
    }
    if (c>4) cout<<"No solution";
    else cout<<n;
    cout<<endl;
}
    return 0;
}
