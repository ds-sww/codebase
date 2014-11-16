#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct child
{
    int l,r;
};
const int MAXN = 10010;
child a[MAXN];
int s[MAXN],d[MAXN];
int top;

void post(int x)
{
    int i = x;
    while (top > 0)
    {
        i = top - 1;
        if (d[i] == 1)
        {
            printf("%d ",s[i]);
            top--;
        }
        else
        {
            if (a[s[i]].r != -1)
            {
                s[top++] = a[s[i]].r;
            }
            if (a[s[i]].l != -1)
            {
                s[top++] = a[s[i]].l;
            }
            d[i] = 1;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(d,0,sizeof(d));
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        scanf("%d %d",&a[x].l,&a[x].r);
    }
    //
    int root = 0;
    scanf("%d",&root);

    top = 0;
    s[top++] = root;
    post(root);
    printf("\n");
    return 0;
}

