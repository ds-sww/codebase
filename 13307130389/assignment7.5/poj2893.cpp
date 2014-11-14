#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

inline int lowbit( int k )
{
	return k&(-k);
}

int bit[1000005] = {} ;
int num[1000005] = {} ;
int n , m ;
int x0,y0 ;
void add( int k , int toadd )
{
	while( k <= n*m )
	{
		bit[k] += toadd ;
		k += lowbit(k) ;
	}
}
int search( int k )
{
	int ans = 0 ;
	while( k > 0 )
	{
		ans += bit[k] ;
		k -= lowbit(k) ;
	}
	return ans ;
}

int getInt()
{
	char c ;
	while( (c=getchar()) < '0' || c > '9' ) ;
	int cnt = c - '0' ;
	while( (c = getchar()) >= '0' && c <= '9' )
	{
		cnt = cnt * 10 + c -'0' ;
	}
	return cnt ;
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);

	while( scanf("%d %d\n",&n,&m) == 2 )
	{
		if( n == 0 && m == 0 ) break ;
		
		int cnt = 0 ;
		memset( bit , 0 , sizeof(bit) ) ;
		for( int i = 1 ; i <= n ; i ++)
			for( int j = 1 ; j <= m ; j ++)
			{
				num[(i-1)*m+j] = getInt() ;
				if( num[(i-1)*m+j] == 0 )
				{
					x0 = i ; y0 = j ;
				}
			}
		
		for( int i = m*n ; i >= 1 ; i -- )
		{
			if( num[i] == 0 ) continue ;
			cnt += search( num[i]-1 ) ;
			add( num[i] , 1 ) ;
		}
		
		bool succeed = false ;
		if( m % 2 && cnt % 2 == 0 )
		{
			succeed = true ;
		}
		else if( m % 2 == 0 && ((n-x0)+cnt) % 2 == 0 )
		{
			succeed = true ;
		}
		
		if( succeed )
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
		
		
