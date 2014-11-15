#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN = 80010;
int a[MAXN];
int q[MAXN];
int s[MAXN];
int t;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    n++;
    a[n] = 2000000000;
    q[1] = a[1];
    s[1] = 1;
    t = 1;
    int i = 1;
    long long ans = 0;
    while (i < n)
    {
        i++;
        while ((a[i] >= q[t]) && (t > 0))
        {
            ans += (long long)(i - s[t] - 1);
            t--;
        }
        t++;
        q[t] = a[i];
        s[t] = i;
    }
    printf("%lld\n",ans);
    return 0;
}

