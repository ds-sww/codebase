#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int N = 130;
const int seed = 29;
const int maxn = 100005;
long long ans;
char matrix[N][N];
long long h[N][N];
map <long long, int> M;

int sa[maxn], Rank[maxn], r[maxn], height[maxn];
int wa[maxn], wb[maxn], wv[maxn], ww[maxn];

int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb,*t;
    for (i = 0; i < m; i++) ww[i] = 0;
    for (i = 0; i < n; i++) ww[x[i]=r[i]]++;
    for (i = 1; i < m; i++) ww[i] += ww[i-1];
    for (i = n-1; i >= 0; i--) sa[--ww[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2,m = p) {
        for (p = 0, i = n-j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < m; i++) ww[i] = 0;
        for (i = 0; i < n; i++) ww[wv[i]]++;
        for (i = 1; i < m; i++) ww[i] += ww[i-1];
        for (i = n-1; i >= 0; i--) sa[--ww[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1:p++;
    }
    return;
}

void calheight(const int *r, int *sa, int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; height[Rank[i++]] = k)
        for (k ? k--:0, j = sa[Rank[i]-1]; r[i+k] == r[j+k]; k++);
    return;
}

int main() {
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> matrix[i];
        memset(h, 0, sizeof(h));
        ans = 0;
        for (int w = 1; w <= m; w++) {
            int temp = 1;
            int cnt = 0;
            M.clear();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j+w-1 < m; j++) {
                    h[i][j] = h[i][j]*seed + matrix[i][j+w-1] - 'A';
                    if (M.find(h[i][j]) == M.end())
                        M.insert(make_pair(h[i][j], temp++));
                }
            }
            for (int j = 0; j+w-1 < m; j++) {
                for (int i = 0; i < n; i++)
                    r[cnt++] = M[h[i][j]];
                r[cnt++] = temp++;
            }
            r[cnt] = 0;
            da(r, sa, cnt+1, temp);
            calheight(r, sa, cnt);
            long long t = (n*(n+1)/2) * (m-w+1);
            for (int i = 1; i <= cnt; i++)
                t -= height[i];
            ans += t;
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
}
