#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define For(i,l,r) for(int i=(l),_r=(r);i<=_r;i++)
#define Rep(i,n) for(int i=0,_n=(n);i<_n;i++)

using namespace std;

int main()
{
    static vector<pair<int,int> >a;
    set<int> have;
    int n;
    scanf("%d",&n);
    Rep(i,n)
    {
        int x;
        scanf("%d",&x);
        a.push_back(make_pair(x,i));
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    have.insert(n);
    long long ans=0;
    for (auto &x:a)
    {
//        cout << x.first <<' ' << x.second << endl;
        ans+=*have.upper_bound(x.second)-x.second-1;
        have.insert(x.second);
    }
    cout << ans << endl;
}

