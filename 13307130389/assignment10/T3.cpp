#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>

typedef __int64 LL;

using namespace std ;
int t ;
LL n , m ;

bool check( LL key )
{
	LL cnt = 0 ;
	for( LL j = 1 ; j <= n ; j ++)
	{
	       LL l = 1 , r = n ;
	       LL mid ;
	       LL tempmid = 0;
	       while( l <= r )
	       {
	       	     mid = (l + r) >> 1 ;
	       	     LL num = mid*mid + 100000*mid + j*j - 100000*j + mid*j ;
	       	     if( key >= num )
	       	     {
	       	          tempmid = mid ;
	       	     	  l = mid + 1 ;
	       	     }
	       	     else 
	       	     	r = mid - 1 ;
	       }
	       cnt += tempmid ;
	}
	if( cnt >= m ) return true ;
	else return false ;
}

void work()
{
	LL left = -99999999999999999LL , right = 99999999999999999LL ;
	LL ans = 0 ;
	LL mid = 0 ;
	while( left <= right )
	{
		mid = (left + right) >> 1 ;
		if( check(mid) )
		{
			ans = mid ;
			right = mid - 1 ;
		}
		else 
			left = mid + 1 ;
	}
	cout << ans << endl ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	cin >> t ;
	for( int i = 1 ; i <= t ; i ++)
	{
		cin >> n >> m ;
		work() ;
	}
	
	return 0;
}
