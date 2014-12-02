#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int a[100010];
int k,now;
void qsort(int x, int y)
{
    int i,j,k;
    i = x;
    j = y;
    k = a[(i + j)>>1];
    while (i < j)
    {
        while (a[i] < k) i++;
        while (a[j] > k) j--;
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
    if (i < y) qsort(i,y);
    if (x < j) qsort(x,j);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i + 1]);
    }
    qsort(1,n);

    for (int i = 0 ;i < 4; i++)
        getchar();

    scanf("%d",&k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d",&now);
        printf("%d\n",a[now]);
    }
    return 0;
}
