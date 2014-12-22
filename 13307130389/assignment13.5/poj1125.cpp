#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>

using namespace std;

const int oo = 99999999 ;

int f[100][100] = {} ;
int n , d[100] ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( scanf("%d",&n) == 1 )
    {
           if(n == 0) break ;
           
           for(int i = 1 ; i <= n ; i ++)
                   for(int j = 1 ; j <= n ; j ++)
                           f[i][j] = oo ;
           
           for(int u = 1 ; u <= n ; u ++)
           {
                   int c , v , w ;
                   scanf("%d",&c);
                   while(c --)
                   {
                           scanf("%d %d",&v,&w);
                           if( f[u][v] > w )
                               f[u][v] = w ;
                   }
           }
           
           for(int k = 1 ; k <= n ; k ++)
                   for(int i = 1 ; i <= n ; i ++)
                           for(int j = 1 ; j <= n ; j ++)
                                   if( f[i][j] > f[i][k] + f[k][j] )
                                       f[i][j] = f[i][k] + f[k][j] ;
           
           int ii , ans = oo ;
           for(int i = 1 ; i <= n ; i ++)
           {
                 int tans = -1 ;
                 for(int j = 1 ; j <= n ; j ++) if( j != i )
                 {
                         if( f[i][j] > tans ) 
                             tans = f[i][j] ;
                         if( f[i][j] >= oo )
                             { tans = -1 ; break ;}
                 }
                 if( tans >= 0 && tans < ans ) {ii = i ; ans = tans ;}
           }
           if( ans < oo )
               printf("%d %d\n",ii , ans );
           else
               printf("disjoint\n");
    }
    return 0;
}
