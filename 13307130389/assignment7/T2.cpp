#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std ;

int n , m ;
string str[20005] ;
int ans[20005] = {} ;

int main()
{
        while( scanf("%d %d\n",&n,&m) == 2 )
        {
                if( n == 0 && m == 0 ) break ;
                
                memset( ans , 0 , sizeof(ans)) ;
                for( int i = 1 ; i <= n ; i ++)
                        cin >> str[i] ;
                
                sort( str + 1 , str + 1 + n ) ;
                
                int cnt = 1 ;
                for( int i = 1  ; i < n ; i ++)
                {
                        if( str[i] == str[i + 1]) cnt ++ ;
                        else
                        {
                                ans[ cnt ] ++ ;
                                cnt = 1 ;
                        }
                }
                ans[ cnt ] ++ ;
                
                for( int i = 1 ; i <= n ; i ++)
                        printf("%d\n",ans[i]) ;
        }
        return 0;
}

