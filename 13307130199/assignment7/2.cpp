#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define For(i,l,r) for(int i=(l),_r=(r);i<=_r;i++)
#define Rep(i,n) for(int i=0,_n=(n);i<_n;i++)

using namespace std;

const int seed=2987;
const long long mo=1e12+7;
map<long long,int>ma;
vector<int> ans;

long long ha(string s)
{
    long long ans=0;
    for(auto &c:s)
        ans=(ans*seed+c)%mo;
    return ans;
}

char s[100];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m),n)
    {
        ma.clear();
        ans.resize(n+1);
        Rep(i,n)
        {
            scanf("%s",s);
            ma[ha(s)]++;
        }
        For(i,1,n)
            ans[i]=0;
        for (auto &x:ma)
            ans[x.second]++;
        For(i,1,n)
            printf("%d\n",ans[i]);
    }
    return 0;
}
s
