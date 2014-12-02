//ST实现RMQ二分区间长度 O(nlogn)
 #include<cstdio>
 #include<cstring>
 #include<iostream>
 #include<cstdlib>
 
 using namespace std ;
 
 int n ;
 int st[80003][17] = {} ;
 
 inline int max( int a , int b )
 {
        if( a > b ) return a ;
        return b;
 }
 
 int RMQ_MAX( int left , int right )
 {
     int len = right - left + 1 ;
     int k = 0 ;
     while( (1 << k) <= len ) k ++ ;
     k -- ;
     return max( st[left][k] , st[right - (1 << k) + 1][k] ) ;
 }
 
 int main()
 {
     freopen("in.txt","r",stdin);
     freopen("out_st.txt","w",stdout);
     
     long long ans = 0 ;
     scanf("%d",&n);
     for( int i = 1 ; i <= n ; i ++)
          scanf("%d",&st[i][0]) ;
     st[n+1][0] = 2147483647 ;
     for( int i = 1 ; (1 << i) <= n ; i ++)
          for( int j = 1 ; j <= n - ( 1 << i ) + 1 ; j ++)
               st[j][i] = max( st[j][i-1] , st[j + ( 1 << (i - 1))][i-1] ) ;
     
     for( int i = 1 ; i <= n ; i ++)
     {
          int left , right , mid ;
          left = i + 1 ; right = n + 1 ; mid = ( left + right ) >> 1 ;
          while( left < right )
          {
                 if( RMQ_MAX( left , mid ) >= st[i][0] )
                     right = mid ;
                 else
                 {
                     left = mid + 1 ;
                     right = ( right + (n+1) ) >> 1 ;
                 }
                 mid = ( left + right ) >> 1 ;
          }
          ans += mid - i - 1;
     }
     
     cout << ans ;
 }