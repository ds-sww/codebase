#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std ;

int n , s ;
int a[20005] = {} ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    ios::sync_with_stdio(false) ;
    
    cin >> n >> s ;
    for( int i = 0 ; i < n ; i ++)
         cin >> a[i] ;
    sort( a , a + n ) ;
    
    int left = 0 , right = n - 1 ;
    int ans = 0 ;
    while( left < right )
    {
           while( a[left] + a[right] > s ) right -- ;
           if( left >= right ) break ;
           ans += right - left ;
           left ++ ;
    }
    cout << ans ;
    
    return 0;
}
