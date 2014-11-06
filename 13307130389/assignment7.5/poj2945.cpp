#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std ;

class String
{
public:
	char str[31] ;
	String() {} 
	friend bool operator < ( const String& a , const String& b )
	{
		return (strcmp(  a.str, b.str ) < 0 );
	}
	friend bool operator == ( const String& a , const String& b )
	{
		return ( strcmp( a.str , b.str ) == 0 ) ;
	}
	friend bool operator > ( const String& a , const String& b )
	{
		return (strcmp(  a.str, b.str ) > 0 );
	}
	friend bool operator <= ( const String& a , const String& b )
	{
		return (strcmp(  a.str, b.str ) <= 0 );
	}
};

String st[20005] ;
int cnt[20005] = {} ;
int n , m ;

void qsort( int top , int bot ) 
{
	int left = top , right = bot ;
	String temp = st[top] ;
	while( left < right )
	{
		while( left < right && st[right] > temp ) right -- ;
		st[left] = st[right] ;
		while( left < right && st[left] <= temp ) left ++ ;
		st[right] = st[left] ;
	}
	st[right] = temp ;
	if( top < right - 1 ) qsort( top , right - 1 ) ;
	if( right + 1 < bot ) qsort( right + 1 , bot ) ;
}

int main()
{
	while( scanf("%d %d",&n,&m) == 2 )
	{
		if( n == 0 && m == 0 ) break ;
		memset( cnt , 0 , sizeof(cnt) ) ;
		for( int i = 1 ; i <= n ; i ++ )
			scanf("%s",st[i].str ) ;
		
		int count = 1 ;
		qsort( 1 , n ) ;
		for( int i = 1 ; i < n ; i ++ )
		{
			if( st[i] == st[i+1] ) count ++ ;
			else
			{
				cnt[ count ] ++ ;
				count = 1 ;
			}
		}
		cnt[ count ] ++ ;
		
		for( int i = 1 ; i <= n ; i ++)
			printf("%d\n", cnt[i] ) ;
		printf("\n");
	}
	return 0;
}
