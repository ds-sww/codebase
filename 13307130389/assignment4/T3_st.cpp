#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

int n , k ;
int st[1000001][21] = {} ;

inline int max( int a , int b ) { return a>b?a:b;}
inline int min( int a , int b ) { return a>b?b:a;}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d %d\n",&n,&k);
    for( int i = 1 ; i <= n ; i ++ )
    {
         scanf("%d",&st[i][0]) ;
    }
    
    for( int i = 1 ; (1<<i) <= n ; i ++ )
    {
         for( int j = 1 ; j <= ( n - (1<<i) + 1 ) ; j ++ )
         {
              st[j][i] = min( st[j][i-1] , st[j + (1 << (i-1))][i-1] ) ;
         }
    }
    

    int length = 0 ;
    while( ( 1 << length+1 ) <= k ) length ++ ;
    for( int i = 1 ; i <= n - k + 1 ; i ++ )
    {
         printf("%d",min( st[i][length] , st[i + k - (1<<length)][length] ) );
         if( i < n-k+1 ) printf(" ");
    }
    printf("\n");
    
    for( int i = 1 ; (1<<i) <= n ; i ++ )
    {
         for( int j = 1 ; j <= ( n - (1<<i) + 1 ) ; j ++ )
         {
              st[j][i] = max( st[j][i-1] , st[j + (1 << (i-1))][i-1] ) ;
         }
    }
    
    for( int i = 1 ; i <= n - k + 1 ; i ++ )
    {
         printf("%d",max( st[i][length] , st[i + k - (1<<length)][length] ) );
         if( i < n-k+1 ) printf(" ");
    }
    printf("\n");
    return 0 ;
}
