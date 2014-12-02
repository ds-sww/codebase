#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std ;

const int maxn = 100000 ;

char str[maxn + 10] = {} ;
priority_queue< int , vector<int> , greater<int> > q ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while( scanf("%s",str) == 1)
    {
           if( strcmp( str , "END" ) == 0 ) break ;
           int ascii_length = 0 , huffman_length = 0;
           int tempsize = 1,typecnt = 0 ;
           ascii_length = strlen(str) * 8 ;
           sort( str , str + strlen(str) ) ;
           for( int i = 1 ; i < strlen(str) ; i ++)
           {
                if( str[i] != str[i-1] )
                {
                      q.push( tempsize ) ;
                      tempsize = 1 ;
                      typecnt ++ ;
                }
                else tempsize ++ ;
           }
           q.push( tempsize ) ; typecnt ++ ;
           
           while( !q.empty() && typecnt > 1)
           {
                  int top1 , top2 ;
                  top1 = q.top() ; q.pop() ;
                  if( q.empty() ) break ;
                  top2 = q.top() ; q.pop() ;
                  huffman_length += top1 + top2 ;
                  q.push( top1 + top2 ) ;
           }
           if( typecnt == 1 )
           {
               while( !q.empty() ) q.pop() ;
               huffman_length = strlen(str) ;
           }
           printf("%d %d %.1f\n",ascii_length,huffman_length,((double)ascii_length)/((double)huffman_length) );
    }
    return 0;
}
