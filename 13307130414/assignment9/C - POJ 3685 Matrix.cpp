#include <iostream>
#include <cmath>
using namespace std;

int cas;
long long n,m;

bool check(long long mid) {
    long long cnt = 0;
    for (long long j = 1; j <= n; j++) {
        long long delta,i;
        delta = (100000+j) * (100000+j) - 4 * (j*j - 100000*j - mid);
        //cout << "delta = " << delta << endl;
        if (delta >= 0) {
            i = ((long long)sqrt((double)delta)-100000-j)/2;
            //cout << "i = " << i << endl;
            if (i >= n)
                cnt += n;
            else if (i > 0)
                cnt += i;
        }
    }
    //cout << "cnt = " << cnt << endl;
    if (cnt < m)
        return true;
    else
        return false;
}

int main() {
    cin >> cas;
    while (cas--) {
        cin >> n >> m;
        long long l = -100000*n, r = 3*n*n + 100000*n;
        while (l < r) {
            long long mid = (l+r) >> 1;
            //cout << "mid = " << mid << endl;
            if (check(mid))
                l = mid+1;
            else
                r = mid;
        }
        cout << l << endl;
    }
    return 0;
}
