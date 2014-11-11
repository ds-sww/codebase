//单调栈做法
//O(n)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

int n ;
int h[80005] = {} ;
int stack[80005] = {};
int x[80005] = {} ;
int top = 0 ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out_stack.txt","w",stdout);
    
    scanf("%d",&n);
    
    for( int i = 1 ; i <= n ; i ++)
         scanf("%d",&h[i]) ;
    
    stack[ ++ top] = h[1] ;
    x[top] = 1;
    int i = 2 ;
    long long ans = 0 ;
    while( i <= n )
    {
           if( top == 0 || stack[ top ] > h[i] ) 
           {
               stack[++ top] = h[i] ;
               x[ top ] = i ;
           }
           else
           {
               while( top > 0 && stack[top] <= h[i] )
               {
                      ans += i - x[top] - 1 ;
                      top -- ;
               }
               stack[++ top] = h[i] ;
               x[top] = i;
           }
           i ++ ;
    }
    int cnt = 0 ;
    while( top > 0 )
    {
         ans += i - x[top] - 1 ;
         top -- ;
    }
    cout << ans ;
    return 0;
}

   