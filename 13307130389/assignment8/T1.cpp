#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

int sonpre[27][27] = {} ;
int sonpost[27][27] = {} ;
int sonlength[27][27] = {} ;
long long c[27][27] = {} ;
long long total[27] = {} ;
char pre[27]={}, post[27]={} ;
int m ;

void calculate_Cnr()
{
        for( int i = 0 ; i < 27 ; i ++)
                c[i][0] = 1 ;
        for( int i = 1 ; i < 27 ; i ++)
                for( int j = 1 ; j < 27 ; j ++)
                        c[i][j] = c[i-1][j] + c[i-1][j-1] ;
}

void work( int pre_start , int post_start , int len )
{
        if( len == 0 ) return ;
        if( len == 1 )
        {
                total[pre_start] = 1 ;
                return ;
        }
        int nowpre , nowpost ;
        long long temp = 1 ;
        nowpre = pre_start + 1 ; nowpost = post_start ;
        int sonlen = 1 ;
        while( nowpre < pre_start + len )
        {
                while( pre[nowpre] != post[nowpost+sonlen - 1] ) sonlen ++ ;
                sonpre[pre_start][ ++ sonpre[pre_start][0]] = nowpre ;
                sonpost[pre_start][++sonpost[pre_start][0]] = nowpost ;
                sonlength[pre_start][ ++ sonlength[pre_start][0]] = sonlen ;
                nowpre += sonlen ;
                nowpost += sonlen ;
                sonlen = 1;
        }
        for( int i = 1 ; i <= sonpre[pre_start][0] ; i ++ )
        {
                work( sonpre[pre_start][i] , sonpost[pre_start][i] , sonlength[pre_start][i] );
                temp *= total[ sonpre[pre_start][i]] ;
        }
        temp *= c[m][ sonpre[pre_start][0] ] ;
        total[pre_start] = temp ;
}

int main()
{
        calculate_Cnr() ;
        while( scanf("%d %s %s\n",&m,pre,post) == 3 )
        {
                memset( sonpre , 0 , sizeof(sonpre) ) ;
                memset( sonpost , 0 , sizeof(sonpost) ) ;
                memset( sonlength , 0 , sizeof(sonlength) ) ;
                memset( total , 0 , sizeof(total) ) ;
                if( m == 0 ) break ;
                work( 0 , 0 , strlen(pre) ) ;
                cout << total[0] << endl ;
        }
        return 0;
}

