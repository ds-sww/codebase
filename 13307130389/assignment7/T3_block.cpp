//°´sqrt(n)·Ö¿é 
//O(n*sqrt(n))
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>

using namespace std ;
int SIZE_OF_BLOCK = 0 ;
int NUM_OF_BLOCK = 0 ;
int sqrtInt(int k )
{
    return (int)(sqrt((double)k)) ;
}
int getBlock( int k )
{
    return k / SIZE_OF_BLOCK ;
}


int block_max[1005] = {} ;
int block[100005] = {} ;
int n ;
int h[100003] = {} ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out_block.txt","w",stdout);
    scanf("%d",&n);
    SIZE_OF_BLOCK = sqrtInt(n) ;
    NUM_OF_BLOCK = n / SIZE_OF_BLOCK ;
    long long ans = 0 ;
    for( int i = 0 ; i < n ; i ++)
    {
         scanf("%d",&h[i]);
         block[i] = getBlock(i);
         if( block_max[ block[i] ] < h[i] )
         {
             block_max[ block[i] ] = h[i] ;
         }
    }
    
    for( int i = 0 ; i < n ; i ++)
    {
         int j = i + 1;
         bool conti = false ;
         for( ; block[j] == block[i] && j < n; j ++)
              if( h[j] >= h[i] ) 
                  { conti = true ; break ;}
         ans += j - i - 1;
         if( j == n ) conti = true ;
         if( conti ) continue ;
         int tempblock = block[j] ;
         for( ; tempblock <= NUM_OF_BLOCK && block_max[tempblock] < h[i] ; tempblock ++ );
         ans += (tempblock - block[j]) * SIZE_OF_BLOCK ;
         if( tempblock > NUM_OF_BLOCK )
         {
             ans -= (NUM_OF_BLOCK + 1)* SIZE_OF_BLOCK - n ;
             continue ;
         }
         j = tempblock*SIZE_OF_BLOCK ;
         for( ; h[i] > h[j] ; j ++)
              ans ++ ;
    }
    cout << ans ;
    
    return 0;
}