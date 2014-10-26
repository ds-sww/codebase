#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

int n , k ;
int queue[1000001] ;
int position[1000001] ;
int array[1000001] ;
//1048576
int head = 0 , tail = 1 ;

int getInt()
{
    char c ;
    int num = 0 ;
    bool fu = false ;
    while( c = getchar() )
    {
           if( c == '-' ) { fu = true ; continue  ; }
           if( c >= '0' && c <= '9' )
               num = num * 10 + c - '0' ;
           else if( c == ' ' || c == '\n' )
               if( !fu ) return num ;
               else return -num ;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d %d\n",&n,&k);
    
    for( int i = 1 ; i <= n ; i ++ )
        //scanf("%d\n",&array[i]);
        array[i] = getInt() ;
    
    int nowpos = 2 ;
    queue[ ++ head ] = array[1] ; position[ head ] = 1 ;
    if( k == 1 ) printf("%d ",queue[tail]);
    while( nowpos <= n )
    {
           while( position[tail] <= nowpos - k && head >= tail) tail ++ ;
           while( array[nowpos] < queue[head] && head >= tail ) head -- ;
           queue[ ++ head] = array[nowpos] ; position[head] = nowpos ;
           if( nowpos >= k ) printf("%d%c",queue[tail],(nowpos==n)?'\n':' ');
           nowpos ++ ;
    }
    //max
    nowpos = 2 ;
    head = 0 ; tail = 1 ;
    queue[ ++ head ] = array[1] ; position[ head ] = 1 ;
    if( k == 1 ) printf("%d ",queue[tail]);
    while( nowpos <= n )
    {
           while( position[tail] <= nowpos - k && head >= tail ) tail ++ ;
           while( array[nowpos] > queue[head] && head >= tail ) head -- ;
           queue[ ++ head] = array[nowpos] ; position[head] = nowpos ;
           if( nowpos >= k ) printf("%d%s",queue[tail],(nowpos==n)?"":" ");
           nowpos ++ ;
    }
    
    return 0;
}
