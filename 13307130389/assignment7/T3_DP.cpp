//裸DP，效率不稳定，第十个点TLE
//O(n*?) ? < n
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

int near[80005] = {} ;
int height[80005] = {} ;
int n ;
int main()
{
       freopen("in.txt","r",stdin);
       freopen("out_dp.txt","w",stdout);
        while( scanf("%d",&n) == 1 )
        {
                for( int i = 1 ; i <= n ; i ++)
                        scanf("%d\n",&height[i]) ;
                height[n + 1] = 2147483647 ;
                for( int i = n ; i >= 1 ; i -- )
                {
                        near[i] = i ;
                        int j = i ;
                        while( height[i] > height[near[j]+1]) near[i] = near[j] + 1 ;
                }
                long long ans = 0 ;
                for( int i = 1 ; i <= n ; i ++)
                        ans += near[i] - i ;
                cout << ans ;
        } 
        return 0;
}