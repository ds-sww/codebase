#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std ;

const int maxn = 100000 ;

int cnt_str = 0 ;
int cnt_num = 0 ;
int index_str[maxn + 5] ={} ;
int index_num[maxn + 5] ={} ;
char str[maxn + 5][105] = {};
int num[maxn + 5] = {} ;

char buff[100005] = {} ;

bool cmpmin( const char *a , const char *b )
{
        char bufa[105] = {} , bufb[105] = {} ;
        int lena = strlen(a) , lenb = strlen(b) ;
        for( int p = 0 ; p < lena ; p ++)
        	if( a[p] >= 'A' && a[p] <= 'Z' )
        		bufa[p] = a[p] - 'A' + 'a' ;
        	else bufa[p] = a[p] ;
        for( int j = 0 ; j < lenb ; j ++)
        	if( b[j] >= 'A' && b[j] <= 'Z' )
        		bufb[j] = b[j] - 'A' + 'a' ;
        	else bufb[j] = b[j];
	return strcmp( bufa , bufb ) < 0 ;
}
bool cmpmax( const char *a , const char *b )
{
        char bufa[105] = {} , bufb[105] = {} ;
        int lena = strlen(a) , lenb = strlen(b) ;
        for( int p = 0 ; p < lena ; p ++)
        	if( a[p] >= 'A' && a[p] <= 'Z' )
        		bufa[p] = a[p] - 'A' + 'a' ;
        	else bufa[p] = a[p] ;
        for( int j = 0 ; j < lenb ; j ++)
        	if( b[j] >= 'A' && b[j] <= 'Z' )
        		bufb[j] = b[j] - 'A' + 'a' ;
        	else bufb[j] = b[j];
	return strcmp( bufa , bufb ) >= 0 ;
}

void qsort( int top , int bot )
{
	char temp[105] ;
	strcpy( temp , str[top] ) ;
	int left = top , right = bot ;
	while( left < right )
	{
		while( left < right && cmpmax( str[right], temp ) ) right -- ;
		strcpy( str[left] , str[right] ) ;
		while( left < right && cmpmin( str[left] , temp ) ) left ++ ;
		strcpy( str[right] , str[left] ) ;
	}
	strcpy( str[right] , temp ) ;
	if( top < right - 1 ) qsort( top , right - 1 ) ;
	if( right + 1 < bot ) qsort( right + 1 , bot ) ;
}

bool isNum( char c )
{
	if( c >= '0' && c <= '9' )
		return true ;
	else return false ;
}

void init()
{
     int i = 0 ;
     int len = strlen(buff) ;
     int tempn = 0 ;
     char tempc[1005] = {} ;
     int cnt = 0 ;
     while( i < len )
     {
     		if( isNum(buff[i]) || (buff[i] == '-' && isNum(buff[i+1])))
     		{
     			sscanf(buff+i, "%d" , &tempn) ;
     			cnt ++ ;
     			index_num[++cnt_num] = cnt ;
     			num[cnt_num] = tempn ;
     		}
     		else
     		{
     			sscanf(buff+i, "%[^,^.]" , tempc) ;
     			cnt ++ ;
     			index_str[++cnt_str] = cnt ;
     			strcpy( str[cnt_str] ,tempc ) ;
     		}
     		while( buff[i] != ',' && buff[i] != '.' ) i ++ ;
     		if( buff[i] == '.') break ;
     		i += 2 ;
     }
}

int main()
{
	ios::sync_with_stdio(false) ;
	
	while(1)
	{
		cnt_str = cnt_num = 0 ;
		memset(str , 0 ,sizeof(str)) ;
		memset(num , 0 ,sizeof(num)) ;
		memset(index_str,0,sizeof(index_str)) ;
		memset(index_num,0,sizeof(index_num)) ;
		gets(buff) ;
		if( buff[0] == '.' ) break ;
		init() ;
		
		sort( num + 1 , num + 1 + cnt_num ) ;
		qsort( 1 , cnt_str) ;
		
		int tagstr = 1 , tagnum = 1 ;
		for( int i = 1 ; i <= cnt_str + cnt_num ; i ++)
		{
			if( index_str[tagstr] == i )
				printf("%s",str[tagstr++]) ;
		        else
		        	printf("%d",num[tagnum++]) ;
		        if( i < cnt_str + cnt_num )
		        	printf(", ");
		        else
		        	printf(".\n");
		}
	}
	
	return 0;
}
