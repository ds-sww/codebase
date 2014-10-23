#include<iostream>
#include<stack>
#include<cstdio>
#define For(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
const int mN=200000;

int a[mN],v[mN],len[mN];
stack<int> st;
void renew(long long &x,long long y)
{
    if (y>x)
        x=y;
}
int main()
{
    //freopen("2.in","r",stdin);
    int n;
    while (scanf("%d",&n),n!=0)
    {
        For(i,1,n)
            scanf("%d",a+i);
        a[n+1]=0;
        int tst=0;
        long long ans=0;
        For(i,1,n+1)
        {
            int left=0;
            while (tst>0 && v[tst]>=a[i])
            {
                renew(ans,1LL*v[tst]*(len[tst]+left));
                left+=len[tst];
                tst--;
            }
            tst++;
            len[tst]=1+left;
            v[tst]=a[i];
        }
        printf("%lld\n",ans);
    }
}
