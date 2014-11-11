#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int a[10010];
void qsort(int x,int y)
{
    int i,j,k,t;
    i = x;
    j = y;
    k = a[(x + y) >> 1];
    while (i < j)
    {
        while (a[i] > k) i++;
        while (a[j] < k) j--;
        if ( i <= j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (x < j) qsort(x,j);
    if (i < y) qsort(i,y);
}
int main()
{
    int n,m,k;
    scanf("%d",&k);
    for (int o = 1; o <= k; o++)
    {
        scanf("%d %d",&n,&m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d",&a[i]);
        }

        qsort(1,m);

        int ans = 0;
        int sum = 0;
        for (int i = 1; i <= m; i++)
        {
            ans ++;
            sum += a[i];
            if (sum >= n)
            {
                break;
            }
        }
        printf("Scenario #%d:\n",o);
        if (sum < n) printf("impossible\n");
        else printf("%d\n",ans);
        printf("\n");
    }
    return 0;
}
