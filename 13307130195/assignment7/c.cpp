#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int maxn = 100000;
const int maxh = 2000000007;
int a[maxn], q[maxn], d[maxn];
int n,t;

int main()
{
    //freopen("a.in", "r", stdin);

    cin>>n;
    for (int i = 1; i <= n; i++) cin>>a[i];

    t = 1;
    q[1] = 1;
    q[0] = 0;
    a[0] = maxh;

    for (int i = 1; i <= n; i++)
    {
        while (a[q[t]] <= a[i]){

            d[q[t]] = i;
            t--;
        }
        q[++t] = i;
    }

    for (int i = 1; i <= t; i++) d[q[i]] = n+1;

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += (long long)(d[i] - i - 1);
    cout<<ans<<endl;


    return 0;
}