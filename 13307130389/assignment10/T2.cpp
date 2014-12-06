#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std ;

int n , s ;
int a[20005] = {} ;

int main()
{
	cin >> n >> s ;
	
	for( int i = 1 ; i <= n ; i ++)
		cin >> a[i] ;
	
	sort( a + 1 , a + n + 1 ) ;
	int left = 1 , right = n ;
	long long ans = 0 ;
	while( left < right )
	{
		while( a[right] + a[left] > s ) right -- ;
		if( left < right ) ans += right - left ;
		left ++ ;
	}
	
	cout << ans ;
	
	return 0;
}
