#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std; 

void qsort( int *a , int top , int bot )
{
        int left = top ,right = bot , temp = a[top] ;
        while( left < right )
        {
                while( left < right && a[right] > temp ) right -- ;
                a[left] = a[right ];
                while( left < right && a[left] <= temp ) left ++ ;
                a[right] = a[left] ;
        }
        a[right] = temp ;
        if( top < right - 1 ) qsort( a , top , right - 1 ) ;
        if( right + 1 < bot ) qsort( a , right + 1 , bot ) ;
}

int knights[20005] = {} , dragons[20005] = {} ;
int n , m ;

int main()
{
    while( scanf("%d %d",&n,&m) )
    {
        if( n == 0 && m == 0 ) break ;
        for( int i = 1 ; i <= n ; i ++)
                scanf("%d\n",&dragons[i]) ;
        for( int i = 1 ; i <= m ; i ++)
                scanf("%d\n",&knights[i]) ;
        
        qsort( knights , 1 , m );
        qsort( dragons , 1 , n ) ;
        
        int ans = 0 ;
        int k_tag = 1 , d_tag = 1 ;
        while( d_tag <= n && k_tag <= m )
        {
                if( knights[k_tag] >= dragons[d_tag] )
                {
                        ans += knights[k_tag] ;
                        k_tag ++ ; d_tag ++ ;
                }
                else k_tag ++ ;
        }
        
        if( k_tag > m && d_tag <= n ) printf("Loowater is doomed!\n");
        else printf("%d\n",ans) ;
             
    }
    
    return 0 ;
}

