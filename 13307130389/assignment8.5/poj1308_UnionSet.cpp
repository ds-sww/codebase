#include<cstdio>
#include<cstring>
#include<stack>

using namespace std ;

const int END = 0 ;
const int SUCCEED = 1 ;
const int FAIL = 2 ;

int pa[100005] = {} ;
bool  vis[100005] = {} ;
int n ;
int actualn = 0 ;

int init()
{
     n = 0 ;
     int x , y ;
     int tag = 0 ;
     int fanin0 = 0 ;
     actualn = 0;
     memset( pa , 0 , sizeof(pa)) ;
     memset( vis , false , sizeof(vis)) ;
     while( scanf("%d %d" , &x , &y ) == 2 )
     {
            if( x < 0 && y < 0 )
                return END ;
            if( x == 0 && y == 0 )
                break ;
            if( x == y ) tag = FAIL ;
            if( pa[y] ) tag = FAIL ;            
            pa[y] = x ;
            if( n < x ) n = x ;
            if( n < y ) n = y ;
            vis[x] = vis[y] = true ;
     }
     if( tag == FAIL ) return tag ;
     for( int i = 1 ; i <= n ; i ++)
          if( vis[i] )
          {
              actualn ++ ;
              if( pa[i] == 0 ) fanin0 ++ ;
          }
     if( fanin0 > 1 ) return FAIL ;
     return true ;
}
/*
int find( int x )
{
    return (fa[x] == x)?( x ):( fa[x] = find(fa[x]) ) ;
}            
*/
int find( int x )
{
    if( pa[x] == x )
    {
         return pa[x] ;
    }
    stack<int> T_T ;
    while( pa[x] != x )
    {
           T_T.push( x ) ;
           x = pa[x] ;
           if( T_T.size() > actualn )
           {
               throw(x);
               return -1;
           }
    }
    while( !T_T.empty() )
    {
           pa[T_T.top()] = x ;
           T_T.pop() ;
    }
    return x ;
}
           
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int sta , cas = 0 ;
start:
    while( (sta = init()) )
    {
           cas ++ ;
           if( n == 0 )
           {
               printf("Case %d is a tree.\n",cas);
               continue ;
           }
           if( sta == END ) break ;
           if( sta == FAIL )
           {
               printf("Case %d is not a tree.\n",cas) ;
               continue ;
           }
           for( int i = 1 ; i <= n ; i ++ )
                if( vis[i] )
                {
                     try{ pa[i] = find(i) ; }
                     catch( int )
                     {
                            printf("Case %d is not a tree.\n",cas) ;
                            goto start ;
                     }
                }
           int temp = 0 ; 
           int i ;
           for( i = 1 ; i <= n ; i ++ )
                if( vis[i] )
                {
                    if( find(i) != 0 )
                        break ;
                }
           if( i > n ) printf("Case %d is a tree.\n",cas);
           else printf("Case %d is not a tree.\n",cas);
    }
    return 0;
}
