#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std ;

int n , m ;

class Edge
{
public:
      int a , b , c ;
      int p , q ;
}e[15];
int passcnt[15] = {} ;

int ans = 99999999;

void Dfs( int cur , int tot , int sta )
{
     if( passcnt[cur] > 3 ) return ;
     if( tot > ans ) return ;
     if( cur == n )
     {
         if( tot < ans )
             ans = tot ;
         return ;
     }
     for(int i = 1 ; i <= m ; i ++)
     {
             if( cur == e[i].a )
             {
                 passcnt[e[i].b] ++ ;
                 if( (1 << (e[i].c-1)) & sta )
                     Dfs( e[i].b , tot + e[i].p , sta | (1 << (e[i].b-1)) );
                 else
                     Dfs( e[i].b , tot + e[i].q , sta | (1 << (e[i].b-1)) );
                 passcnt[e[i].b] -- ;
             }
     }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d %d",&n,&m);

    for(int i = 1 ; i <= m ; i ++)
    {
            int a , b , c , p , q ;
            scanf("%d %d %d %d %d",&a,&b,&c,&p,&q) ;
            e[i].a = a ;
            e[i].b = b ;
            e[i].c = c ;
            e[i].p = p ;
            e[i].q = q ;
    }
    Dfs( 1 , 0 , 1 ) ;
    if( ans < 99999999 )
        printf("%d",ans);
    else
        printf("impossible");
    return 0;
}
