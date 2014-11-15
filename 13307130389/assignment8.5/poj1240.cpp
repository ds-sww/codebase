#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

long long ans[27] = {} ;
int sonpre[27][27] = {} ;
int sonpost[27][27] = {} ;
int sonlen[27] = {} ;
char pre[27] = {} , post[27] = {} ;
int m ;
long long c[27][27] = {} ;

void cal_Cnr()
{
     for( int i = 0 ; i <= 26 ; i ++) c[i][0] = 1 ;
     for( int i = 1 ; i <= 26 ; i ++)
          for( int j = 1 ; j <= i ; j ++)
               c[i][j] = c[i-1][j-1] + c[i-1][j] ;
}
     

void work( int start_pre , int start_post , int len )
{
     if( len == 1 )
     {
         ans[start_pre] = 1 ;
     }
     int nextroot = start_pre + 1 , nextlen = 1 , nextpost = start_post ;
     while( nextroot < start_pre + len )
     {
            if( nextpost + nextlen >= start_post + len ) break ;
            if( pre[nextroot] == post[nextpost + nextlen - 1] )
            {
                sonpre[start_pre][0] ++ ;
                sonpost[start_pre][0] ++ ;
                sonpre[start_pre][ sonpre[start_pre][0] ] = nextroot ;
                sonpost[start_pre][ sonpost[start_pre][0]] = nextpost ;
                sonlen[nextroot] = nextlen ;
                nextpost = nextpost + nextlen ;
                nextroot = nextroot + nextlen ;
                nextlen = 1 ;
            }
            else nextlen ++ ;
     }
     long long nowans = 1 ;
     for( int i = 1 ; i <= sonpre[start_pre][0] ; i ++)
          work( sonpre[start_pre][i] , sonpost[start_pre][i] , sonlen[ sonpre[start_pre][i] ] );
     for( int i = 1 ; i <= sonpre[start_pre][0] ; i ++)
          nowans *= ans[ sonpre[start_pre][i] ] ;
     ans[start_pre] = nowans * c[m][ sonpre[start_pre][0] ];
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cal_Cnr() ;
    
    while( scanf("%d %s %s\n",&m,pre,post) == 3 )
    {
           if( m == 0 ) break ;
           memset( sonpre , 0 , sizeof(sonpre) ) ;
           memset( sonlen , 0 , sizeof(sonlen)) ;
           memset( sonpost, 0 , sizeof(sonpost) );
           memset( ans , 0 , sizeof(ans) ) ;
           work( 0 , 0 , strlen(pre) ) ;
           cout << ans[0] << endl ;
    }
    return 0 ;
}
