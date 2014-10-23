#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#define Rep(i,n) for(int i=0,_n=(n);i<_n;i++)
#define For(i,l,r) for(int i=(l),_r=(r);i<=_r;i++)
#define rFor(i,r,l) for(int i=(r),_l=(l);i>=_l;i--)
using namespace std;

void renew(long long &x, long long y)
{
    if (y>x) x=y;
}

const int N=1e5+6;
int l[N],r[N];
bool ha[N];
vector<pair<int,int> > a;

int main()
{
    //freopen("2.in","r",stdin);
    int n,x,p,ll,rr;
    while (scanf("%d",&n),n)
    {
        a.clear();
        For(i,1,n)
        {
            scanf("%d",&x);
            a.push_back(make_pair(x,i));
            l[i]=i;
            r[i]=i;
            ha[i]=false;
        }
        ha[0]=false;
        ha[n+1]=false;
        long long ans=0;
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        Rep(i,n)
        {
            p=a[i].second;
            ha[p]=true;
            ll = (ha[p-1] ? l[p-1] : p);
            rr = (ha[p+1] ? r[p+1] : p);
            renew(ans,1LL*(rr-ll+1)*a[i].first);
            r[ll]=rr;
            l[rr]=ll;
        }
        cout << ans << endl;
    }
	return 0;
}
