#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std ;

int c , n ;
int a[100005] = {} ;
int exist[100005] ={} ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( scanf("%d %d",&c,&n) == 2 )
    {
           memset( exist , 0 , sizeof(exist) ) ;
           if( c == 0 && n == 0 ) break ;
           
           for(int i = 1 ; i <= n ; i ++)
                   scanf("%d",&a[i]) ;
           
           for( int i = 1 ; i <= n ; i ++)
           {
                   a[i] = (a[i] + a[i-1])% c;
           }
           for( int i = 1 ; i <= n ; i ++)
           {
                if( a[i] == 0 )
                {
                    for( int j = 1 ; j <= i ; j ++)
                    {
                         printf("%d ",j);
                    }
                    printf("\n");
                    break;
                }
                else
                {
                    if( exist[a[i]] > 0 )
                    {
                        for( int j = exist[a[i]] + 1 ; j <= i ; j ++ )
                             printf("%d ",j);
                        printf("\n");
                        break ;
                    }
                    else
                        exist[a[i]] = i;
                }
           }
    }
    return 0;
}
