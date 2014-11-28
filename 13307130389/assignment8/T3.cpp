#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

int n ;
int rightest ;
int a[105] = {} ;
int cnt = 0;

void preorder( int k )
{
        a[++cnt] = k;
        if( (k<<1)<= n ) preorder(k<<1) ;
        if( (k<<1)+1 <= n ) preorder((k<<1)+1) ;
}
int main()
{
        bool firstcase = true ;
        while( scanf("%d",&n) == 1 )
        {
                if( n == 0 ) break ;
                if(!firstcase) printf("\n");
                firstcase = false ;
                cnt = 0 ;
                preorder(1) ;
                for( int i = 1; i <= cnt ; i ++)
                {
                     printf("%d",a[i]) ;
                     if( i < cnt ) printf(" ");
                }
        } 
        return 0;
}

