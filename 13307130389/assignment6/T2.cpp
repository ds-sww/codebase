#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std; 

void qsort( int *a , int top , int bot )
{
        int left = top ,right = bot , temp = a[top] ;
        while( left < right )
        {
                while( left < right && abs(a[right]) > abs(temp) ) right -- ;
                a[left] = a[right ];
                while( left < right && abs(a[left]) <= abs(temp) ) left ++ ;
                a[right] = a[left] ;
        }
        a[right] = temp ;
        if( top < right - 1 ) qsort( a , top , right - 1 ) ;
        if( right + 1 < bot ) qsort( a , right + 1 , bot ) ;
}

int a[50002] = {} ;

int main()
{
        int ans = 0 ;
        int T , N ;
        cin >> T >> N ;
        a[0] = 0 ;
        for( int i = 1 ; i <= N ; i ++)
                scanf("%d",&a[i]) ;
        
        qsort( a , 0 , N );
        
        while( T >= 0 ) { ans ++ ; T -= abs( a[ans] - a[ans-1] ) ; }
        ans -- ;
        cout << ans ;
        return 0;
}
