#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std ;

int T , N ;
class Landmark
{
	public:
		int x ;
		Landmark() {} ;
		friend bool operator < ( const Landmark& a , const Landmark& b )
		{
			  return abs(a.x) < abs(b.x) ;
	    }
};

int main()
{
	cin >> T >> N ;
	Landmark *ldm ;
	ldm = new Landmark[N+1] ;
	int ans = 0 ;
	for( int i = 1 ; i <= N ; i ++ )
		cin >> ldm[i].x ;
	ldm[0].x = 0 ;
	
	sort( ldm , ldm + N + 1 ) ;
	
	while( T >= 0 ) { ans ++ ; T -= abs( ldm[ans].x - ldm[ans-1].x ) ; }
	ans -- ;
	
	cout << ans ;
	
	return 0;
}

