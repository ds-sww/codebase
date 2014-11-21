#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std ;

int num[6000] = {} , i ;

long long pow( long long x , long long k )
{
     if( k == 0 ) return 1 ;
     if( k == 1 ) return x ;
     long long t = pow(x,k/2) ;
     if( k % 2 )
         return t*t*x ;
     else
         return t*t ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    long long x , y , z , w ;
    i = 0 ;
    for( x = 0 ; x < 32 ; x ++)
         for( y = 0 ; pow(3,y) <= 2000000000/pow(2,x) ; y ++)
              for( z = 0 ; pow(5,z) <= 2000000000/pow(2,x)/pow(3,y) ; z ++)
                   for( w = 0 ; pow(7,w) <= 2000000000/pow(2,x)/pow(3,y)/pow(5,z); w ++)
                        num[++ i] = pow(2,x)*pow(3,y)*pow(5,z)*pow(7,w) ;
    sort( num + 1 , num + i + 1 ); 
    
    int query ;
    while( scanf("%d",&query) == 1 )
    {
           // zhe ge di fang keng si ying yu zha!!!
           if( query == 0 ) break ;
           if( query % 10 == 1 && query % 100 != 11 )
                printf("The %dst humble number is %d.\n",query,num[query]);
           else if( query % 10 == 2 && query % 100 != 12 )
                printf("The %dnd humble number is %d.\n",query,num[query]);
           else if( query % 10 == 3 && query % 100 != 13 )
                printf("The %drd humble number is %d.\n",query,num[query]);
           else 
                printf("The %dth humble number is %d.\n",query,num[query]);
    }
    
    return 0;
}
