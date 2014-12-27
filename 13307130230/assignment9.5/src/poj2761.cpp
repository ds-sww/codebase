#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cassert>
using namespace std;
#define Rep(i,n) for (int i=0;i<(n);i++)
#define For(i,l,r) for (int i=(l);i<=(r);i++)
#define PB push_back
#define MP make_pair
#include "rbtree.h"

struct Node
{
    int x,y,z,id;
}p[200005];
int n,Q,l,r;
int a[200005],ans[200005];

bool cp(Node u,Node v)
{
    return u.x<v.x;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d%d",&n,&Q);
    For(i,1,n) scanf("%d",&a[i]);
    Rep(i,Q)
    {
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        p[i].id=i;
    }
    sort(p,p+Q,cp);
    l=0; r=0;
    RBTREE RBtree;
    Rep(i,Q)
    {
        while (r<p[i].y) RBtree.insert(a[++r]);
        while (l+1<p[i].x) RBtree.erase(a[++l]);
        ans[p[i].id]=RBtree.Find_kth(p[i].z);
    }
    Rep(i,Q) printf("%d\n",ans[i]);
    return 0;
}
