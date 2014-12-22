#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std ;

int fa[1005] = {} ;

class Edge
{
public:
      int u , v , w ;
      bool used ;
      friend bool operator<(const Edge& x , const Edge& y)
      {
             return x.w < y.w ;
      }
      Edge()
      {
            u = v = w = 0 ;
            used = 0 ;
      }
}e[15005] ;
int cnt = 0 ;

int n , m ;

void init()
{
     scanf("%d %d",&n,&m);
     for(int i = 1 ; i <= n ; i ++)
             fa[i] = i ;
     int u , v , w ;
     for(int i = 1 ; i <= m ; i ++)
     {
             scanf("%d %d %d",&u,&v,&w);
             e[cnt].u = u ; e[cnt].v = v ; e[cnt ++].w = w ;
     }
     sort( e , e + cnt ) ;
}

int find(int x) { return (fa[x]==x)?x:(fa[x]=find(fa[x])) ;}

int kruskal()
{
    int u , v , w ;
    int num = 0 ;
    for(int i = 0 ; i < m ; i ++)
    {
            int u , v , w ;
            u = e[i].u ; v = e[i].v ; w = e[i].w ;
            int x = find(u) , y = find(v) ;
            if( x != y )
            {
                e[i].used = true ;
                fa[x] = y ;
                num ++ ;
                if( num == n - 1 )
                    return e[i].w ;
            }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    init() ;
    int ans = kruskal() ;
    
    printf("%d\n%d\n",ans,n-1);
    for(int i = 0 ; i < m ; i ++)
            if( e[i].used )
                printf("%d %d\n", e[i].u,e[i].v );
    
    return 0;
}
