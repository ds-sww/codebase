/**
 * @author whimsycwd
 * @date   2014.11.2
 *
 */

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


int n,m;

void work() {
    int * geeses = new int[n];
    int * knights = new int[m];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &geeses[i]);
    }    
    for (int i = 0; i < m; ++i) {
        scanf("%d", &knights[i]);
    }

    sort(geeses, geeses + n);
    sort(knights, knights + m);

    int gp = 0;
    int kp = 0;
    int ans = 0;

    while (gp < n && kp < m) {
        while (kp < m && knights[kp] < geeses[gp]) ++kp;
        if (kp < m) {
            ++gp;
            ans += knights[kp++];
        }
    }

    if (gp == n) {
        cout << ans << endl;
    } else {
        cout << "Loowater is doomed!" << endl; 
    }

    delete [] geeses;
    delete [] knights; 
}

int main() {

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        work();
    }
    return 0;
}
