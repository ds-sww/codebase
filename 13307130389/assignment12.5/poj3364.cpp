#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std ;

#define LL __int64

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    LL x , y , c ;
    
    while( cin >> x >> y >> c )
    {
           if( x == 0 )
               break ;
           x -= 7 ; y -= 7 ;
           if( x*y % 2 == 0 )
               cout << x * y / 2 << endl ;
           else
               cout << x * y / 2 + c << endl ;
    }
    
    return 0;
}
