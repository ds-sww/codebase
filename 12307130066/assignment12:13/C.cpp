#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
int father[550], m, k;
double d[550];

struct post
{
        double x, y;
}p[550];

struct edge
{
        int u, v;
        double w;
}e[500005];

bool comp(edge e1, edge e2)
{
        return  e1.w < e2.w;
}

double get_dis(double x1, double y1, double x2, double y2)
{
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void Init(int n)
{
        for(int i = 1; i <= n; i++)
                father[i] = i;
}

int Find(int x)
{
        if(x != father[x])
                father[x] = Find(father[x]);
        return father[x];
}

void Merge(int a, int b)
{
        int p = Find(a);
        int q = Find(b);
        if(p > q)
                father[p] = q;
        else
                father[q] = p;
}

void Kruskal(int n)
{
        k = 0;
        double Max = 0;
        for(int i = 0; i < m; i++)
                if(Find(e[i].u) != Find(e[i].v))
                {
                        Merge(e[i].u, e[i].v);
                        d[k++] = e[i].w;
                        n--;
                        if(n == 1)
                                return;
                }
}

int main()
{
        int t, S, P, i, j;
        double x, y;
        scanf("%d",&t);
        while(t--)
        {
                m = 0;
                scanf("%d%d",&S,&P);
                Init(P);
                for(i = 1; i <= P; i++)
                        scanf("%lf%lf",&p[i].x, &p[i].y);
                for(i = 1; i <= P; i++)
                        for(j = i + 1; j <= P; j++)
                        {
                                e[m].u = i;
                                e[m].v = j;
                                e[m++].w = get_dis(p[i].x, p[i].y, p[j].x, p[j].y);
                                e[m].u = j;
                                e[m].v = i;
                                e[m++].w = get_dis(p[i].x, p[i].y, p[j].x, p[j].y);
                        }
                sort(e, e+m, comp);
                Kruskal(P);
                printf("%.2lf\n",d[P-S-1]);
        }
        return 0;
}