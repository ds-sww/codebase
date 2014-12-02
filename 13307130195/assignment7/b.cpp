#include <map>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[30];
int t[300], ans[21000];

int main()
{
   // freopen("a.in", "r", stdin);

    t['A'] = 0;
    t['C'] = 1;
    t['G'] = 2;
    t['T'] = 3;

    int hs, n, m;

    while (scanf("%d %d\n", &n, &m))
    {
        if (n == 0 && m ==0) break;
        map<int, int> mp;

        for (int i = 0; i < n; i++){
            scanf("%s\n", s);
            hs = 0;
            for (int j = 0; j < m; j++)
            {
                hs = hs * 4 + t[s[j]];
            }
            mp[hs] ++;
        }
        memset(ans, 0 ,sizeof(ans));
        for (auto i = mp.begin(); i != mp.end(); i++) ans[i->second] ++;
        for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    }

    return 0;
}