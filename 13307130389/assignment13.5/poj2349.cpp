#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std ;

int T ;
int m , n ;
const double oo = 99999999.0 ;

double dis[505] = {} ;
double tree[505] = {} ;
int tree_cnt = 0 ;
bool vis[505] = {} ;

typedef struct Node
{
        double x , y ;
};

Node nd[505] ;

double dist(const Node& a , const Node& b )
{
       return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) ) ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d",&T) ;
    while( T -- )
    {
           scanf("%d %d",&m,&n);
           tree_cnt = 0 ;
           memset( vis , false , sizeof(vis) ) ;
           for(int i = 0 ; i < n ; i ++)
           {
                   scanf("%lf %lf",&nd[i].x,&nd[i].y);
                   dis[i] = oo ;
           }
           
           dis[0] = 0 ;
           int next = 0 ;
           for(int k = 1 ; k < n ; k ++)
           {
                   for(int i = 0 ; i < n ; i ++ )
                           if( i != next && !vis[i] )
                               if( dis[i] > dist(nd[next],nd[i]) )
                                   dis[i] = dist(nd[next],nd[i]) ;
                   vis[next] = true ;
                   double minw = oo ;
                   for(int i = 0 ; i < n ; i ++ )
                           if( !vis[i] && dis[i] < minw )
                           {
                               next = i ;
                               minw = dis[i] ;
                           }
                   tree[tree_cnt ++] = minw ;
           }
           sort( dis + 1 , dis + n );
           printf("%.2f\n",dis[n-m]) ;
    }
    return 0;
}
