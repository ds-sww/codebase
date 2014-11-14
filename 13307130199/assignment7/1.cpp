#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define For(i,l,r) for(int i=(l),_r=(r);i<=_r;i++)
#define Rep(i,n) for(int i=0,_n=(n);i<_n;i++)

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    For(C,1,T)
    {
        static vector<int> a;
        int x,n;
        scanf("%d%d",&x,&n);
        a.clear();
        Rep(i,n)
        {
            int x;
            scanf("%d",&x);
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int ans=0;
        Rep(i,a.size())
            if (x>0)
            {
                ans++;
                x-=a[i];
            }
        printf("Scenario #%d:\n",C);
        if (x>0)
            puts("impossible");
        else printf("%d\n",ans);
        puts("");
    }
    return 0;
}
