#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int a[110000];

int main()
{
   // freopen("a.in", "r", stdin);

    int T, i, n, m;

    scanf("%d", &T);
    for (int s = 1; s <= T; s++)
    {
        scanf("%d %d", &n, &m);
        for (i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
            a[i] = -a[i];
        }

        sort(a, a+m);
        for (i = 0; i < m; i++)
        {
            if (n > 0) n += a[i];
            else break;
        }

        printf("Scenario #%d:\n",s);
        if (n > 0) printf("impossible\n");
        else printf("%d\n", i);
        printf("\n");
    }
    return 0;
}
