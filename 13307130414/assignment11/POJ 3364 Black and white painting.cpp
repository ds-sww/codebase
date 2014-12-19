#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    //freopen("3364.txt", "r", stdin);
    int n,m,c;
    while (1) {
        cin >> n >> m >> c;
        if (n == 0 && m == 0 && c == 0) return 0;
        if (n < 8 || m < 8) {
            cout << "0" << endl;
            continue;
        }
        int ans = 0;
        if (c == 1) {
            ans = ((m-7)*(n-7)+1)/2;
        }
        else {
            ans = ((m-7)*(n-1-7)+1)/2;
            ans += (m-7)/2;
        }
        cout << ans << endl;
    }
}
