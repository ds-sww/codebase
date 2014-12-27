#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,s;
long long ans;
int a[20010];
int main()
{
    scanf("%d %d",&n,&s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        while (a[i] + a[j] > s) j--;
        if (i > j) break;
        ans += (long long)(j - i);
    }
    printf("%lld\n",ans);
    return 0;
}
