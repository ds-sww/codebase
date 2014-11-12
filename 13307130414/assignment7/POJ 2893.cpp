#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
int a[N][N];
int b[N*N],c[N*N];
int x; // 0 is in which line
int ans;

void merge (int l, int r) {
    int m = (l+r)/2;
    int i = l, j = m+1, k = l;
    while (i <= m && j <= r) {
        if (b[i] <= b[j])
            c[k++] = b[i++];
        else {
            ans += j - k;
            c[k++] = b[j++];
        }
    }
    while (i <= m)
        c[k++] = b[i++];
    while (j <= r)
        c[k++] = b[j++];
    for (i = l; i <= r; i++)
        b[i] = c[i];
}

void mergesort(int l, int r) {
    if (r <= l) return;
    int m = (l+r)/2;
    mergesort(l,m);
    mergesort(m+1,r);
    merge(l,r);
}

int main() {
    int n,m;
    int t;
    int i,j,k;
    bool flag;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) return 0;
        k = 0;
        flag = false;
        ans = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                if (a[i][j])
                    b[k++] = a[i][j];
                else
                    x = i;
            }
        mergesort(0, n*m-2);
        if (m % 2 == 1) {
            if (ans % 2 == 0)
                flag = true;
        }
        else {
            t = n - 1 - x;
            if ((ans - t) % 2 == 0)
                flag = true;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
