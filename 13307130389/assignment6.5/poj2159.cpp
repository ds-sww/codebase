#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std ;

int bucket[30] = {} ;
int bucket_dst[30] = {} ;

char src[1003] = {} , dst[1003] = {} ;

int main()
{
	scanf("%s\n%s",dst , src );
	for( int i = 0 ; i < strlen(dst) ; i ++ )
		bucket_dst[ dst[i] - 'A' ] ++ ;
	sort( bucket_dst , bucket_dst + 26 ) ;
	
	int step ;
	for( step = 0 ; step < 26 ; step ++ )
	{
		int i ;
		memset( bucket , 0 , sizeof(bucket) );
		
		for(i = 0 ; i < strlen(src) ; i ++ )
			bucket[ (src[i] - 'A' + step) % 26 ] ++ ;
		sort( bucket , bucket + 26 ) ;
		
		for(i = 0 ; i < 26 ; i ++)
			if( bucket[i] != bucket_dst[i] )
				break ;
		if( i == 26 ) { printf("YES\n"); break ; }
	}
	if( step == 26 ) printf("NO\n"); 
	
	return 0;
}

