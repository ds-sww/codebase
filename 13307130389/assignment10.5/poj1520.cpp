#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std ;

char buffer[100005] = {} ;
char str[10005][105] = {} ;
int index_str[100005] = {} , num_str = 0 ;
int index_num[100005] = {} , num_num = 0 ;
int num[100005] = {} ;

bool isNum( const char c )
{
     if( c >= '0' && c <= '9' ) return true ;
     return false ;
}

void tolower( char *a )
{
     int i = 0 ;
     while( i < strlen(a) )
     {
            if( a[i] >= 'A' && a[i] <= 'Z' )
                a[i] = a[i] - 'A' + 'a' ;
            i ++ ;
     }
}

bool str_cmp_less( const char* a , const char* b )
{
     char ta[105] , tb[105] ;
     strcpy( ta , a ) ; strcpy( tb , b ) ; 
     tolower(ta) ; tolower(tb) ;
     return strcmp( ta , tb ) < 0 ;
}
bool str_cmp_greater( const char* a , const char* b )
{
     char ta[105] , tb[105] ;
     strcpy( ta , a ) ; strcpy( tb , b ) ;
     tolower(ta) ; tolower(tb) ;
     return strcmp( ta , tb ) >= 0 ;
}

void qsort( int top , int bot )
{
     char temp[105] ;
     int left = top , right = bot ;
     strcpy( temp , str[top] ) ;
     while( left < right )
     {
            while( left < right && str_cmp_less( temp , str[right] ) ) right -- ;
            strcpy( str[left] , str[right] );
            while( left < right && str_cmp_greater( temp , str[left])  ) left ++ ;
            strcpy( str[right] , str[left] );
     }
     strcpy( str[right] , temp ) ;
     if( top < right - 1 ) qsort( top , right - 1 );
     if( right + 1 < bot ) qsort( right + 1 , bot );
}

bool init()
{
     memset( index_num , 0 , sizeof(index_num)) ;
     memset( index_str , 0 , sizeof(index_str)) ;
     gets(buffer) ;
     int i = 0 ;
     if( buffer[0] == '.' ) return false ;
     num_str = num_num = 0 ;
     while( i < strlen(buffer) )
     {
            if( (buffer[i] == '-' && isNum( buffer[i+1] )) || isNum(buffer[i]) )
            {
                num_num ++ ;
                index_num[num_num] = num_num + num_str ;
                sscanf(buffer + i , "%d" , &num[num_num] ) ;
            }
            else
            {
                num_str ++ ;
                index_str[num_str] = num_num + num_str ;
                sscanf(buffer + i , "%[^,^.]",str[num_str] ) ;
            }
            while( buffer[i] != ',' && buffer[i] != ' ' && buffer[i] != '.' ) i ++ ;
            if( buffer[i] == '.' ) return true ;
            i ++ ; i ++ ;
     }
     return false ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( init() )
    {
           sort( num + 1 , num + 1 + num_num ) ;
           qsort( 1 , num_str ) ;
           int ti = 1 , tj = 1 ;
           for( int i = 1 ; i <= num_num + num_str ; i ++)
           {
                if( index_num[ti] == i )
                {
                    printf("%d",num[ti]);
                    ti ++ ;
                }
                else if( index_str[tj] == i )
                {
                     printf("%s",str[tj]) ;
                     tj ++ ;
                }
                if( i == num_num + num_str )
                    printf(".\n");
                else
                    printf(", ");
           }
    }
    
    return 0;
}
