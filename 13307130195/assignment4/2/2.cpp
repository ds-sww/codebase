#include "cmath"
#include "cstdlib"
#include "climits"
#include "vector"
#include "queue"
#include "map"
#include "set"
#include "string"
#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;

typedef long long LL;
typedef int arr[110000];
arr a, q, l, r;
int n;

int main()
{

    while(cin>>n) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin>>a[i];

        memset(q, 0, sizeof(q));
        memset(l, 0 ,sizeof(l));
        memset(r, 0 ,sizeof(r));
        int t = 1;
        l[1] = 1;
        q[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            while(a[q[t]] >= a[i] && t > 0) --t;
            l[i] = q[t] + 1;
            ++t;
            q[t] = i;
            
        }


        t = 1;
        r[n] = n;
        q[1] = n;
        q[0] = n + 1;

        for (int i = n-1; i >= 1; i--)
        {
            while(a[q[t]] >= a[i] && t > 0) --t;
            r[i] = q[t] - 1;
            ++t;
            q[t] = i;
        }

        LL ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, (LL)(r[i]- l[i] + 1) * (LL)a[i]);

        cout<<ans<<endl;
        // printf("%lld\n", ans);
    }

    return 0;
}