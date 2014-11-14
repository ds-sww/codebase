#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>

using namespace std ;

int n , k ;
int a[100005] = {} ;

void qsort( int *a , int top , int bot )
{
        int left = top , right = bot , temp = a[top] ;
        while( left < right )
        {
                while( left < right && a[right] > temp ) right -- ;
                a[left] = a[right] ;
                while( left < right && a[left] <= temp ) left ++ ;
                a[right]= a[left] ;
        }
        a[right] = temp ;
        if( top < right - 1 ) qsort( a , top , right - 1 ) ;
        if( right + 1 < bot ) qsort( a , right + 1 , bot ) ;
}

int main()
{
        char c[10] = {} ;
        cin >> n ;
        for( int i = 1 ; i <= n ; i ++)
                scanf("%d",&a[i]) ;
        scanf("%s\n",c) ;
        qsort( a , 1 , n ) ;
        cin >> k ;
        
        for( int i = 1 ; i <= k ; i ++)
        {
                int tt ;
                cin >> tt ;
                printf("%d\n",a[tt] ) ;
        }
        return 0 ;
}
