#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
    int n,l,r,h;
};
const int MAXN = 10;
node a[MAXN];
int p[MAXN];
int n;
bool check1(int x)
{
    if ((a[x].l == -1) || (a[x].r == -1)) return false;
    return true;
}

bool check2(int x)
{
    if ((n > (a[x].n + 1) * 2 - 1) && (a[x].l == -1)) return false;
    if ((n > (a[x].n + 1) * 2) && (a[x].r == -1)) return false;
    //if (a[x + 1].l != -1 && a[x].l == -1) return false;
    //if (a[x + 1].r != -1 && a[x].r == -1) return false;
    if (a[x].l == -1 && a[x].r != -1) return false;
    return true;
}

bool check3(int x)
{
    if (a[x].l !=-1 || a[x].r != -1) return false;
    return true;
}

bool order(int x)
{
    int h,t;
    int tmp = 1;
    int now = 0;
    int sum = 0;
    h = 0;
    t = 1;
    while (h < t)
    {
        int x = p[h];
        a[x].n = h;
        if (h > sum)
        {
            now++;
            tmp *= 2;
            sum += tmp;
        }
        a[x].h = now;
        if (a[x].l != -1)
        {
            p[t++] = a[x].l;
        }
        if (a[x].r != -1)
        {
            p[t++] = a[x].r;
        }
        h++;
    }
    for (int i = 0; i < t; i++)
    {
        if (a[p[i]].h < now - 1)
        {
            if (!check1(p[i])) return false;
        }
        if (a[p[i]].h == now - 1)
        {
            if (!check2(p[i])) return false;
        }
        if (a[p[i]].h == now)
        {
            if (!check3(p[i])) return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    bool ok = true;
    for (int i = 0; i  < n; i++)
    {
        int x;
        scanf("%d",&x);
        scanf("%d %d",&a[x].l,&a[x].r);
        if (a[x].l == -1 && a[x].r != -1) ok = false;
    }
    int root;
    scanf("%d",&root);
    p[0] = root;
    if (ok) ok = order(root);
    if (ok) printf("Complete Binary Tree.\n");
    else printf("Not Complete Binary Tree.\n");
    return 0;
}

