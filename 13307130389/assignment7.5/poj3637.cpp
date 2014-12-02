#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std ;

int T ;
int n ;
int a[20005] = {} ;

int main()
{
	cin >> T ;
	while( T -- )
	{
		int discount = 0 ;
		cin >> n ;
		for( int i = 1 ; i <= n ; i ++ )
			scanf("%d",&a[i]);
		
		sort( a + 1 , a + 1 + n ) ;
		
		for( int i = n ; i >= 1 ; i -- )
			if( (n - i + 1) % 3 == 0 )
				discount += a[i] ;
		
		printf("%d\n",discount) ;
	}
	return 0;
}
