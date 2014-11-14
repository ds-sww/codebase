#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
char a[2][20010][22];
int ans[20010];
int num;
int r[5];
int number(char c)
{
    switch (c)
    {
        case 'A':return 1;
        case 'C':return 2;
        case 'G':return 3;
        case 'T':return 4;
    }
    return 0;
}
int main()
{
    int n,m,k,l;
    scanf("%d %d",&n,&m);
    while (n+m>0)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%s",a[0][i]);
        }
        
        for (int i = m; i >= 0 ; i--)
        {
            memset(r,0,sizeof(r));
            k =( m - i ) % 2;
            for (int j = 1;j <= n; j++)
            {
                r[number(a[k][j][i])] ++;
            }
            for (int j = 2; j < 5; j++)
                r[j] += r[j-1];
            l = 1 - k;
            for (int j = n; j > 0 ;j--)
            {
                int x = number(a[k][j][i]);
                for (int u = 0; u <= m ; u++)
                {
                    a[l][r[x]][u] = a[k][j][u];
                }
                r[x]--;
            }
        }
        
        memset(ans,0,sizeof(ans));
        num = 0;
        for (int i = 1; i <= n; i++)
        {
            bool ok = true;
            for (int j = 0; j < m; j++)
            if (a[l][i][j] != a[l][i-1][j])
            {
                ok = false;
                break;
            }
            if (ok)
            {
                num ++;
            }
            else
            {
                ans[num] ++;
                num = 0;
            }
        }
        ans[0]--;
        ans[num]++;
        for (int i = 0 ; i < n; i++)
            printf("%d\n",ans[i]);
        scanf("%d %d",&n,&m);
    }
    return 0;
}
