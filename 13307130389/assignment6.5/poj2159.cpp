#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std ;

int bucket[27] = {} ;
int bucket_dst[27] = {} ;

char src[100] = {} , dst[100] = {} ;

int main()
{
	int i ;
	scanf("%s\n%s",dst , src );
	for( int i = 0 ; i < strlen(dst) ; i ++ )
		bucket_dst[ dst[i] - 'A' ] ++ ;
	sort( bucket_dst , bucket_dst + 26 ) ;
	for( int i = 0 ; i < strlen(dst) ; i ++ )
		bucket[ src[i] - 'A' ] ++ ;
	sort( bucket , bucket + 26 ) ;
		
	for(i = 0 ; i < 26 ; i ++)
		if( bucket[i] != bucket_dst[i] )
			break ;
	if( i == 26 ) printf("YES\n"); 
	else printf("NO\n"); 
	
	return 0;
}

