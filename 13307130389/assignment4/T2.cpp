#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

#define LL __int64

using namespace std ;

int n ;
LL stack[100001][2] = {} ;
LL array[100001] = {} ;
int top = -1 ;
LL ans = 0 ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( scanf("%d",&n) )
    {
           if( n == 0 ) break ;
           top = -1 ; ans = 0 ;
           for( int i = 1 ; i <= n ; i ++ )
                scanf("%I64d",&array[i]);
           
           for( int i = 1 ; i <= n ; i ++ )
           {
                if( top == -1 || array[i] > stack[top][0] )
                {
                    stack[++top][0] = array[i] ;
                    stack[top][1] = 1 ;
                }
                else
                {
                    LL temp = 0 ;
                    while( array[i] <= stack[top][0] && top >= 0)
                    {
                           ans = max( ans , stack[top][0]*(stack[top][1]+temp) );
                           temp += stack[top][1] ;
                           top -- ;
                    }
                    stack[++top][0] = array[i] ;
                    stack[top][1] = temp + 1 ;
                }
           }
           LL temp = 0 ;
           while(top >= 0)
           {
                  ans = max( ans , stack[top][0]*(stack[top][1]+temp) );
                  temp += stack[top][1] ;
                  top -- ;
           }
           printf("%I64d\n",ans);
    }
    
    return 0;
}
