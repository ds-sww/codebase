#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std ;

int T ;
int m , n ;
int friends[10005] = {} ;

int main()
{
        cin >> T ;
        int cas = 0 ;
        while( (++cas) <= T )
        {
                scanf("%d %d",&m,&n);
                for( int i = 1; i <= n ; i ++)
                {
                      scanf("%d",&friends[i]) ;
                }
                int ans = 0 ;
                sort( friends + 1 , friends + 1 + n ) ;
                for( int i = n ; i >= 1 ; i -- )
                {
                        if( m <= 0 ) break ;
                        m -= friends[i] ;
                        ans ++ ;
                }
                printf("Scenario #%d:\n",cas) ;
                if( m <= 0 ) printf("%d\n",ans);
                else printf("impossible\n");
                printf("\n");
        }
        return 0;
}

