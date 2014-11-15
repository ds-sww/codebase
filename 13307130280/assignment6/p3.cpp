#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int a[2][20010];
void qsort(int s,int x, int y)
{
    int i,j,k;
    i = x;
    j = y;
    k = a[s][(i + j)>>1];
    while (i < j)
    {
        while (a[s][i] < k) i++;
        while (a[s][j] > k) j--;
        if (i <= j)
        {
            int t;
            t = a[s][i];
            a[s][i] = a[s][j];
            a[s][j] = t;
            i++;
            j--;
        }
    }
    if (i < y) qsort(s,i,y);
    if (x < j) qsort(s,x,j);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while (n + m > 0)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d",&a[0][i]);
        for (int i = 1; i <= m; i++)
            scanf("%d",&a[1][i]);
        qsort(0,1,n);
        qsort(1,1,m);
        int num = 0;
        int ans = 0;
        int k = 1;
        for (int i = 1; i <= m; i++)
        {
            if (k > n) break;
            if (a[1][i] >= a[0][k])
            {
                num++;
                ans += a[1][i];
                k++;
            }
        }
        if (num < n)
        {
            printf("Loowater is doomed!\n");
        }
        else
        {
            printf("%d\n",ans);
        }
        scanf("%d %d",&n,&m);
    }
    return 0;
}
