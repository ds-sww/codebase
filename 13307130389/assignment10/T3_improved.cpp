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
	       LL delta = (100000+j)*(100000+j) - (((j-100000)*j-key)<<2) ;
	       if( delta < 0 ) 
	           continue ;
	       LL sqrd = (LL)sqrt((long double)delta) ;
	       LL tempc = sqrd - 100000 - j ;
	       tempc >>= 1 ;
	       if( tempc > 0 )
           {
                if( tempc <= n )
                    cnt += tempc ;
                else cnt += n ;
           }
	}
	if( cnt >= m ) return true ;
	else return false ;
}

void work()
{
	LL left = -7500000001LL , right = 7500000001LL ;
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
