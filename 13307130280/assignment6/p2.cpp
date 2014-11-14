#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
int a[50010];
void qsort(int x, int y)
{
    int i,j,k;
    i = x;
    j = y;
    k = abs(a[(i + j) >> 1]);
    while (i < j)
    {
        while (abs(a[i]) < k) i++;
        while (abs(a[j]) > k) j--;
        if (i <= j)
        {
            int t;
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
    int t,n;
    scanf("%d %d", &t ,&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(0,n - 1);
    int now = 0;
    int ans = 0;
    int k = 0;
    for (int i = 0 ;i < n; i++)
    {
        if (now + abs(a[i] - k) <= t)
        {
            now += abs(a[i] - k);
            ans ++;
            k = a[i];
        }
        else break;
    }
    printf("%d\n",ans);
    return 0;
}
