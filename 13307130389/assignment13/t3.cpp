#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<sstream>
#include<cmath>

using namespace std ;
const double oo = 99999999 ;
double dis[505] = {} ;
bool vis[505] = {} ;
double nd[505][2] = {} ;
double res[505] = {} ;
int rescnt = 0 ;
int s , n ;

double dist( int x , int y )
{
        return sqrt( (nd[x][0]-nd[y][0])*(nd[x][0]-nd[y][0])+(nd[x][1]-nd[y][1])*(nd[x][1]-nd[y][1]) ) ;
}

int main()
{
        int T ;
        scanf("%d",&T);
        while(T --)
        {
                memset(vis,false,sizeof(vis)) ;
                rescnt = 0 ;
                scanf("%d %d",&s,&n) ;
                for(int i = 1 ; i <= n ; i ++)
                        scanf("%lf %lf",&nd[i][0],&nd[i][1]) ;
                for(int i = 1 ; i <= n ; i ++)
                        dis[i] = oo ;
                
                dis[1] = 0 ; vis[1] = true ;
                int next = 1 ;
                for(int i = 1 ; i < n ; i ++)
                {
                        double mindis = oo ;
                        for( int j = 1 ; j <= n ; j ++ ) if( j != i && !vis[j] )
                                if( dis[j] > dist(next,j) )
                                {
                                        dis[j] = dist(next,j) ;
                                }
                        vis[next] = true ;
                        for( int j = 1 ; j <= n ; j ++ ) if( !vis[j] )
                                if( dis[j] < mindis )
                                {
                                        mindis = dis[j] ;
                                        next = j ;
                                }
                        res[++ rescnt] = mindis ;
                }
                sort( res + 1 , res + n ) ;
                printf("%.2f\n",res[n-s]);
         }
         
        return 0;
}

