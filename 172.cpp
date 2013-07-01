#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

int c[201],b[201][40401];

int main()
{
    int n,m,a1,s=0,l=0,a2;
    cin >> n >> m;
    for (int i=1;i<=m;i++)
    {
        cin >> a1 >> a2;
        b[a[1][i]][0]=b[a[1][i]][0]+1;
        b[a[1][i]][b[a[1][i]][0]]=a[2][i];
        b[a[2][i]][0]=b[a[2][i]][0]+1;
        b[a[2][i]][b[a[2][i]][0]]=a[1][i];
    }
    c[1]=1;
/*    for (int i=1;i<=n;i++)
    {
        cout << i << ':';
        for (int j=1;j<=b[i][0];j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }*/
    while (l==0)
    {
        s=s+1;
        l=1;
        for (int i=1;i<=n;i++)
        {
            if (c[i]==1)
                for (int j=1;j<=b[i][0];j++)
                    c[b[i][j]]=2;
            if (c[i]==2)
                for (int j=1;j<=b[i][0];j++)
                    c[b[i][j]]=1;
            if (c[i]==0)
            {
                for (int j=1;j<=b[i][0];j++)
                    if (c[b[i][j]]!=0)
                    {
                        if (c[b[i][j]]==1)
                            c[i]=2;
                        if (c[b[i][j]]==2)
                            c[i]=1;
                        i=i-1;
                        break;
                    }
                if (c[i]==0)
                {
                    if (s==1)
                        l=0;
                    if (s==2)
                    {
                        c[i]=2;
                        s=0;
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=b[i][0];j++)
            if (c[i]==c[b[i][j]])
                l=0;
    if (l==0)
        cout << "no";
    if (l==1)
    {
        s=0;
        cout << "yes" << endl;
        for (int i=1;i<=n;i++)
            if (c[i]==1)
                s=s+1;
        cout << s << endl;
        for (int i=1;i<=n;i++)
            if (c[i]==1)
                cout << i << ' ';
    }
    getch();
}
