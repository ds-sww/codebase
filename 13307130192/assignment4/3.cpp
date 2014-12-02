#include<iostream>
#include<stack>
#include<cstdio>
#include<set>
#include<vector>
#define For(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
const int mN=2000000;

int a[mN],v[mN],len[mN];
stack<int> st;
void renew(long long &x,long long y)
{
    if (y>x)
        x=y;
}
multiset<int> b;
vector<int> ami,ama;
void out(vector<int> &a)
{
    For(i,0,a.size()-1)
        printf("%d%c",a[i],(i==a.size()-1?'\n':' '));
}
int main()
{
    //freopen("3.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    For(i,1,n)
        scanf("%d",a+i);
    b.clear();
    For(i,1,k-1)
    {
        b.insert(a[i]);
    }
    ami.clear();
    ama.clear();
    For(i,k,n)
    {
        b.insert(a[i]);
        ami.push_back(*b.begin());
        ama.push_back(*b.rbegin());
        multiset<int>::iterator now=b.find(a[i-k+1]);
        b.erase(now);
    }
    out(ami);
    out(ama);
}

