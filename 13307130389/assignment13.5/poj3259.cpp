#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std ;

const int oo = 99999999 ;

class Edge
{
public:
      int u , v , w ;
}e[5500] ;
int dis[505] = {} ;
int cnt = 0 ;
int F ;
int n , m , ww ;

void init()
{
     scanf("%d %d %d",&n,&m,&ww);
     int u , v, w ;
     cnt = 0 ;
     for(int i = 1 ; i <= n ; i ++)
             dis[i] = oo ;
     for(int i = 0 ; i < m ; i ++)
     {
             scanf("%d %d %d",&u,&v,&w) ;
             e[cnt].u = u ; e[cnt].v = v ; e[cnt ++].w = w;
             e[cnt].u = v ; e[cnt].v = u ; e[cnt ++].w = w;
     }
     for(int i = 0 ; i < ww ; i ++)
     {
             scanf("%d %d %d",&u,&v,&w) ;
             e[cnt].u = u ; e[cnt].v = v ; e[cnt ++].w = -w ;
     }
}

bool BellmanFord()
{
     dis[1] = 0 ;
     for(int i = 0 ; i < n - 1 ; i ++)
     {
             bool ok = false ;
             for(int j = 0 ; j < cnt ; j ++)
                     if( dis[e[j].u] > dis[e[j].v] + e[j].w )
                     {
                         dis[e[j].u] = dis[e[j].v] + e[j].w ;
                         ok = true ;
                     }
             if( !ok ) break ;
     }
     for(int j = 0 ; j < cnt ; j ++)
             if( dis[e[j].u] > dis[e[j].v] + e[j].w )
                 return false ;
     return true ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d",&F);
    while( F -- )
    {
           init() ;
           
           if( BellmanFord() )
               printf("NO\n");
           else
               printf("YES\n");
    }
    
    return 0;
}
