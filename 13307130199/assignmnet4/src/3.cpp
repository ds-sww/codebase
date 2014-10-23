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

const int N=1e6+5;
priority_queue<pair<int,int> > tma,tmi;
int a[N];
vector<int> ans1,ans2;

int main()
{
    //freopen("3.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    Rep(i,n)
        scanf("%d",a+i);
    Rep(i,min(n-1,k-1))
    {
        tma.push(make_pair(a[i],i));
        tmi.push(make_pair(-a[i],i));
    }
    For(i,min(n-1,k-1),n-1)
    {
        tma.push(make_pair(a[i],i));
        tmi.push(make_pair(-a[i],i));
        while (tma.top().second<=i-k) tma.pop();
        while (tmi.top().second<=i-k) tmi.pop();
        ans1.push_back(-tmi.top().first);
        ans2.push_back(tma.top().first);
    }
    Rep(i,ans1.size())
        printf("%d%c",ans1[i],i==ans1.size()-1?'\n':' ');
    Rep(i,ans2.size())
        printf("%d%c",ans2[i],i==ans2.size()-1?'\n':' ');
	return 0;
}
