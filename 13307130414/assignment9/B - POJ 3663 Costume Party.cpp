#include <iostream>
#include <algorithm>
using namespace std;

int a[20005];
int ans;
int n,s;

void cnt(int i, int j) {
    int t;
    for(t = j; t > i; t--) {
        if ((a[i] + a[t]) <= s)
            break;
    }
    if (t == i) return;
    ans += t - i;
    cnt(i+1,t);
}

int main() {
    ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    cnt(0,n-1);
    cout << ans;
    return 0;
}
