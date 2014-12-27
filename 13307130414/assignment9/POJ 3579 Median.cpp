#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 1000;
int x[N];
int n,m,ans;

bool check(int a) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += n - (lower_bound(x, x+n, x[i]+a) - x);
    }
    if (cnt > m)
        return true;
    else
        return false;
}

int main() {
    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        sort(x, x+n);
        m = n*(n-1)/4;
        ans = -1;
        int l = 0, r = x[n-1]-x[0];
        while (l <= r) {
            int mid = (l+r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
