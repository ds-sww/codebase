#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std ;

int n ;
long long m ;
int a[100005] = {} ;

bool check( int key )
{
     long long cnt = 0 ;
     for( int i = 1 ; i <= n ; i ++)
     {
          int left = i , right = n , mid ;
          int ti = (left + right) >> 1 ;
          while( left <= right )
          {
                 mid = (left + right) >> 1 ;
                 if( a[mid] - a[i] <= key )
                 {
                     ti = mid ;
                     left = mid + 1 ;
                 }
                 else
                     right = mid - 1 ;
          }
          cnt += ti - i ;
     }
     if( cnt >= m ) return true ;
     else return false ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    ios::sync_with_stdio(false) ;
    int ans = 0 ;
    while( scanf("%d",&n) == 1 )
    {
           if( n * (n - 1) % 4 == 0 )
               m =  n * (n - 1) / 4;
           else 
               m =  n * (n - 1) / 4 + 1;
           
           for( int i = 1 ; i <= n ; i ++)
                scanf("%d",&a[i]);
           sort( a + 1 , a + 1 + n ) ;
           
           int low = 1 , high = a[n] - a[1] ;
           
           while( low <= high )
           {
                  int mid = (low + high) >> 1 ;
                  
                  if( check(mid) )
                  {
                      ans = mid ;
                      high = mid - 1 ;
                  }
                  else
                      low = mid + 1 ;
           }
           
           cout << ans << endl ;
    }
    
    return 0;
}
